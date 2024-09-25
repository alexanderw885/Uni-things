#ifndef __READER_H_
#define __READER_H_

#include <stdint.h>

typedef struct Boot_info Boot_info;

struct Boot_info
{
    char name[9];
    int sector_size;
    int cluster_size;
    int reserved_sectors;
    int num_FAT;
    int max_root_entries;
    int num_sectors;
    int FAT_sectors;
    char volume_label[12];
};
// Reads basic information from boot sector
Boot_info readBootInfo(FILE* file);

// Reads info in as primitive types, used in all functions
uint8_t* readString(FILE* file, int sector, int start, int size);
uint8_t* readNextString(FILE* file, int size);
uint16_t readInt(FILE* file, int sector, int start_byte);
uint16_t readNextInt(FILE* file);
uint8_t readByte(FILE* file, int sector, int start);
uint8_t readNextByte(FILE* file);

uint16_t getFATEntry(FILE* file, int entry_location);
void writeFATEntry(FILE* file, uint16_t addr, uint16_t value);


// All read directories, but they all return different information
int read_directory_recursive(FILE* file, uint16_t address);
int display_directory_contents(FILE* file, uint16_t* queue, uint8_t** name, int curr_index, int* pointer, int* len);
uint16_t search_directory(FILE* file, int sector, char* filename, char* extension, uint32_t *size);

void print_file_info(uint8_t details[]);

// Used by diskget and diskput to read filenames from stdin
char** read_filename(char* input, int *num_fields_out, int* filename_index);

#endif