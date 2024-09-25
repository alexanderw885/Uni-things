#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/sendfile.h>

#include "reader.h"


int main(int argc, char* argv[])
{
// Reading file and ensuring it exists
    if (argc < 3)
    {
        printf("error, expects disk image and file name as argument\n");
        exit(1);
    }
    FILE* file = fopen(argv[1], "rb+");
    if(file == NULL)
    {
        printf("error, file %s could not be opened\n", argv[1]);
        exit(1);
    }

    Boot_info info = readBootInfo(file);

    // read name of file to be read, ensure correctness
    int num_fields = 0;
    int name_index = 0;
    char** filename = read_filename(argv[2], &num_fields, &name_index);


    //search directory returns address. use to find first sub-directory in root, then to keep going down until you find file
    int curr_field = 0;
    int  addr = 0;
    int size = 0;
    if(name_index != 0)
    {
        for(int i = 0; i < info.max_root_entries / 16; i++)
        {
            addr = search_directory(file, info.FAT_sectors * info.num_FAT + 1 + i, filename[curr_field], "   ", &size);
            if(addr != 0)
            {
                curr_field++;
                break;
            }
        }
        if(addr == 0)
        {
            printf("Could not find subdirectory %s\n", filename[curr_field]);
            exit(1);
        }
    }
    //search down root directories until at directory to place file
    while(curr_field < name_index)
    {
        int next_addr = search_directory(file, addr + 31, filename[curr_field], "   ", &size);
        if(next_addr > 0)
        {
            addr = next_addr;
            curr_field++;
        }
        else
        {
            printf("did not find subdirectory %s\n", filename[curr_field]);
            exit(1);
        }
    }
    // Ensure file doesn't already exist in the directory
    if(search_directory(file, addr+31, filename[curr_field], filename[curr_field+1], &size) > 0)
    {
        printf("filename %s.%3.3s already exists in this directory\n", filename[curr_field], filename[curr_field+1]);
        exit(1);
    }

    // Tokenize input string to get filename without any spaces and with hopefully less pain
    // Also to keep input capitalization
    char* token;
    char delim = '/';
    char copy_name[20];;

    token = strtok(argv[2], &delim);
    while(token != NULL)
    {
        strncpy(copy_name, token, 20);
        token = strtok(NULL, &delim);
    }
    
    FILE* copy = fopen(copy_name, "rb");
    if(copy == NULL)
    {
        printf("file %s does not exist\n", copy_name);
        exit(1);
    }    


    // Find first empty entry in directory
    char* reader;
    fseek(file, (addr + 31) * 512, SEEK_SET);
    for(int i = 0; i < 16; i++)
    {
        reader = readNextString(file, 33);
    }


    // Find location for directory enty
    uint8_t writer[33];
    int found = 0;
    // Root directory case
    if(addr == 0)
    {
        fseek(file, (info.FAT_sectors * info.num_FAT + 1) * 512, SEEK_SET);
        for(int i = 0; i < info.max_root_entries; i++)
        {
            fread(writer, sizeof(uint8_t), 32, file);
            if(writer[0] == 0x00 || writer[0] == 0xe5)
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            printf("no space in root directory\n");
            exit(1);
        }
    }
    // Sub directory case
    else{
        fseek(file, (addr + 31) * 512, SEEK_SET);
        for(int i = 0;i < 16; i++)
        {
            fread(writer, sizeof(uint8_t), 33, file);
            if(writer[0] == 0x00 || writer[0] == 0xe5)
            {
                found = 1;
                break;
            }
        }
        if(!found)
        {
            printf("no space in sub directory\n");
            exit(1);
        }
    }
    int dir_location = ftell(file) - 32;

    // Filling directory entry
    strncpy(writer, filename[name_index], 8);
    strncpy(&writer[8], filename[name_index+1],  3);

    fseek(copy, 0, SEEK_END);
    uint32_t copy_size = ftell(copy);
    writer[28] = (copy_size) % 0x100;
    writer[29] = (copy_size >> 8) % 0x100;
    writer[30] = (copy_size >> 16) % 0x100;
    writer[31] = (copy_size >> 24) % 0x100;
    // int size = details[28] + details[29] * 0x0100 + (details[30] + details[31] * 0x0100) * 0x00010000;
    /*
    int size 
    */


    // Get location to store in FAT table
    int FATval = -1;
    for(int i = 2; i < info.FAT_sectors * 512 * 3 / 2; i++)
    {

        FATval = getFATEntry(file, i);
        if(FATval == 0)
        {
            addr = i;
            break;
        }
    }

    writer[26] = addr % 0x100;
    writer[27] = (addr >> 8) % 0x100;

    // Push writer info into directory entry
    fseek(file, dir_location, SEEK_SET);
    fwrite(writer, sizeof(uint8_t), 32, file);

    // Write into storage, if need be find next free sector, update fat entry
    fseek(copy, 0, SEEK_SET);
    while(1) 
    {

        int to_copy;
        if(copy_size >= 512)
        {
            to_copy = 512;
            copy_size -= 512;
        }
        else
        {
            to_copy = copy_size;
            copy_size = 0;
        }
        fseek(file, (addr + 31) * 512, SEEK_SET);
        /*
        printf("\n");
        printf("write head: %lx\n", ftell(file));
        printf("read head: %lx\n", ftell(copy));
        printf("copying now: %d\n", to_copy);
        printf("size remaining: %d\n", copy_size);
        printf("address: %x\n", addr);
        */
        uint8_t writer[512];
        fread(writer, sizeof(uint8_t), to_copy, copy);
        fwrite(writer, sizeof(uint8_t), to_copy, file);

        if(copy_size <= 0)
        {
            writeFATEntry(file, addr, 0xfff);
            break;
        }
        int FATval = -1;
        for(int i = addr + 1; i < info.FAT_sectors * 512 * 3 / 2; i++)
        {
            FATval = getFATEntry(file, i);
            if(FATval == 0)
            {
                // printf("next address: %x\n", i);
                FATval = i;
                break;
            }
        }
        writeFATEntry(file, addr, FATval);
        addr = FATval;
    }

    fclose(file);
    fclose(copy);
    for(int i = 0; i <= num_fields; i++)
        free (filename[i]);
    free(filename);
}