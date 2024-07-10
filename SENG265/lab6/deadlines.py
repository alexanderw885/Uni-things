#!/usr/bin/env python3

import datetime


def init():
    return [(datetime.datetime(2024, 1, 20), datetime.datetime(2024, 3, 7)),
        (datetime.datetime(2024, 4, 18), datetime.datetime(2024, 5, 16)),
        (datetime.datetime(2024, 1, 1), datetime.datetime(2024, 5, 28)),
        (datetime.datetime(2024, 1, 22), datetime.datetime(2024, 2, 7)),
        (datetime.datetime(2024, 2, 10), datetime.datetime(2024, 4, 18)),
        (datetime.datetime(2024, 2, 21), datetime.datetime(2024, 6, 12)),
        (datetime.datetime(2024, 4, 2), datetime.datetime(2024, 6, 7)),
        (datetime.datetime(2024, 5, 16), datetime.datetime(2024, 5, 26)),
        (datetime.datetime(2024, 3, 19), datetime.datetime(2024, 4, 21)),
        (datetime.datetime(2024, 6, 3), datetime.datetime(2024, 6, 12))]


"""
The following won't work immediately as you must as first add
parameters to the function definition.
"""

def within_deadline(d1, d2, dateRange):

    diff = datetime.timedelta()
    diff = d2 - d1
    k = diff.days

    if diff.days <= dateRange:
        return True

    return False


def main():
    data = init()
    white_space = ""
    for (d1, d2) in data:
        print(white_space, end="")

        print(d1)
        print(d2)
        if within_deadline(d1, d2, 14):
            print("Dates ARE within 14 days of each other")

            print("The first date is a " + d1.strftime("%A"))

        else:
            print("Dates are NOT within 14 days of each other")
        
        white_space = "\n"


if __name__ == "__main__":
    main()
