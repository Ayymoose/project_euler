num_set = {
0 : "",
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

def crunch(number):
	if number <= 19:
		return num_set[number]
	else:
		number_string = str(number)
		length = len(number_string)
		if length == 2:
			return num_set[number - (number % 10)] + num_set[number % 10]
		elif length == 3:
			if int(number_string[1:]) == 0:
				return num_set[int(number_string[0])] + num_set[100]
			else:
				return num_set[int(number_string[0])] + num_set[100] + "and" + crunch(int(number_string[1:]))
		elif length == 4:
			if int(number_string[1:]) == 0:
				return num_set[int(number_string[0])] + num_set[1000]
			else:
				return num_set[int(number_string[0])] + num_set[1000] + crunch(int(number_string[1:]))
		else:
			return "undefined"

#print crunch(19)
#print crunch(7)
#print crunch(60)
#print crunch(25)
#print crunch(100)
#print crunch(119)
#print crunch(234)
#print crunch(230)
#print crunch(1000)
	
l = 0
for i in range(1,1001):
	l += len(crunch(i))
print l