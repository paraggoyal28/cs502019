from cs50 import get_int
from math import floor


def main():
    digit1 = 0
    digit2 = 0
    num_digits = 0
    sum_of_double_odds = 0
    sum_of_evens = 0
    cc_number = get_int("Number: ")  # getting card number

    while cc_number > 0:  # calculating sum of even number and sum of digits of twice the odd number
        digit2 = digit1
        digit1 = cc_number % 10

        if num_digits % 2 == 0:
            sum_of_evens += digit1
        else:
            multiple = 2 * digit1
            sum_of_double_odds += (multiple // 10) + (multiple % 10)

        cc_number //= 10
        num_digits += 1  # calculating the number of digits in the number

    is_valid = (sum_of_evens + sum_of_double_odds) % 10 == 0  # checking validity of the card
    first_two_digits = (digit1 * 10) + digit2  # calculating first two digits of the card

    if digit1 == 4 and num_digits >= 13 and num_digits <= 16 and is_valid:  # valid VISA card
        print("VISA\n")
    elif first_two_digits >= 51 and first_two_digits <= 55 and is_valid and num_digits == 16:  # valid MASTERCARD
        print("MASTERCARD\n")
    elif (first_two_digits == 34 or first_two_digits == 37) and num_digits == 15 and is_valid:  # valid AMEX Card
        print("AMEX\n")
    else:
        print("INVALID\n")  # invalid card number


if __name__ == "__main__":
    main()