# EE355 Spring 2019
# Author: Jason Gendron
# Lab2
# Description:
# Matrix multiplication using two square matrices
# Calculating runtime of code

# Start time for runtime calculation
import time
start = time.time()

# Initialize empty lists for storing matrix data
A = []
B = []
C = []

# Matrix file intake
f = open("input.txt", "r")

# Count how many rows in matrix file to determine size of matrices for future adaptability
#while line:
	#line = f.readline()
	#row_count += 1
line = f.readlines()
row_count = len(line)
print(row_count)
size = row_count / 2

# Reopen file to start at beginning
f = open("input.txt", "r")

# Input matrix data into matrices A and B
line = list(f)
for i in range(int(size)):
     A.append(line[i].split())

for i in range(int(size)):
	B.append(line[i+8].split())

# Calculate matrix C	
c = 0
for i in range(int(size)):
	for j in range(int(size)):
		for k in range(int(size)):
			c = c + (int(A[i][k]) * int(B[k][j]))
		C.append(c)
		c = 0

# Write result of matrix multiplication to output file
count = 0
outfile = open("output.txt", "w+")
for i in range(int(size*size)):
	outfile.write("%d " %(C[i]))
	count += 1
	if count == 8:
		outfile.write('\n')
		count = 0

# Calculate and write runtime to new file
outtime = open("output_time.txt", "w+")
end = time.time()
outtime.write("runtime = %f" %(end - start))
