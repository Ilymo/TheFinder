#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Creat copy of "image"
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Rgx = 0;
            int Ggx = 0;
            int Bgx = 0;

            int Rgy = 0;
            int Ggy = 0;
            int Bgy = 0;

            // determine Gx and Gy
            // Add left pixel
            if (j - 1 >= 0)
            {
                Rgx += copy[i][j - 1].rgbtRed * -2;
                Ggx += copy[i][j - 1].rgbtGreen * -2;
                Bgx += copy[i][j - 1].rgbtBlue * -2;

                Rgy += copy[i][j - 1].rgbtRed * 0;
                Ggy += copy[i][j - 1].rgbtGreen * 0;
                Bgy += copy[i][j - 1].rgbtBlue * 0;

                // Add left top
                if (i - 1 >= 0)
                {
                    Rgx += copy[i - 1][j - 1].rgbtRed * -1;
                    Ggx += copy[i - 1][j - 1].rgbtGreen * -1;
                    Bgx += copy[i - 1][j - 1].rgbtBlue * -1;

                    Rgy = Rgx;
                    Ggy = Ggx;
                    Bgy = Bgx;
                }

                // add left bot
                if (i + 1 < height)
                {
                    Rgx += copy[i + 1][j - 1].rgbtRed * -1;
                    Ggx += copy[i + 1][j - 1].rgbtGreen * -1;
                    Bgx += copy[i + 1][j - 1].rgbtBlue * -1;

                    Rgy += copy[i + 1][j - 1].rgbtRed * 1;
                    Ggy += copy[i + 1][j - 1].rgbtGreen * 1;
                    Bgy += copy[i + 1][j - 1].rgbtBlue * 1;

                }
            }

            // Add right pixel
            if (j + 1 < width)
            {
                Rgx += copy[i][j + 1].rgbtRed * 2;
                Ggx += copy[i][j + 1].rgbtGreen * 2;
                Bgx += copy[i][j + 1].rgbtBlue * 2;

                Rgy += copy[i][j + 1].rgbtRed * 0;
                Ggy += copy[i][j + 1].rgbtGreen * 0;
                Bgy += copy[i][j + 1].rgbtBlue * 0;

                // add right top
                if (i - 1 >= 0)
                {
                    Rgx += copy[i - 1][j + 1].rgbtRed * 1;
                    Ggx += copy[i - 1][j + 1].rgbtGreen * 1;
                    Bgx += copy[i - 1][j + 1].rgbtBlue * 1;

                    Rgy += copy[i - 1][j + 1].rgbtRed * - 1;
                    Ggy += copy[i - 1][j + 1].rgbtGreen * - 1;
                    Bgy += copy[i - 1][j + 1].rgbtBlue * - 1;
                }

                // add right bot
                if (i + 1 < height)
                {
                    Rgx += copy[i + 1][j + 1].rgbtRed * 1;
                    Ggx += copy[i + 1][j + 1].rgbtGreen * 1;
                    Bgx += copy[i + 1][j + 1].rgbtBlue * 1;

                    Rgy = Rgx;
                    Ggy = Ggx;
                    Bgy = Bgx;
                }
            }
            // Add top pixel
            if (i - 1 >= 0)
            {
                R += copy[i - 1][j].rgbtRed;
                G += copy[i - 1][j].rgbtGreen;
                B += copy[i - 1][j].rgbtBlue;
                npixel++;
            }

            // Add bottom pixel
            if (i + 1 < height)
            {
                R += copy[i + 1][j].rgbtRed;
                G += copy[i + 1][j].rgbtGreen;
                B += copy[i + 1][j].rgbtBlue;
                npixel++;
            }

            // Calculate average of each color
            float avR = R / npixel;
            float avG = G / npixel;
            float avB = B / npixel;

            // write the rounded value to image
            image[i][j].rgbtRed = round(avR);
            image[i][j].rgbtGreen = round(avG);
            image[i][j].rgbtBlue = round(avB);
        }
    }
    return;
}
