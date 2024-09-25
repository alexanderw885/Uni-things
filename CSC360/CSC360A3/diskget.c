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

    FILE* file = fopen(argv[1], "rb");
    if(file == NULL)
    {
        printf("error, file %s could not be opened\n", argv[1]);
        exit(1);
    }

    Boot_info info = readBootInfo(file);

    // read name of file to be read, ensure correctness
    if(strlen(argv[2]) > 12)
    {
        printf("invalid filename. Filename can only be 8 characters long, and have a 3 character extension\n");
        exit(1);
    }
    char name_in[13];
    strncpy(name_in, argv[2], strlen(argv[2]));

    if(name_in[0] == '.')
    {
        printf("invalid filename, cannot start with '.'\n");
        exit(1);
    }

    int name_len = strlen(argv[2]);

    // initialize name to all spaces, makes it easier to work with
    char name[9];
    char extension[4];

    strncpy(name, "        ", 9);
    
    int i;
    for(i = 0; i < 8 && i < strlen(name_in); i++)
    {
        if(name_in[i] == '.' || name_in[i] == '\0')
            break;
        name[i] = toupper(name_in[i]);
    }

    if(name_in[i] == '.')
    {
        i++;
        extension[0] = toupper(name_in[i + 0]);
        extension[1] = toupper(name_in[i + 1]);
        extension[2] = toupper(name_in[i + 2]);
        extension[3] = '\0';
    }


    // search for file in root directory
    uint16_t addr = 0;
    int size;
    for(int i = 0; i < info.max_root_entries / 16; i++)
    {
        if(addr != 0)
            break;
        addr = search_directory(file, info.num_FAT * info.FAT_sectors + 1 + i, name, extension, &size);
    }

    if(addr == 0)
    {
        printf("Could not find file %s in root directory\n", name_in);
        exit(1);
    }

    // delete file on disk if it already exist, and create new file to write in
    if(access(name_in, F_OK) == 0)
    {
        remove(name_in);
    }
    FILE* out = fopen(name_in, "ab");
    
    while(addr >= 2 && addr != 0xfff)
    {

        uint8_t* read_out = readString(file, addr + 31, 0, info.sector_size);

        int read_size;
        if(size > info.sector_size)
            fwrite(read_out, sizeof(uint8_t), info.sector_size, out);
        else
        {
            fwrite(read_out, sizeof(uint8_t), size, out);  
        }
        size -= info.sector_size;
        addr = getFATEntry(file, addr);

        free(read_out);
    }

    fclose(file);
    fclose(out);
}

