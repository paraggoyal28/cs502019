import sys
import crypt


def main():
    if len(sys.argv) != 2:
        print("Usage: crack <hash>")
        sys.exit(1)

    ahash = sys.argv[1]  # given hash
    salt = ahash[0:2]  # salt of a given hash is first two characters
    letters = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"  # combination of all characters

    for fifth in letters:  # five for loops
        for fourth in letters:
            for third in letters:
                for second in letters:
                    for first in letters[1:]:
                        candidate = f"{first}{second}{third}{fourth}{fifth}".strip()

                        if crypt.crypt(candidate, salt) == ahash:  # crypting the candidate with salt and comparing with the given hash
                            print(candidate)
                            sys.exit(0)


if __name__ == "__main__":
    main()
