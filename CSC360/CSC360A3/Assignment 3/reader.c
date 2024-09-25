#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/sendfile.h>

#include "reader.h"

int sector_size = 512; // default value, gets set in ReadBootInfo

// Returns pointer to string of specified length, at specified place in the file
// This pointer must be freed once no longer needed
uint8_t* readString(FILE* file, int sector,int start_byte, int size)
{
    uint8_t* value = (uint8_t*) malloc(sizeof(uint8_t) * (size + 1));
    fseek(file, (sector_size * sector) + start_byte, SEEK_SET);
    fread(value, sizeof(uint8_t), size, file);
    return value;
}

// Returns pointer to string of specified length at current file pointer location
// This pointer must be freed once no longer needed
uint8_t* readNextString(FILE* file, int size)
{
    uint8_t* value = (uint8_t*) malloc(sizeof(uint8_t) * (size + 1));
    fread(value, sizeof(uint8_t), size + 1, file);
    return value;
}


// Reads 2 byte integer at specified location in file
// FAT-12 is little-endian, this function accounts for that and converts to big-endian
uint16_t readInt(FILE* file, int sector, int start_byte)
{
    uint8_t num[3];
    fseek(file, (sector_size * sector) + start_byte, SEEK_SET);
    fgets(num, 3, file);

    uint16_t retval = num[1] * 0x0100 + num[0];
    return retval;
}

// Returns next 2-byte integer at current file pointer location
// FAT-12 is little-endian, this function accounts for that and converts to big-endian
uint16_t readNextInt(FILE* file)
{
    uint8_t num[3];
    fgets(num, 3, file);

    uint16_t retval = num[1] * 0x0100 + num[0];
    return retval;
}

// Returns single byte from file at specified location
uint8_t readByte(FILE* file, int sector, int start)
{
    uint8_t byte[2];
    fseek(file, (sector_size * sector) + start, SEEK_SET);
    fgets(byte, 2, file);
    return byte[0];
}

// Returns byte at current file pointer
uint8_t readNextByte(FILE* file)
{
    uint8_t byte[2];
    fgets(byte, 2, file);
    return byte[0];
}

// Stores all relevant info from boot sector into Boot_info struct
// Also sets sector_size variable, which is used throughout reader.c
Boot_info readBootInfo(FILE* file)
{
    Boot_info info;
    fseek(file, 3, SEEK_SET);

    fgets(info.name, 9, file);
    info.sector_size = readNextInt(file);
    info.cluster_size = readNextByte(file);
    info.reserved_sectors = readNextInt(file);
    info.num_FAT = readNextByte(file);
    info.max_root_entries = readNextInt(file);
    info.num_sectors = readNextInt(file);

    info.FAT_sectors = readInt(file, 0, 22);

    // reading volume label
    fseek(file, (info.num_FAT * info.FAT_sectors + 1) * 512, SEEK_SET);

    // printf("%x\n\n", (info.num_FAT * info.FAT_sectors + 1) * 512);

    uint8_t* reader = (uint8_t*) malloc(sizeof(uint8_t) * 33);
    
    for(int i = 0; i < info.max_root_entries; i++)
    {
        fgets(reader, 33, file);
        // printf("%02x%02x %02x%02x  %02x\n", reader[0], reader[1], reader[2], reader[3], reader[11]);
        if(reader[11] & 0x08 && reader[11] != 0x0f) break;
    }

    strncpy(info.volume_label, reader, 11);
    info.volume_label[11] = '\0';

    sector_size = info.sector_size;

    free(reader);
    // exit(0);
    return info;
}

// Returns 12-bit value from FAT table at the specified index.
// Returned as uint16_t as there is no 12-bit type
// FAT-12 is little-endian this function accounts for that and converts to big-endian
uint16_t getFATEntry(FILE* file, int entry_location)
{
    uint16_t value = 0;

    // convert entry_location into byte location in table
    int location = (3 * entry_location) / 2;

    uint8_t reader[3];
    fseek(file, (sector_size * 1) + location, SEEK_SET);
    fgets(reader, 3, file);

    // Convert to big-endian
    if(entry_location % 2 == 0)
    {
        value = reader[0];
        value += reader[1] % 0x010 * 0x100;
    }
    else
    {
        value = reader[0] / 0x10;
        value += reader[1] * 0x10;
    }

    return value;
}

// Used by diskput
// Writes value into FAT table at specified location
// Writes to all FAT tables
void writeFATEntry(FILE* file, uint16_t addr, uint16_t value)
{

// convert entry_location into byte location in table
    int location = (3 * addr) / 2;

    uint8_t writer[3];
    fseek(file, (sector_size * 1) + location, SEEK_SET);
    fgets(writer, 3, file);

    if(addr % 2 == 0)
    {
        writer[0] = value % 0x100;
        writer[1] %= 0x10;
        writer[1] |= (value >> 8) % 0x10;
    }
    else
    {
        writer[1] = value % 0x100;
        writer[0] %= 0x10;
        writer[0] |= (value >> 8) % 0x10;
    }
    fseek(file, (sector_size * 1) + location, SEEK_SET);
    fwrite(writer, sizeof(uint8_t), 2, file);

}

// Used by diskinfo
// Recursively searches through all directories and sub-directories, and returns the number if files they contain
// This count does not include the sub-directoies themselves
int read_directory_recursive(FILE* file, uint16_t logic_address)
{
    //convert logical address into physical address
    int num_entries = 0;
    uint16_t address = logic_address + 31;

    // go through all entries in the sector
    // if the entry is a directory, recursively call function to search it
    // increment num_entries if entry points to file
    for(int i = 0; i < 16; i++)
    {
        uint8_t* reader = readString(file, address, i * 32, 32);

        // check if entry is filled. If not, no need to read it
        // Also checks if entry starts with ".". This is not allowed in FAT12,
        // meaning entry points to current/parent directory
        if(reader[0] == 0x00 || reader[0] == 0xe5 || reader[0] == 0x2e)
        {
            free(reader);
            continue;
        }

        uint16_t address = reader[27] * 0x0100 + reader[26];
        // check if first logical cluster exists. if not, ignore
        if(address < 2)
        {
            free(reader);
            continue;
        }

        // check if entry is subdirectory. if so, read contents
        if(reader[11] & 0x10)
        {
            num_entries += read_directory_recursive(file, address);

            free(reader);
            continue;
        }

        num_entries++;
        free(reader);
    }
    return num_entries;
}

// This function takes in 32 bytes, and prints out the file details in accordance to FAT-12 directory specifications
// Note this function expects a 33 byte array
void print_file_info(uint8_t details[])
{
    // Check if directory of file
    if(details[11] & 0x10)
        printf("D ");
    else
        printf("F ");

    int size = details[28] + details[29] * 0x0100 + (details[30] + details[31] * 0x0100) * 0x00010000;
    printf("%10d ", size);

    //print name and extension
    char name[9];
    strncpy(name, details, 8);
    name[8] = '\0';
    printf("%8s ", name);
    char ext[4];
    strncpy(ext, &details[8], 3);
    ext[3] = '\0';
    printf("%s         ", ext);

    uint16_t date = details[16] + 0x0100 * details[17];
    int day = date & 0x1f;
    int month = (date & 0x1e0) >> 5;
    int year =((date & 0xfe00) >> 9) + 1980;
    printf("%d-%02d-%02d ", year, month, day);

    uint16_t time = details[14] + 0x0100 * details[15];
    int hours = (time & 0xf800) >> 11;
    int minutes = (time & 0x7e0) >> 5;
    int seconds = (time & 0x1f) * 2;

    printf("%02d:%02d:%02d", hours, minutes, seconds);

    printf("\n");
}

// This function is used by disklist.c
// Takes address of a directory sector, the name of the directory, and a queue of directories to be searched
// Adds all sub-directories to the queue and increments pointer and len appropriately
// Sends file information to print_file_info
int display_directory_contents(FILE* file, uint16_t* queue, uint8_t** name, int curr_index, int* pointer, int* len)
{
    printf("%s\n==================\n", name[curr_index]);

    fseek(file, (queue[curr_index] + 31) * sector_size, SEEK_SET);
    for(int i = 0; i < 16; i++)
    {
        uint8_t reader[33];
        fgets(reader, 33, file);
        if(reader == NULL)
            return -1;

        // check if entry is filled. If not, no need to read it
        // Also checks if entry starts with ".". This is not allowed in FAT12,
        // meaning entry points to current/parent directory
        if(reader[0] == 0x00 || reader[0] == 0xe5 || reader[0] == 0x2e)
        {
            continue;
        }

        uint16_t address = reader[27] * 0x0100 + reader[26];
        // check if first logical cluster exists. if not, ignore
        if(address < 2)
        {
            continue;
        }
        // check if entry is subdirectory. if so, print info and put address in queue
        if(reader[11] & 0x10)
        {
            print_file_info(reader);
            queue[*pointer] = address;
            name[*pointer] = (uint8_t*) malloc(sizeof(uint8_t) * 9);
            strncpy(name[*pointer], reader, 8);
            (*pointer)++;
            if(*pointer == *len)
            {
                (*len) *= 2;
                queue = realloc(queue, sizeof(uint16_t) * *len);
            }
            continue;
        }

        // At this point, entry must contain a file
        print_file_info(reader);
    }
    printf("\n");
    return 0;
}

uint16_t search_directory(FILE* file, int sector, char* filename, char* extension, uint32_t* size)
{
    uint16_t addr = 0;
    fseek(file, sector * sector_size, SEEK_SET);

    for(int i = 0; i < 16; i++)
    {
        uint8_t reader[33];
        fgets(reader, 33, file);
        if(reader == NULL)
            return -1;

        // check if entry is filled. If not, no need to read it
        // Also checks if entry starts with ".". This is not allowed in FAT12,
        // meaning entry points to current/parent directory
        if(reader[0] == 0x00 || reader[0] == 0xe5 || reader[0] == 0x2e)
        {
            continue;
        }

        uint16_t address = reader[27] * 0x0100 + reader[26];
        // check if first logical cluster exists. if not, ignore
        if(address < 2)
        {
            continue;
        }



        // Compares entry name to search name, if successful compares extensions
        // If they don't match, ignore
        if(strncmp(filename, reader, 8) != 0)
        {
            continue;
        }
        if(strncmp(extension, &reader[8], 9));
        {
            *size = reader[28] + reader[29] * 0x0100 + (reader[30] + reader[31] * 0x0100) * 0x00010000;

            addr = address;
            break;
        }
    }

   return addr;
}

char** read_filename(char* input, int *num_fields_out, int* filename_index)
{
    *filename_index = -1; // used to check if extension was added
    int num_fields = 5;
    char** fields = (char**) malloc(sizeof(char*) * num_fields);

    int curr_field = 0; // To determine index in num_fields
    int string_index = 0; // To determine index in num_fields[i]

    int i = 0;
    // Check first char, if it is '.', name is invalid
    if(input[i] == '.')
    {
        printf("invalid file name, cannot start with '.'\n");
        exit(1);
    }

    fields[curr_field] = (char*) malloc(sizeof(char) * 9);
    strncpy(fields[curr_field], "        ", 9);
    // transfer input into separate fields, one for each directory, filename, and extension
    while( input[i] != '\0')
    {
        // if input character signifies new field
        if(input[i] == '/')
        {
            string_index = 0;
            curr_field++;
            if(curr_field == num_fields)
            {
                num_fields++;
                fields = (char**) realloc(fields, sizeof(char*) * num_fields);
            }
            fields[curr_field] = (char*) malloc(sizeof(char) * 9);
            strncpy(fields[curr_field], "        ", 9);
            i++;
            continue;
        }

        // if input character signifies extension
        if(input[i] == '.')
        {
            *filename_index = curr_field;
            string_index = 0;
            curr_field++;
            if(curr_field == num_fields)
            {
                num_fields++;
                fields = (char**) realloc(fields, sizeof(char*) * num_fields);
            }
            fields[curr_field] = (char*) malloc(sizeof(char) * 9);
            strncpy(fields[curr_field], "        ", 9);
            i++;
            continue;
        }

        // If filename is longer than 8 characters, too long for FAT12 format
        if(string_index == 8)
        {
            fields[curr_field][string_index] = '\0';
            printf("name too long, cannot be greater than 8 characters\n");
            printf("error on string %s\n", fields[curr_field]);
            exit(1);
        }
        
        fields[curr_field][string_index] = toupper(input[i]);
        i++;
        string_index++;
    }
    // if there was no '.', add a blank extension
    if(*filename_index == -1)
    {
        *filename_index = curr_field;
        curr_field++;
        if(curr_field == num_fields)
        {
            num_fields++;
            fields = (char**) realloc(fields, sizeof(char*) * num_fields);
        }
        fields[curr_field] = (char*) malloc(sizeof(char) * 4);
        strncpy(fields[curr_field], "   ", 9);
;
    }

    *num_fields_out = curr_field;
    return fields;
}
