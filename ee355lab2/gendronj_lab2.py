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
close("input.txt")
size = row_count / 2

# Input matrix data
f = open("input.txt", "r")
line = list(f)
for i in range (len(line)/2):
   mlist = line[i].split()
   for j in mlist:
     A[i][j] = mlist[j]

for i in range (len(line)/2):
	mlist = line[i + (size*size)].split()
	for j in mlist:
		B[i][j] = mlist[j]
	 
	


for i in range(size):
	for j in range(size):
		for k in range(size):
			c = c + (A[i][k] * B[k][j])
		C[i][j] = c
		c = 0

for i in range(size):
	for j in range(size):
		print(C[i][j])