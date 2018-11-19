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

void ASCII_Table() {
	// This function fills ASCII_CODES and ASCII_SYMBOLS arrays.
	for (int i = 0; i < 128; i++) {
		ASCII_SYMBOLS[i] = char(i);
		ASCII_CODES[i] = bitset <7>(i).to_string();
	}
}
// DO NOT MODIFY THIS CODE

// WRITE YOUR CODE FROM HERE


// Uses sequential searching to find exact match of string
// If there is an exact match, returns position of name
// If no match, returns -1 (should never happen in this program)
int search_name_in_list(string names[], string search_name, int sz_names)
{
	for (int i = 0; i < sz_names; i++) {
		if (search_name == names[i]) {
			return(i);
		}
	}
	return(-1);
}

// Creates a binary tree for use in searching
// Fills all values before the leaf node with 0 to prevent random values from appearing
void create_binary_tree(string array[])
{
	for (int i = 0; i < 127; i++) {
		array[i] = "0";
	}
	for (int i = 127; i < 255; i++) {
		array[i] = ASCII_SYMBOLS[i - 127];
	}
}

// Uses binary tree arrays to search for information
string search_tree(string tree[], int nodes, string code)
{
	int bit;
	int index = 0;
	for (int i = 0; i < nodes; i++) {
		if (code.substr(i, 1) == "1") {
			bit = 1;
		}
		else {
			bit = 0;
		}
		index = (index * 2) + 1 + bit;
	}
	return (tree[index]);
}

// Takes .txt file and outputs a new encoded file that contains ascii code as 7 bits.
// Uses search_name_in_list function to compare position of each character read to ascii table values

void encode_file()
{
	int symbol_position;
	char c;
	string ch;

	// Change this file name to read a different file
	ifstream to_encode("char_text.txt");

	ofstream encoded("encoded.txt");

	if (to_encode.is_open()) {
		while (!to_encode.eof()) {
			to_encode.read(&c, sizeof(char));
			// Exit loop if end of file reached
			if (to_encode.eof()) {
				break;
			}
			ch = ("%c", c);
			symbol_position = search_name_in_list(ASCII_SYMBOLS, ch, 128);
			encoded << ASCII_CODES[symbol_position];
		}
	}
	to_encode.close();
	encoded.close();
}


// Takes encoded file and outputs a new decoded file that has the same content as the original read file
// Converts 7 bits into a string and uses a binary tree search to search for the proper character
void decode_file()
{
	string binary_tree[255];
	create_binary_tree(binary_tree);

	char bit;
	int code_position;
	int i = 0;
	string code_string;

	ifstream to_decode("encoded.txt");
	ofstream decoded("decoded.txt");
	if (to_decode.is_open()) {
		while (!to_decode.eof()) {
			// Read 7 bits and convert them into a string
			for (i = 0; i < 7; i++) {
				to_decode.read(&bit, sizeof(char));
				code_string += ("%c", bit);
			}
			// Exit loop if end of file is reached
			if (to_decode.eof()) {
				break;
			}
			// Use bit string to find next character using binary tree searching
			decoded << search_tree(binary_tree, 7 ,code_string);
			code_string = "";
		}
		to_decode.close();
		decoded.close();
	}
}

int main()
{
	ASCII_Table();

	encode_file();

	decode_file();

}
