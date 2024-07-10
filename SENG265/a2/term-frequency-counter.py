#! /usr/bin/env python3

import sys

def main():

    dict = {}
    MakeDictionary(dict)
    output = SortDict(dict)

    for word in output:
        print("%s %d" % (word, output[word]))


def SortDict(dict):

    keyList = list(dict.keys())            #creates list of dict keys to sort, then makes a new
    keyList.sort()                         #dictionary with keys in sorted order
    sortedDict = {}
    
    for word in keyList:
        sortedDict[word] = dict[word]

    return sortedDict



def MakeDictionary(dict):
    for line in sys.stdin:
        words = line.split(" ")
        for i in range(len(words)):    #cleaning words to remove issues with new lines/spaces
            words[i] = words[i].strip()

        for word in words:                #filling the dictionary
            if len(word) == 0:        #gets rid of empty strings
                continue
            if dict.get(word) == None:
                dict[word] = 1
            else:
                dict[word] = dict[word] + 1



if __name__ == "__main__":
    main()
