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

void encode_file()
{
	int symbol_position;
	char c;
	string ch;
	
	ifstream encode("char_text.txt");
	ofstream encoded("encoded.txt");

	if (encode.is_open()) {
		while (!encode.eof()) {
			encode.read(&c, sizeof(char));
			ch = ("%c", c);
			symbol_position = search_name_in_list(ASCII_SYMBOLS, ch, 128);
			encoded << ASCII_CODES[symbol_position];
		}
	}
	encode.close();
	encoded.close();
}


void decode_file()
{
	char bit;
	int code_position;
	int i = 0;
	string code_string;


	ifstream decode("encoded.txt");
	ofstream decoded("decoded.txt");
	if (decode.is_open()) {
		while (!decode.eof()) {
			for (i = 0; i < 7; i++) {
				decode.read(&bit, sizeof(char));
				code_string += ("%c", bit);
			}
			code_position = search_name_in_list(ASCII_CODES, code_string, 128);
			decoded << ASCII_SYMBOLS[code_position];
			code_string = "";
		}
		decode.close();
		decoded.close();
	}
}

int main()
{
	ASCII_Table();
	
	encode_file();

	decode_file();

}
