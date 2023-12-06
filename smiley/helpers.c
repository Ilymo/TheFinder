#include "helpers.h"
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            printf("%i; %i; %i\n", pixel.rgbtBlue, pixel.rgbtRed, pixel.rgbtGreen);
            if (pixel.rgbtBlue == 0)
            {
                pixel.rgbtBlue = 100;
            }
            printf("%i; %i; %i\n", pixel.rgbtBlue, pixel.rgbtRed, pixel.rgbtGreen);
        }
    }
}
