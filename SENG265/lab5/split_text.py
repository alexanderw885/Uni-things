#!/usr/bin/env python3

import sys

def main():

    if(len(sys.argv) != 2):
        print("please enter one argument!")
        exit()

    str = sys.argv[1]
    lines = str.split(",")

    for i in lines:
        print(i)


if __name__ == "__main__":
    main()
