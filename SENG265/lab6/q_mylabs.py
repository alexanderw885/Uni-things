#!/usr/bin/env python3

import datetime

def main():
    """
    Create a datetime object for today's date
    """

    todays_date = datetime.datetime(2023, 10, 19)

    date_list = every_lab(todays_date)

    for date in date_list:
        weekday = date.strftime("%a")
        month = date.strftime("%B")
        print("%s, %d %s %d" % (weekday, date.day, month, date.year % 100))

#print these dates in the format "Mon, 19 November 23

    


def every_lab(todays_date):

    week = datetime.timedelta(days = 7)
    deadline = datetime.datetime(2023, 12, 4)
    output = []

    while todays_date < deadline:
        output.append(todays_date)
        todays_date = todays_date + week

    return output

if __name__ == "__main__":
    main()
