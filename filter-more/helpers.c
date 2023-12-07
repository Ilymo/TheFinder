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
            float npixel = 0.0;
            int Rtop = 0;
            int Rmid = 0;
            int Rbot = 0;
            int G = 0;
            int B = 0;

            // Add main Pixel to sum
            R += copy[i][j].rgbtRed;
            G += copy[i][j].rgbtGreen;
            B += copy[i][j].rgbtBlue;
            npixel++;

            // Add left pixel
            if (j - 1 >= 0)
            {
                R += copy[i][j - 1].rgbtRed;
                G += copy[i][j - 1].rgbtGreen;
                B += copy[i][j - 1].rgbtBlue;
                npixel++;

                // Add left top
                if (i - 1 >= 0)
                {
                    R += copy[i - 1][j - 1].rgbtRed;
                    G += copy[i - 1][j - 1].rgbtGreen;
                    B += copy[i - 1][j - 1].rgbtBlue;
                    npixel++;
                }

                // add left bot
                if (i + 1 < height)
                {
                    R += copy[i + 1][j - 1].rgbtRed;
                    G += copy[i + 1][j - 1].rgbtGreen;
                    B += copy[i + 1][j - 1].rgbtBlue;
                    npixel++;
                }
            }

            // Add right pixel
            if (j + 1 < width)
            {
                R += copy[i][j + 1].rgbtRed;
                G += copy[i][j + 1].rgbtGreen;
                B += copy[i][j + 1].rgbtBlue;
                npixel++;

                // add right top
                if (i - 1 >= 0)
                {
                    R += copy[i - 1][j + 1].rgbtRed;
                    G += copy[i - 1][j + 1].rgbtGreen;
                    B += copy[i - 1][j + 1].rgbtBlue;
                    npixel++;
                }

                // add right bot
                if (i + 1 < height)
                {
                    R += copy[i + 1][j + 1].rgbtRed;
                    G += copy[i + 1][j + 1].rgbtGreen;
                    B += copy[i + 1][j + 1].rgbtBlue;
                    npixel++;
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
