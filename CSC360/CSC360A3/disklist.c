#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "reader.h"


int main(int argc, char* argv[])
{
    // Reading file and ensuring it exists
    if (argc == 1)
    {
        printf("error, expects file name as argument\n");
        exit(1);
    }

    FILE* file = fopen(argv[1], "rb");
    if(file == NULL)
    {
        printf("error, file %s could not be opened\n", argv[1]);
        exit(1);
    }

    Boot_info info = readBootInfo(file);

    int directory_start = info.num_FAT * info.FAT_sectors + 1;

    int len = 10;
    // basic queue for traversing directories
    uint16_t* queue = (uint16_t*) calloc(len, sizeof(uint16_t));
    uint8_t** name = (uint8_t**) malloc(sizeof(uint8_t*) * len);
    int pointer = 0;

    //since root is multiple sectors long, It's not done in the read_directory_contents file
    printf("root\n==================\n");
    fseek(file, directory_start * info.sector_size, SEEK_SET);
    for(int i = 0; i < info.max_root_entries; i++)
    {
        uint8_t reader[32];
        fread(reader, sizeof(uint8_t), 32, file);

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
            queue[pointer] = address;
            name[pointer] = (uint8_t*) malloc(sizeof(uint8_t) * 9);
            strncpy(name[pointer], reader, 8);
            pointer++;
            if(pointer == len)
            {
                len *= 2;
                queue = realloc(queue, sizeof(uint16_t) * len);
            }
            continue;
        }

        // At this point, entry must contain a file
        print_file_info(reader);
    }
    printf("\n");// makes it look better

    // printing contents of sub-directories
    for(int i = 0; i < pointer; i++)
    {
        // printf("%d\n", len);
        int err = display_directory_contents(file, queue, name, i, &pointer, &len);
        if(err != 0)
        {
            printf("invalid entry in display_directory_contents\n");
            exit(1);
        }
        free(name[i]);
    }


    free(queue);
    free(name);
    fclose(file);
}