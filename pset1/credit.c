#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    long credit;
    long copy_credit;
    int length = 0;
    bool even = true;
    int sum = 0;
    int starting_number;
    int remainder[16];
    do
    {
        
        credit = get_long("Number: "); // getting number
        
    }
    while (credit < 0); // while not valid number
    
    copy_credit = credit;
    while (copy_credit) // calculating  sum and length of number
    {
        remainder[length] = copy_credit % 10;
        length++;
        copy_credit /= 10; 
    }
    for (long value = length - 1; value >= 0; value--)
    {    
        if (value & 1)
        {
            long number = remainder[value] * 2;
            while (number)
            {
                sum += number % 10;
                number /= 10;
            }
        }
        else
        {
            sum += remainder[value];
        }
    }
    starting_number = (remainder[length - 2] + remainder[length - 1] * 10); // calculating   first two digits of number
    
    if (!(sum % 10))
    {
        if ((length == 15) && (starting_number == 34 || starting_number == 37))
        {
            printf("AMEX\n"); // valid amex number
        }
        else if ((length == 16) && (starting_number == 51 || starting_number == 52
                                    || starting_number == 53 || starting_number == 54
                                    || starting_number == 55))
        {
            printf("MASTERCARD\n"); // valid mastercard
        }
        else if ((length == 13 || length == 16) && (remainder[length - 1] == 4))
        {
            printf("VISA\n"); // valid visa number
        }
        else
        {
            printf("INVALID\n"); // invalid number
        }
    }
    else
    {
        printf("INVALID\n"); // invalid number
    }
}
