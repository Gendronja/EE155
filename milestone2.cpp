#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
using namespace std;

/*
You are provided with two arrays ASCII_CODES and ASCII_SYMBOLS.
ASCII_CODES: Array or list of valid ASCII codes, represented as sequences of 0s and 1s.
ASCII_SYMBOLS: Array or list of ASCII symbols for each of valid ASCII code.

For encoding, You will read input ASCII file containing ASCII characters and generate a file containing ASCII codes (sequence of 0s and 1s) and write it to a file.
For decoding, you will read sequences of 0s and 1s and then decode the sequence into correct ascii characters.

You need to generate index to access ASCII_CODES and ASCII_SYMBOLS arrays.

In your main() function add following line to generate ASCII_CODES and ASCII_SYMBOLS tables.
ASCII_Table();

*/

// DO NOT MODIFY THIS CODE
string ASCII_CODES[128];
string ASCII_SYMBOLS[128];

void ASCII_Table(){
	// This function fills ASCII_CODES and ASCII_SYMBOLS arrays.
	for (int i = 0; i < 128; i++){
		ASCII_SYMBOLS[i] = char(i);
		ASCII_CODES[i] = bitset <7> (i).to_string();
	}
}
// DO NOT MODIFY THIS CODE

// WRITE YOUR CODE FROM HERE

// Store names in buffer and swap them
void swap_names(string names[], int pos1, int pos2)
{
	string buffer = names[pos1];
	names[pos1] = names[pos2];
	names[pos2] = buffer;
}


// Uses swap_name function to operate
void sort_list(string names[], int sz_names)
{
	for (int i = 0; i < sz_names; i++) {
		for (int j = 0; j < sz_names; j++) {
			if (names[j] > names[i]) {
				swap_names(names, i, j);
			}
		}
	}
}

// Shifts list down from given position to add new name into place
void shift_list(string names[], int& sz_names, int shift_position)
{
	for (int i = sz_names; i > shift_position; i--)
	{
		names[i] = names[i - 1];
	}
}

void print_list(string names[], int sz_names)
{
	for (int i = 0; i < sz_names; i++)
	{
		cout << "Name " << i + 1 << ": " << names[i] << endl;

	}
}

// Asks for number of names and the names themselves in list, and returns it for main
void read_initial_list(string names[], int& sz_names)
{
	cout << "Please enter number of names" << endl;
	cin >> sz_names;

	for (int i = 0; i < sz_names; i++)
	{
		cout << "Enter name " << i + 1 << ": " << endl;
		cin >> names[i];
	}
	return;
}

// Uses sequential searching to find exact match of string
// If there is an exact match, returns position of name
// If no match, returns -1
int search_name_in_list(string names[], string search_name, int sz_names)
{
	for (int i = 0; i < sz_names; i++) {
		if (search_name == names[i]) {
			return(i);
		}
	}
	return(-1);
}

// Adds name to bottom of list and updates the sz_names value
void add_name_to_list(string names[], int& sz_names)
{
	// Only runs if user inputs y
	cout << "Would you like to add a name to the list? Type y or n" << endl;
	cin >> y_n;
	if (y_n == "y" || y_n == "Y") {
		string add_name;
		cout << "Please type the name you would like to add" << endl;
		cin >> add_name;
		names[sz_names] = add_name;
		sz_names++;
	}
}

// Finds position to add name
// Uses separate function to shift list down
// Adds name into list
void add_name_to_sorted_list(string names[], int& sz_names)
{
	string add_name;
	cout << "Please type the name you would like to add" << endl;
	cin >> add_name;

	for (int i = 0; i < sz_names; i++) {
		if (names[i] > add_name) {
			shift_list(names, sz_names, i);
			names[i] = add_name;
			sz_names++;
			break;
		}
	}
}

// Removes name from list while keeping order by moving all names below it up one and reduces sz_names value
// Finds position using the search_name_in_list function
void remove_name_from_list(string names[], int& sz_names)
{
	cout << "Would you like to remove a name from the list? Type y or n" << endl;
	cin >> y_n;
	if (y_n == "y" || y_n == "Y") {
		string remove_name;
		cout << "Please type the name you would like to remove" << endl;
		cin >> remove_name;
		int remove_name_position = search_name_in_list(names, remove_name, sz_names);
		if (remove_name_position == -1) {
			cout << "Does not exist in the list" << endl;
			return;
		}
		for (int i = remove_name_position; i < sz_names; i++) {
			names[i] = names[i + 1];

		}
		sz_names--;
	}
}

int main()
{




}
