# Matrix Multiplication
c = 0

# Matrix intake
f = open("input.txt", "r")
line = f.readline()
row_count = 0

# Count how many rows in matrix file
while line:
	line = f.readline()
	row_count += 1
size = row_count / 2
size2 = size * size

A = []
B = []

f = open("input.txt", "r")

# Input matrix data
line = list(f)
print(line)


# Remove \n from list
#line.strip("\n")
	
for i in range(int(size)):
     A.append(line[i])

for i in range(int(size)):
	B.append(line[i+8])
	 
print (A)
print (B)	 

#for i in range(size):
#	for j in range(size):
#		for k in range(size):
#			c = c + (A[i][k] * B[k][j])
#		C[i][j] = c
#		c = 0

#outfile = open("outfile.txt")
#outfile.write(C)
