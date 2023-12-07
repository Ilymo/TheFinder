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
    int buffer[512];

    while (fread(buffer, 512, 1, infile) == 1);
    {

    }

}
