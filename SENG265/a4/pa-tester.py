#!/usr/bin/env python3

import sys
import re


def allowed(password):
	'''removes any passwords that don't match the minimum requirements'''
	stillGood = True
	output = ''

	if(len(password) < 8):
		output = 'INVALID,TOO_SHORT'
		stillGood = False
	
	'''0x00-0x7F is range of ASCII characters, this loop searches for anything but that'''
	if re.search('[^\x00-\x7F]', password):
		if stillGood:
			output = 'INVALID'
			stillGood = False
		output += ',NONASCII'

	if stillGood:
		return ''
	return output


def make_expressions():
	'''compiles all the regex beforehand, to lower runtime'''
	regex = []
	regex.append(re.compile('[A-Z]'))
	regex.append(re.compile('[a-z]'))
	regex.append(re.compile('[0-9]'))
	#nope
	#regex.append(re.compile(r'[!#$%&()*+,\-\./:;<=>?@[]^_`{|}~]'))

	#seemed way easier, ["] and ['] were not in special char list
	regex.append(re.compile('''[^a-zA-Z0-9"']'''))   
	regex.append(re.compile(r'(.)\1{2}'))	    #\1 is a reference to previous char

	return regex


def evaluate(password, regex):
	score = 1
	text = ''
	#goes through each regular expression to add/remove points and add to the discription string
	if(regex[0].search(password)):
		score += 1
		text += ',UPPERCASE'

	if(regex[1].search(password)):
		score += 1
		text += ',LOWERCASE'
	
	if(regex[2].search(password)):
		score += 1
		text += ',NUMBER'

	if(regex[3].search(password)):
		score += 1
		text += ',SPECIAL'

	if(regex[4].search(password)):
		score -= 1
		text += ',sequence'

	#rates password based on score
	if score == 0:   text = 'INVALID'
	elif score == 1: text = 'VERY_WEAK' + text
	elif score == 2: text = 'WEAK' + text
	elif score == 3: text = 'MEDIUM' + text
	elif score == 4: text = 'STRONG' + text
	else:		 text = 'VERY_STRONG' + text	

	return (text, score)



def main():
	""" This script reads a text from standard input,
	analyzes the validity of a password in each line,
	if valid assesses the strength of the password,
	and writes results of the password analysis into
	the standard output  """

	# if arguments provided, show error message
	if len(sys.argv) != 1:
		print("No arguments should be provided.")
		print("Usage: %s" % sys.argv[0])
		return 1;

	# ADD YOUR CODE HERE
	regex = make_expressions()

	for line in sys.stdin:

		line = line.strip()
		output = ''
		score = 0

		#check to make sure password is allowed before actually doing all required checks
		output = allowed(line)
		if(output != ''):
			print('%d,%s' % (score, output))
			continue
		
		output, score = evaluate(line, regex)
		print('%d,%s' % (score, output))


	# end the script normally
	return 0 

if __name__ == "__main__":
	main()

