from cs50 import get_string
import sys


def main():

    if len(sys.argv) != 2:  # checking if dictionary is provided in the arguements or not
        print("Usage: bleep.py dictionary")
        sys.exit(1)

    k = sys.argv[1]  # getting the file name
    banned_words = []  # creating banned words array
    with open(k, 'r') as file:
        banned_words = file.readlines()  # storing banned words in an array

    file.close()  # closing the opened file

    banned_words = [word.strip() for word in banned_words]  # removing new line character from each banned word

    print("What message would you like to censor?")

    message = list(input().split())

    for words in message:
        if words.lower() in banned_words:  # checking the message word in banned words
            print("*" * len(words), end="")
        else:
            print(words, end="")
        print(" ", end="")
    print()

    return 0


if __name__ == "__main__":
    main()
