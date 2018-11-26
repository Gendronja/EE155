#include <iostream>
#include <string>
using namespace std;

// E7.4

//Write a function that returns a pointer to the maximum value of an array of floating - point data :
//double* maximum(double* a, int size)
//If size is 0, return nullptr.



double* maximum(double* a, int size)
{
	double max_value = 0;
	int max_location = 0;

	if (size == 0) {
		return NULL;
	}
	for (int i = 0; i < size; i++) {
		if (max_value < a[i]) {
			max_value = a[i];
			max_location = i;
		}
	}
	// Returns memory location in array of largest value
	return (a + max_location);
}

int main()
{
	double a[10] =
	{ 1.0, 2.0, 3.0, 4.0, 5.0, 10.0, 7.0, 8.0, 9.0, 6.0 };

	double* p = maximum(a, 10);
}