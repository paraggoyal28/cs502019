if __name__ == "__main__":  # main function
    while(True):
        height = input('Height: ')  # ask for height
        if (height.isdigit()):
            if(int(height) >= 1 and int(height) <= 8):  # height found
                break

    for block in range(int(height)):
        for space in range(int(height) - block - 1):
            print(' ', end='')  # Printing spaces
        for brick in range(block+1):
            print('#', end='')  # Printing bricks
        print('  ', end='')  # Printing space
        for brick in range(block+1):
            print('#', end='')  # Printing bricks
        print()
