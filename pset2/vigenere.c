#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getValue(char ch)
{
    if (ch >= 97 && ch <= 122)
    {
        return ch - 'a'; // returning value of character in range 0 to 25
    }
    else if (ch >= 65 && ch <= 90)
    {
        return ch - 'A'; // returning value of character in range 0 to 25
    }
    return ch;
}
int check(string arguement)
{
    for (int ch = 0; arguement[ch] != '\0'; ch++)
    {
        if (!isalpha(arguement[ch]))
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, string argv[])
{
    if (argc != 2 || atoi(argv[1]) || !check(argv[1])) // if arguement count is not 2 or arguement[1] is integer
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
    {
        string keyword = argv[1]; // getting keyword 
        int length_keyword = strlen(keyword);
        string plain_text = get_string("plaintext:  "); // getting plaintext
        for (int ch = 0, k = 0; plain_text[ch] != '\0'; ch++) // iterating over the plaintext
        {
            if (plain_text[ch] >= 65 && plain_text[ch] <= 90) // if plaintext + ch is upper case letter
            {
                plain_text[ch] = (plain_text[ch] - 'A' + getValue(keyword[k])) % 26 + 'A';
                k = (k + 1) % length_keyword; // modulus increment of keyword iterator
            }
            else if (plain_text[ch] >= 97 && plain_text[ch] <= 122) 
                // if plaintext + ch is lower case letter
            {    
                plain_text[ch] = (plain_text[ch] - 'a' + getValue(keyword[k])) % 26 + 'a';
                k = (k + 1) % length_keyword; // modulus increment of keyword iterator
            }
             
        }
        printf("ciphertext: %s\n", plain_text); // printing cipher text
        return 0;
    }
}
