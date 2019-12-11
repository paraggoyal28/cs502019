#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[1];

    //open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int imageCount = 0;

    char filename[8];
    FILE *outptr = NULL;

    while (true)
    {
        // read a block of memory card image
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }

        // check if we found a JPEG
        bool containsJPEGHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // if we found yet another JPEG we must close previous file
        if (containsJPEGHeader && outptr != NULL)
        {
            fclose(outptr);
            imageCount++;
        }

        // if we found a JPEG image we need to open file for writing
        if (containsJPEGHeader)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            outptr = fopen(filename, "w");
        }

        // write anytime we open a new file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }

    // close last jpeg file
    fclose(outptr);

    // close infile
    fclose(inptr);

    //success
    return 0;
}
