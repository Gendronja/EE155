#include <iostream>
#include <fstream>
#include <bitset>
#include <string>
using namespace std;

/*
You are provided with three arrays ASCII_CODES, ASCII_SYMBOLS, and HUFFMAN_CODES.
ASCII_CODES: Array or list of valid ASCII codes.
ASCII_SYMBOLS: Array or list of ASCII symbols for each of valid ASCII code.
HUFFMAN_CODES: Array or list of Huffman Codes for the 128 symbols (this Huffman Code was optimized for Shakespere's Macbeth, obtained from mit.edu).

*/

struct TREE_NODE {
	string node_value;
	TREE_NODE* left_child = NULL;
	TREE_NODE* right_child = NULL;
};

// Begin: Do NOT modify
string ASCII_CODES[128];
string ASCII_SYMBOLS[128];
string HUFFMAN_CODES[128];

void ASCII_and_Huffman_Table()
{
	// This function fills ASCII_CODES, ASCII_SYMBOLS, HUFFMAN_CODES  arrays.
	ifstream infile("huffman-code.txt");
	int j;
	if (infile.is_open()) {
		for (int i = 0; i < 128; i++) {
			ASCII_SYMBOLS[i] = char(i);
			ASCII_CODES[i] = bitset < 7 >(i).to_string();
			infile >> j >> HUFFMAN_CODES[i];
			if (i != j) {
				cout << "Warning: Huffman-code file seems out of step with ASCII codes list" << endl;
			}
		}
	} // if()	
	infile.close();
}
// End: Do NOT modify

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

void create_tree(TREE_NODE*& r, int n)
{
	if (n == 0) {
		r = NULL;
	}
	else {
		r = new TREE_NODE;
		create_tree(r->left_child, n - 1);
		create_tree(r->right_child, n - 1);
	}
}

void input_values(TREE_NODE*& element, string code, string value)
{
	int n = code.length();
	while (n > 0) {
		if (code.substr(n - 1, 1) == "0") {
			element = element->left_child;
		}
		else {
			element = element->right_child;
		}
		n--;
	}
	// Inputs value after reaching end of code, and makes left/right childs point to NULL
	element->node_value = value;

	//element->left_child = NULL;
	//element->right_child = NULL;
}

/*
string search_tree(TREE_NODE*& element, string bit)
{
	if (bit == "0") {
		element = element->left_child;
	}
	else {
		element = element->right_child;
	}
	
		return (element->node_value);
}
*/

// Takes .txt file and outputs a new encoded file that contains huffman code
// Uses search_name_in_list function to compare position of each character read to huffman code values

void encode_file()
{
	int symbol_position;
	char c;
	string ch;

	// Change this file name to read a different file
	ifstream to_encode("macbeth-from-mit-dot-edu.txt");

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
			encoded << HUFFMAN_CODES[symbol_position];
		}
	}
	to_encode.close();
	encoded.close();
}

// Takes encoded file and outputs a new decoded file that has the same content as the original read file
// Converts 7 bits into a string and uses a binary tree search to search for the proper character
void decode_file()
{
	char c;
	string bit;	

	TREE_NODE* root;
	create_tree(root, 20);
	TREE_NODE* element;

	for (int i = 0; i < 128; i++) {
		element = root;
		input_values(element, HUFFMAN_CODES[i], ASCII_SYMBOLS[i]);
	}
	element = root;

	ifstream to_decode("encoded.txt");
	ofstream decoded("decoded.txt");

	if (to_decode.is_open()) {
		while (!to_decode.eof()) {
			// Read bits until function stops
			while (1) {
				to_decode.read(&c, sizeof(char));
				bit = c;
				if (bit == "0") {
					element = element->left_child;
				}
				else {
					element = element->right_child;
				}
				if (element->right_child == NULL || element->left_child == NULL) {
					break;
				}
			}
				
			// Exit loop if end of file is reached
			if (to_decode.eof()) {
				break;
			}

			//cout << element->node_value << endl;
			decoded << element->node_value;
			element = root;
		}
		to_decode.close();
		decoded.close();
	}
}

int main() {
	ASCII_and_Huffman_Table();
	//for (int i = 0; i < 128; i++) {
	//	cout << i << ": " << ASCII_CODES[i] << " " << HUFFMAN_CODES[i] << " " << ASCII_SYMBOLS[i] << endl;
	//}
	encode_file();
	decode_file();

	return 0;
}