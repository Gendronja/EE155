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
C = []

f = open("input.txt", "r")

# Input matrix data
line = list(f)
	
for i in range(int(size)):
     A.append(line[i].split())

for i in range(int(size)):
	B.append(line[i+8].split())
 

for i in range(int(size)):
	for j in range(int(size)):
		for k in range(int(size)):
			c = c + (int(A[i][k]) * int(B[k][j]))
		C.append(c)
		c = 0
	
outfile = open("outfile.txt")
for i in range(int(size2)):
	outfile.write(str(C[i]))
