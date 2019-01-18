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

print(size)
print(size2)
print (row_count)