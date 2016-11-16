num_set = {
1 : "one",
2 : "two",
3 : "three",
4 : "four",
5 : "five",
6 : "six",
7 : "seven",
8 : "eight",
9 : "nine",
10 : "ten",
11 : "eleven",
12 : "twelve",
13 : "thirteen",
14 : "fourteen",
15 : "fifteen",
16 : "sixteen",
17 : "seventeen",
18 : "eighteen",
19 : "nineteen",
20 : "twenty",
30 : "thirty",
40 : "forty",
50 : "fifty",
60 : "sixty",
70 : "seventy",
80 : "eighty",
90 : "ninety",
100 :"hundred",
1000 :"thousand"
}

# Solution tailored to Problem 17

def crunch(number):
	str_number = str(number)
	length = len(str_number)
	if length == 4:
		return "onethousand"
	if length == 3:
		d1 = int(str_number[0])
		dr = int(str_number[1:])
		if dr == 0:
			return num_set[d1] + num_set[100];
		else:
			return num_set[d1] + num_set[100] + "and" + crunch(dr);
	elif length == 2:  
		if number <= 19 or number % 10 == 0:
			return num_set[number];
		else:
			return num_set[number - (number % 10)] + num_set[number % 10];
	else:
		return num_set[number];
			
l = 0
for i in range(1,1001):
	l += len(crunch(i))
print l