#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "reader.h"


int main(int argc,char* argv[])
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

    // calculate free space
    int free_space = 0;
    for(int i = 0; i <= 2848; i++)
    {
        if(getFATEntry(file, i) == 0x000)
            free_space++;
    }
    free_space *= info.sector_size;

    // get number of files on disk
    int num_files = 0;
    int max_directories = readInt(file, 0, 17);
    int directory_start = info.num_FAT * info.FAT_sectors + 1;
    for(int i = 0; i < info.max_root_entries / 16; i++)
    {
        num_files = read_directory_recursive(file, directory_start - 31);
    }
    
    // Printing info
    printf("OS Name: %s\n", info.name);
    printf("Label of the disk: %s\n", info.volume_label);
    printf("Total size of the disk: %d bytes\n", info.num_sectors * info.sector_size);
    printf("Free size of the disk:  %d bytes\n", free_space);
    printf("==============\n");
    printf("Number of files on disk: %d\n", num_files);
    printf("that number does not include directories\n");
    printf("==============\n");
    printf("Number of FAT copies: %d\n", info.num_FAT);
    printf("Sectors per FAT: %d\n", info.FAT_sectors);


    fclose(file);
}