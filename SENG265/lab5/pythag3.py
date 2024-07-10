#!/usr/bin/env python3

import sys

def pythag(a, b):
    c = (a*a + b*b) **0.5
    return c


def main():
 
    if(len(sys.argv) != 3):
        print("please enter 2 numbers as arguments")
        exit()

    a = float(sys.argv[1])
    b = float(sys.argv[2])

    print("Sides ", a, " and ", b, ", hypotenuse ", end="", sep="")
    print("%.4f" % pythag(a, b))


if __name__ == "__main__":
    main()
