#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gscale = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int rounded = round(gscale);
            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtBlue = rounded;
            image[i][j].rgbtGreen = rounded;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
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
            int R = 0;
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
                Rgx += (copy[i][j - 1].rgbtRed * (-2));
                Ggx += (copy[i][j - 1].rgbtGreen * (-2));
                Bgx += (copy[i][j - 1].rgbtBlue * (-2));

                // Add left top
                if (i - 1 >= 0)
                {
                    Rgx += (copy[i - 1][j - 1].rgbtRed * (-1));
                    Ggx += (copy[i - 1][j - 1].rgbtGreen * (-1));
                    Bgx += (copy[i - 1][j - 1].rgbtBlue * (-1));

                    Rgy += (copy[i - 1][j - 1].rgbtRed * (-1));
                    Ggy += (copy[i - 1][j - 1].rgbtGreen * (-1));
                    Bgy += (copy[i - 1][j - 1].rgbtBlue * (-1));
                }

                // add left bot
                if (i + 1 < height)
                {
                    Rgx += (copy[i + 1][j - 1].rgbtRed * (-1));
                    Ggx += (copy[i + 1][j - 1].rgbtGreen * (-1));
                    Bgx += (copy[i + 1][j - 1].rgbtBlue * (-1));

                    Rgy += (copy[i + 1][j - 1].rgbtRed * 1);
                    Ggy += (copy[i + 1][j - 1].rgbtGreen * 1);
                    Bgy += (copy[i + 1][j - 1].rgbtBlue * 1);
                }
            }

            // Add right pixel
            if (j + 1 < width)
            {
                Rgx += (copy[i][j + 1].rgbtRed * 2);
                Ggx += (copy[i][j + 1].rgbtGreen * 2);
                Bgx += (copy[i][j + 1].rgbtBlue * 2);

                // add right top
                if (i - 1 >= 0)
                {
                    Rgx += (copy[i - 1][j + 1].rgbtRed * 1);
                    Ggx += (copy[i - 1][j + 1].rgbtGreen * 1);
                    Bgx += (copy[i - 1][j + 1].rgbtBlue * 1);

                    Rgy += (copy[i - 1][j + 1].rgbtRed * (-1));
                    Ggy += (copy[i - 1][j + 1].rgbtGreen * (-1));
                    Bgy += (copy[i - 1][j + 1].rgbtBlue * (-1));
                }

                // add right bot
                if (i + 1 < height)
                {
                    Rgx += (copy[i + 1][j + 1].rgbtRed * 1);
                    Ggx += (copy[i + 1][j + 1].rgbtGreen * 1);
                    Bgx += (copy[i + 1][j + 1].rgbtBlue * 1);

                    Rgy += (copy[i + 1][j + 1].rgbtRed * 1);
                    Ggy += (copy[i + 1][j + 1].rgbtGreen * 1);
                    Bgy += (copy[i + 1][j + 1].rgbtBlue * 1);
                }
            }
            // Add top pixel
            if (i - 1 >= 0)
            {
                Rgy += (copy[i - 1][j].rgbtRed * (-2));
                Ggy += (copy[i - 1][j].rgbtGreen * (-2));
                Bgy += (copy[i - 1][j].rgbtBlue * (-2));
            }

            // Add bottom pixel
            if (i + 1 < height)
            {
                Rgy += (copy[i + 1][j].rgbtRed * 2);
                Ggy += (copy[i + 1][j].rgbtGreen * 2);
                Bgy += (copy[i + 1][j].rgbtBlue * 2);
            }

            // Calculate value of R, B and G and check if <255
            int Rholder = round(sqrt((Rgx * Rgx) + (Rgy * Rgy)));
            if (Rholder > 255)
            {
                Rholder = 255;
            }

            int Gholder = round(sqrt((Ggx * Ggx) + (Ggy * Ggy)));
            if (Gholder > 255)
            {
                Gholder = 255;
            }

            int Bholder = round(sqrt((Bgx * Bgx) + (Bgy * Bgy)));
            if (Bholder > 255)
            {
                Bholder = 255;
            }

            // write the rounded value to image
            image[i][j].rgbtRed = Rholder;
            image[i][j].rgbtGreen = Gholder;
            image[i][j].rgbtBlue = Bholder;
        }
    }
    return;
}
