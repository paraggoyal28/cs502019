import sys
from cs50 import get_string


def is_valid(k):
    for ch in k:
        if not ch.isalpha():
            return False
    return True


def main():
    if len(sys.argv) != 2 or not is_valid(sys.argv[1]):
        print("Usage: ./vigenere k")
        sys.exit(1)

    k = sys.argv[1]  # getting key
    plaintext = get_string("plaintext: ")  # getting plain text
    j = 0

    print("ciphertext: ", end="")

    for ch in plaintext:
        if not ch.isalpha():
            print(ch, end="")
            continue

        ascii_offset = 65 if ch.isupper() else 97  # offset is 65 if upper case and 97 if lowercase

        pi = ord(ch) - ascii_offset  # converting alphabet to 0-25
        kj = ord(k[j % len(k)].upper()) - 65  # converting key value to 0-25
        ci = (pi + kj) % 26  # adding the key and plain text
        j += 1

        print(chr(ci + ascii_offset), end="")  # converting the cipher index to text

    print()

    return 0


if __name__ == "__main__":
    main()