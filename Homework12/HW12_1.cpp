#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Consider this program segment:
	char a[] = "Mary had a little lamb";
	char* p = a;
	int count = 0;
	while (*p != '\0')
	{
		count++;
		while (*p != ' ' && *p != '\0') { p++; }
		while (*p == ' ') { p++; }
	}
	//What is the value of count at the end of the outer while loop ?
	cout << count
	//Count = 5, due to while loops only counting each word in the array
}