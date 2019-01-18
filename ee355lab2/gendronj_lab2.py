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

f = open("input.txt", "r")

# Input matrix data
line = list(f)
for i in range(int(size2)):
   mlist = line[i].split()
   for j in range(len(mlist)):
     A[i][j] = mlist[j]

for i in range(int(size2)):
	mlist = line[i + (int(size2))].split()
	for j in mlist:
		B[i][j] = mlist[j]
	 
	


for i in range(size):
	for j in range(size):
		for k in range(size):
			c = c + (A[i][k] * B[k][j])
		C[i][j] = c
		c = 0

outfile = open("outfile.txt")
for i in range(size):
	for j in range(size):
		outfile.write(C[i][j])
