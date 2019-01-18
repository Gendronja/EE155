# Matrix Multiplication
import time

# Matrix file intake
f = open("input.txt", "r")
line = f.readline()
row_count = 0

start = time.time()
# Count how many rows in matrix file to determine size of matrices
while line:
	line = f.readline()
	row_count += 1
size = row_count / 2

A = []
B = []
C = []

# Reopen file to start at beginning
f = open("input.txt", "r")

# Input matrix data
line = list(f)
for i in range(int(size)):
     A.append(line[i].split())

for i in range(int(size)):
	B.append(line[i+8].split())
 
c = 0
for i in range(int(size)):
	for j in range(int(size)):
		for k in range(int(size)):
			c = c + (int(A[i][k]) * int(B[k][j]))
		C.append(c)
		c = 0

count = 0
outfile = open("output.txt", "w+")
for i in range(int(size*size)):
	outfile.write("%d " %(C[i]))
	count += 1
	if count == 8:
		outfile.write('\n')
		count = 0
outtime = open("output_time.txt", "w+")
end = time.time()
outfile.write("runtime = %d" %(end - start))
