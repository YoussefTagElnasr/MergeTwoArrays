#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if( argc != 2)
    {
        printf("usagee : ./recover MemoryCard\n");
        return 1;
    }

    FILE *card = fopen( argv[1] , "rb");

    if( card == NULL)
    {
        printf("couldnt open file");
        fclose(card);
        return 2;
    }


    BYTE buffer[512];
    bool found_jpg = false;
    char jpg_name [8];
    FILE  *outFile = NULL;
    int counter= 0;



    while(fread(buffer , sizeof(BYTE) , 512 , card)  == 512)
    {
        if ( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(found_jpg)
            {
                fclose(outFile);
            }
            else
            {
                found_jpg = true;
            }

            sprintf( jpg_name , "%03d.jgp" , counter);
            outFile = fopen(jpg_name , "wb");

            if(outFile == NULL)
            {
                fclose(outFile);
                printf("could not create the file %s" , jpg_name);
            }

            if(found_jpg)
            {
                fwrite( buffer , sizeof(BYTE) , 512 , outFile );
            }

            counter++;
        }
    }

    if(found_jpg)
    {
        fclose(outFile);
    }

    fclose(card);
    return 0;
}
