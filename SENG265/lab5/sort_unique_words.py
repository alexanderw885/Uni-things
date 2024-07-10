#! /usr/bin/env python3

import sys

def main():
    li = []
    for line in sys.stdin:
        words = line.split(",")
        for i in words:
            li.append(i)


    for i in range(len(li)):
        
        li[i] = li[i].rstrip()

    temp = set(li)
    li = list(temp)
    li.sort()

    for word in li:
        print(word)



if __name__ == "__main__":
    main()
