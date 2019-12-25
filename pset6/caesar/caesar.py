import sys
from cs50 import get_string


def main():
    if len(sys.argv) != 2:
        print("Usage: ./caesar k")
        sys.exit(1)

    k = int(sys.argv[1])
    plaintext = get_string("plaintext: ")

    print("ciphertext: ", end="")

    for ch in plaintext:
        if not ch.isalpha():
            print(ch, end="")  # printing non alpha characters as it is
            continue

        ascii_offset = 65 if ch.isupper() else 97  # ascii offset calculation for lower case letters and upper case letters

        pi = ord(ch) - ascii_offset  # getting value of ascii character in between 0 and 25
        ci = (pi + k) % 26  # adding k to the digit and modulus by 26

        print(chr(ci + ascii_offset), end="")  # printing character of encrypted text

    print()

    return 0


if __name__ == "__main__":
    main()
