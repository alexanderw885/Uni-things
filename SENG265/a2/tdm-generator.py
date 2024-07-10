#! /usr/bin/env python3

import fileinput
import sys
import os

def main():

    if os.path.exists(sys.argv[2]) == False:    #creates output directory, if it does not already exist
        os.mkdir(sys.argv[2])

    docList = sortDocs()

    fileList = []                #makes list of all input files and opens them
    for item in docList:
        fileList.append(open(sys.argv[1]+"/"+item, "r"))

    textList = []                #copies contents of files to array of strings
    for item in fileList:
        textList.append(item.read())

    for item in fileList:
        item.close()


    sortedList = make_wordSet(textList)


    makeMatrix(sortedList, textList)



def sortDocs():
    """grabs the name of each file in the input directory, and sorts them alphabetically"""
    docList = []
    for item in os.listdir(sys.argv[1]):
        docList.append(item)

    docList = sorted(docList)
                                              #creates file if needed, opens in write only
    if os.path.exists(sys.argv[2]+"/sorted_documents.txt") == True:
        output = open(sys.argv[2]+"/sorted_documents.txt", "w")
    else:
        output = open(sys.argv[2]+"/sorted_documents.txt", "x")

    for item in docList:
        output.write(item + "\n")

    output.close()
    return docList


def make_wordSet(textList):
    """creates one list with all words from each text document, sorted alphabetically"""
    words = []

    for item in textList:    #strips each file to remove trailing new lines, adds each word to a list
        item = item.strip()
        for line in item.split('\n'):
            words.append(line.split(" ")[0])

    tempSet = set(words)
    words = list(tempSet)
    words = sorted(words)

    if os.path.exists(sys.argv[2]+"/sorted_terms.txt") == True:#creates file if needed, opens in write only
        output = open(sys.argv[2]+"/sorted_terms.txt", "w")
    else:
        output = open(sys.argv[2]+"/sorted_terms.txt", "x")
    
    for item in words:
        output.write(item + "\n")

    output.close()

    return words


def makeMatrix(sortedList, textList):
    
    matrix = {}
    
    for word in sortedList:        #this mess checks if word is in each file, and if it is then it 
        frequency=[]               #narrows down which line, and adds the frequency in each file to
        for item in textList:      #the frequency list
            if ('\n'+word+' ') in item or word == item.split(' ')[0]:
                lines = item.split('\n')
                for line in lines:
                    if word == line.split(' ')[0]:
                        frequency.append(line.split(' ')[1])
                        break
            else:
                frequency.append(0)      #if word isn't in file, adds a zero instead
        matrix[word] = tuple(frequency)


    outstring = ""

    for key in matrix:            #creating matrix format for output file into a regular string first
        for value in matrix[key]: #out of convenience
            outstring += str(value) + " "
        outstring = outstring.strip()
        outstring += "\n"
    outstring = outstring.strip()

    if os.path.exists(sys.argv[2]+"/td_matrix.txt") == True:  #creates file if needed, opens in write only
        output = open(sys.argv[2]+"/td_matrix.txt", "w")
    else:
        output = open(sys.argv[2]+"/td_matrix.txt", "x")

    output.write("%d %d\n%s\n" % (len(sortedList), len(textList), outstring))


    output.close()
    
if __name__ == "__main__":
    main()
