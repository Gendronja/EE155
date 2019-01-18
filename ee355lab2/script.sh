# EE355 - Spring 2019
# Lab2 - shell script
# Shahin Nazarian
# Author: Xuejing Lei

python EE355_Lab2_*.py < input.txt

diff output.txt output_golden.txt > result.txt

if [ -s result.txt ]
then
	echo "Test Failed!"
else
	echo "Test Passed!"
fi

rm result.txt