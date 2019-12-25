from cs50 import get_float
from math import floor


def main():
    while True:  # while cents_owed < 0 or string
        dollars_owed = get_float('Change owed: ')
        cents_owed = floor(dollars_owed * 100)

        if cents_owed > 0:
            break

    quarters = cents_owed // 25  # cents divide by 25
    dimes = (cents_owed % 25) // 10  # remaining cents divide by 10
    nickles = ((cents_owed % 25) % 10) // 5  # remaining cents divide by 5
    pennies = (((cents_owed % 25) % 10) % 5)  # remaining cents

    print(f"{quarters + dimes + nickles + pennies}")  # printing result


if __name__ == "__main__":
    main()