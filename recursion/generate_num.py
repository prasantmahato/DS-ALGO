import random

file = open("random.txt",'w')

for i in range(100000):
	num = random.randint(0,i+1)
	file.write(str(num))
	file.write("\n")
file.close()


