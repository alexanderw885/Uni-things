#!/usr/bin/env python3

import datetime

def main():
    """
    Florence is a nurse in a clinic. She is caring for 4 patients on
    different medication schedules

    * Mark needs medication every 5 hours
    * Susan needs medication every 3 hours
    * Chloe needs medication every 8 hours
    * Alexander needs medication every 10 hours

    Starting with your current day and time, make a care schedule
    for the next 14 days that Florence can use to schedule
    who needs medication at what time.

    Follow the steps provided.

    STEP 1: Use function patient_schedule to get a list of
    medication times for every patient

    mark_schedule = <...........COMPLETE..................>
    susan_schedule = <...........COMPLETE..................>
    chloe_schedule = <...........COMPLETE..................>
    alexander_schedule = <...........COMPLETE..................>


    STEP 2: Combine all the lists and then form a master list of
    when medication is required by which patient.

    Print the medication schedule sorted by time in the format below:

      Friday, 25 03 2023, 09:24:27 Time to give medication to Alexander
      Friday, 25 03 2023, 10:24:27 Time to give medication to Chloe

    Refer to care_required.txt to see what the final output
    should look like. You are not required to write this information
    to a file. Simply output to console is enough.

    Note that care_required.txt does not contain the required output for
    this program. It only shows what the output should look like.

    HINT: You will need to keep track of who needs medication when.
    One way of doing this is with a dictionary. You may choose to
    use other ways.
    """
    # COMPLETE YOUR IMPLEMENTATION
    markList = patient_schedule("Mark", 5)
    susanList = patient_schedule("Susan", 3)
    chloeList = patient_schedule("Chloe", 8)
    alexanderList = patient_schedule("Alexander", 10)

    masterList = list(susanList.keys())

    for date in list(chloeList.keys()):
        masterList.append(date)

    for date in list(alexanderList.keys()):
        masterList.append(date)

    for date in list(markList.keys()):
        masterList.append(date)

    sortedDict = {}

   # print(len(masterList))
    masterList = sorted(masterList)
    for date in masterList:
        if markList.get(date) != None:
            printFormat(date, "Mark")
        if susanList.get(date) != None:
            printFormat(date, "Susan")
        if chloeList.get(date) != None:
            printFormat(date, "Chloe")
        if alexanderList.get(date) != None:
            printFormat(date, "Alexander")


    

def patient_schedule(patient_name, interval_in_hours):
    

    dict = {}
    time = datetime.datetime.now()
    end = time + datetime.timedelta(days = 14)
    interval = datetime.timedelta(hours = interval_in_hours)
    
    while time < end:
        dict[time] = patient_name
        time = time + interval

    return dict

#      Friday, 25 03 2023, 09:24:27 Time to give medication to Alexander
def printFormat(date, name):

    weekday = date.strftime("%A")
    day = date.day
    month = date.month
    year = date.year
    time = str(date.strftime("%X"))
    print("%s, %d %d, %s Time to give medication to %s" % (weekday, day, month, time, name))




if __name__ == "__main__":
    main()




























