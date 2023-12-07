#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *infile = fopen("argv[1]", "r");
    if (infile != NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

}
