#!/usr/bin/env python3

# write the pythag() function here
def pythag(a, b):
    c = (a*a + b*b) **0.5
    return c

def main():
    print("Sides %.3f and %.3f, hypotenuse %.4f" 
        % (10, 13, pythag(10, 13)) )

    print("Sides %.3f and %.3f, hypotenuse %.4f" 
        % (21.9, 31.2, pythag(21.9, 31.2)) )

    print("Sides %.3f and %.3f, hypotenuse %.4f" 
        % (719.21, 21.2, pythag(719.21, 21.2)) )


if __name__ == "__main__":
    main()
