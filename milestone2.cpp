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

