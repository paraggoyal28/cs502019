#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2 || !((int) argv[1][0] >= 48 
                       && (int) argv[1][0] <= 57)) //checking number of arguements and first character of the arguement 1 
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int key, ch;
        // extracting int key from string arguement
        key = atoi(argv[1]) % 26; // making key % 26
        string plain_text;
        plain_text = get_string("plaintext:  ");
        for (ch = 0; plain_text[ch] != '\0'; ch++)
        {
            if (plain_text[ch] >= 65 && plain_text[ch] <= 90) 
            {
                plain_text[ch] = ((plain_text[ch] - 'A' + key) % 26) + 'A';  
                // adding key value to the character 
            }
            else if (plain_text[ch] >= 97 && plain_text[ch] <= 122)
            {
                plain_text[ch] = ((plain_text[ch] - 'a' + key) % 26) + 'a';
                // adding key value to the character
            }
                
        }
        printf("ciphertext: %s\n", plain_text); // printing cipher_text
        return 0;
    }
}
