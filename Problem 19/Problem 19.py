#    1 Jan 1900 was a Monday.
#    Thirty days has September,
#    April, June and November.
#    All the rest have thirty-one,
#    Saving February alone,
#    Which has twenty-eight, rain or shine.
#    And on leap years, twenty-nine.
#    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

#How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

import calendar
year = 1901
sundays = 0
for year in range(year,2000+1):
	for month in range(1,12+1):
		if calendar.weekday(year, month, 1) == 6:
			sundays+=1
print sundays

