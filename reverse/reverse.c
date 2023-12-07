#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER hin;
    fread(&hin, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(hin) == 1)
    {
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&hin, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(hin);
    printf("%i\n", block_size);

    // Write reversed audio to file
    // TODO #8
    char *buffer;
    fread(&buffer, sizeof(block_size), 1, input);
    

}

int check_format(WAVHEADER header)
{
    // TODO #4

    if (header.format[0] == 'W')
    {
        if (header.format[1] == 'A')
        {
            if (header.format[2] == 'V')
            {
                if (header.format[3] == 'E')
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
}
