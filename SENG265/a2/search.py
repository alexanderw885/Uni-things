#! /usr/bin/env python3

import fileinput
import sys
import math
#import os
                 #cat search-tests/input01/query01.txt | ./search.py search-tests/index01
def main():

    if len(sys.argv) != 2:
        print("enter 1 argument of index files")
        exit()

    docs = openFile(sys.argv[1]+"/sorted_documents.txt")
    terms = openFile(sys.argv[1]+"/sorted_terms.txt")
    matrix = openFile(sys.argv[1]+"/td_matrix.txt")

    prompt = sys.stdin.read()
    prompt = prompt.strip()

    terms = terms.strip()
    query_vector = makeVector(prompt, terms) 
    matrix_list = makeUseful(matrix)


    #makes a list by pairing each cosine error value with its respective filename, then adds
    #this list to errorList
    errorList = []
    for i, item in enumerate(matrix_list):
        error = cosError(query_vector, item)
        errorList.append((error, docs.split('\n')[i]))

    #luckily it looks like sorted sorts lists by their first value, so this puts all elements
    #or errorList into reverse order by cosine error value, ready to be printed
    errorList = sorted(errorList)
    for item in reversed(errorList):
        print('%.4f %s' % (item[0], item[1]))
    
    

def openFile(address):
    '''takes file name, reads file, and outputs contents'''
    tempFile = open(address, "r")
    output = tempFile.read()
    tempFile.close()
    return output

def makeVector(prompt, terms):
    '''takes user input prompt, compares it to terms, makes a query vector '''
    output = []

    for i, line in enumerate(terms.split('\n')):
        match = 0
        for word in prompt.split('\n'):
            if word.split(' ')[0] == line.split(' ')[0]:
                output.append(int(word.split(' ')[1]))
                match = 1
                break
        if match == 0:
            output.append(0)
    
    
    return output

def makeUseful(matrix):
    '''turns matrix from a string into a 2d array of integers'''
    output = []
    matrix = matrix.strip()
    for i, line in enumerate(matrix.split('\n')):
        if i == 0:
            continue
        temp_list = []
        for value in line.split(' '):
            temp_list.append(int(value))
        output.append(temp_list)

    output = rotate(output)
    return output

def rotate(matrix):
    '''rotates matrix, to make things slightly easier for me later'''
    output = []
    for i in range(len(matrix[0])):
        temp = []
        for j in range(len(matrix)):
            temp.append(matrix[j][i])
        output.append(temp)
    return output




def cosError(query, matrix):
    '''computes cosine error of 2 vectors'''
    
    if len(matrix) != len(query):
        print("what")
        exit(1)    

    dot = 0
    matrix_mag = 0
    query_mag = 0
    for i in range(len(matrix)):
        dot += (query[i]*matrix[i])
        matrix_mag += matrix[i]**2
        query_mag += query[i]**2

    matrix_mag = math.sqrt(matrix_mag)
    query_mag = math.sqrt(query_mag)
    magnitude = matrix_mag * query_mag
    if magnitude == 0:
        return 0
    return dot/magnitude
    
    


if __name__ == "__main__":
    main()

























