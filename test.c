            RGBTRIPLE pixel = image[i][j];
            printf("%i; %i; %i\n", pixel.rgbtBlue, pixel.rgbtRed, pixel.rgbtGreen);
            if (pixel.rgbtBlue == 0)
            {
                pixel.rgbtBlue = 100;
                image[i][j] = pixel;
            }
