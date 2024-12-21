#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for( int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            float avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 ;
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtRed = round(avg);
            image[i][j].rgbtBlue = round(avg);
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for( int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            float sepiaRed = round((0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            float sepiaGreen = round((0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            float sepiaBlue = round((0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            image[i][j].rgbtGreen = fmin(255, (int)sepiaGreen);
            image[i][j].rgbtRed = fmin(255 , (int)sepiaRed);
            image[i][j].rgbtBlue = fmin(255, (int)sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{;
    int LastRightElter = width - 1;

    for( int i = 0; i < height; i++)
    {
        for( int j = 0 ;  j < width / 2; j++ , LastRightElter--)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][LastRightElter];
            image[i][LastRightElter] = temp;
        }
        LastRightElter = width - 1;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for( int i = 0; i < height; i++)
    {
        for( int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;
            int counter = 0;

            for( int y = -1; y < 2; y++)
            {
                for(int x = -1; x < 2; x++)
                {
                    int currentx = x + j;
                    int currenty = y + i;

                    if( currentx < 0 || currentx > width - 1 || currenty < 0 || currenty > height + 1)
                    {
                        continue;
                    }

                    totalRed += image[currenty][currentx].rgbtRed;
                    totalBlue += image[currenty][currentx].rgbtBlue;
                    totalGreen += image[currenty][currentx].rgbtGreen;
                    counter++;
                }
            }

            temp[i][j].rgbtRed = round(totalRed / counter);
            temp[i][j].rgbtGreen = round(totalGreen / counter);
            temp[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }

    for( int i = 0; i < height; i++)
    {
        for(int j = 0; j < width ; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}


