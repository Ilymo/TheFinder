#include <stdio.h>
#include <stdlib.h>

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
    int BLOCK_SIZE = 512;
    int buffer[BLOCK_SIZE];
    int n = 0;
    char *filename;

    while (fread(buffer, 1, BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff)
        {
            if (buffer[1] == 0xd8)
            {
                if (buffer[2] == 0xff)
                {
                    if ((buffer[3] & 0xf0) == 0xe0)
                    {
                        sprintf(filename, "%03i.jpg", n);
                        filename = malloc(BLOCK_SIZE);
                        FILE *img = fopen(filename, "w");
                        fwrite(buffer, 1, BLOCK_SIZE, img);
                    }
                }
            }
        }
    }

}
