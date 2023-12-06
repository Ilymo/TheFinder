#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtBlue == 0 && image[i][j].rgbtGreen == 0)
            {
                float gscale = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) * 3.0;
                
                image[i][j].rgbtRed =
                image[i][j].rgbtBlue = 50;
                image[i][j].rgbtGreen = 50;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
