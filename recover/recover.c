#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Ensure 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file and make sure it worked
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create buffer for reading
    BYTE buffer[BLOCK_SIZE];
    int count = 0;
    char filename[8];
    FILE *img = NULL;

    // read 512 byte into memory
    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        // if start of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first jpeg
            if (count == 0)
            {
                //creat new jpeg file
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                img = malloc(BLOCK_SIZE);
                count++;
            }
            else
            {
                fclose(img);
            }
        }
        else if (img != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }

}
