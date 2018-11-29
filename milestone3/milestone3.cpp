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

// Creates a new node for huffman tree
// Must be called for each entry in huffman code array
void create_node(TREE_NODE* r, string code)
{
	int code_position = search_name_in_list(HUFFMAN_CODES, code, 128);

	TREE_NODE* next_node;
	TREE_NODE* current_node = r;

	// Reads huffman codes and places symbols in tree
	// Creates new nodes as needed to prevent unnecessary memory allocation
	for (int i = 0; i < code.length(); i++) {
		string bit = code.substr(i, 1);
		if (bit == "0") {
			if (current_node->left_child == NULL) {
				next_node = new TREE_NODE;
				current_node->left_child = next_node;
			}
			current_node = current_node->left_child;
		}
		else {
			if (current_node->right_child == NULL) {
				next_node = new TREE_NODE;
				current_node->right_child = next_node;
			}
			current_node = current_node->right_child;
		}
	}
	current_node->node_value = ASCII_SYMBOLS[code_position];
}


// Takes .txt file and outputs a new encoded file that contains huffman code
// Uses search_name_in_list function to compare position of each character read to huffman code values

void encode_file()
{
	int symbol_position;
	char c;
	string ch;

	// Change this file name to read a different file
	ifstream to_encode("macbeth-from-mit-dot-edu.txt");

	ofstream encoded("macbeth.huffman");

	if (to_encode.is_open()) {
		while (!to_encode.eof()) {
			to_encode.read(&c, sizeof(char));
			// Exit loop if end of file reached
			if (to_encode.eof()) {
				break;
			}
			ch = c;
			symbol_position = search_name_in_list(ASCII_SYMBOLS, ch, 128);
			encoded << HUFFMAN_CODES[symbol_position];
		}
	}
	to_encode.close();
	encoded.close();
}

// Takes encoded .txt file and outputs a new decoded file that has the same content as the original read file
// Reads bits from encoded file until it hits a NULL pointer in the tree and outputs each character sequentially
void decode_file()
{
	char c;
	string bit;	

	TREE_NODE* root = new TREE_NODE;

	for (int i = 0; i < 128; i++) {
		create_node(root, HUFFMAN_CODES[i]);
	}
	TREE_NODE* element = root;

	ifstream to_decode("macbeth.huffman");
	ofstream decoded("macbeth.huffman.decoded");

	if (to_decode.is_open()) {
		// Read all bits from encoded file and decode them into characters
		while (!to_decode.eof()) {
			to_decode.read(&c, sizeof(char));
			bit = c;
			if (bit == "0") {
				element = element->left_child;
			}
			else if (bit == "1") {
				element = element->right_child;
			}
				
			// Exit loop if end of file is reached
			if (to_decode.eof()) {
				break;
			}
			// Print character to file if NULL pointer reached and reset element for next character
			if (element->left_child == NULL || element->right_child == NULL){
				decoded << element->node_value;
				element = root;
			}
		}
		to_decode.close();
		decoded.close();
	}
}

int main() {
	ASCII_and_Huffman_Table();

	encode_file();
	
	decode_file();

	return 0;
}