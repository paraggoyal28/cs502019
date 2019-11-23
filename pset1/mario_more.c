#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: "); // get height 
    }
    while (height < 1 || height > 8); // iterate while height is not between 1 and 8.
    for (int i = 1; i <= height; i++) // for loop from 1 to height of brick
    {
        for (int space = height - i; space > 0; space--)
        {
            printf(" "); // for space
        }
        for (int comment = 0; comment < i; comment++)
        {
            printf("#"); // actual bricks
        }
        printf("\n");
    }
}
