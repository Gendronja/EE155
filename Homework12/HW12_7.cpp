#include <iostream>
#include <string>
using namespace std;

//Write a program to create a complete binary tree using structures and pointers. (a)Each node in the
//tree must be a variable of a new type TREE_NODE which has three fields, a field called node_value
//which is of type string, and two fields called left_child and right_child which are of type
//TREE_NODE*. (b)The root of your tree must be always accessible via a pointer variable tree_root of
//appropriate type. (c)Your complete binary tree must have four leaf nodes whose node_value fields
//contain strings AA, BB, CC, and DD, respectively.For each leaf node, the fields left_child and
//right_child must have values NULL. (d)Every non - leaf node in the tree must have the field
//node_value equal to string EMPTY; also, its fields left_child and right_child must point to the nodes
//that are its left and right child, respectively. (e)Write a function that takes tree_root as an argument,
//and prints all three field values of every node in the tree in the order we numbered the nodes of binary
//trees in our lectures. Use this function to print your binary tree.


struct TREE_NODE {
	string node_value = "";
	TREE_NODE* left_child = NULL;
	TREE_NODE* right_child = NULL;
};

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
	element->node_value = value;
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

void print_tree(TREE_NODE* element, string code)
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
	cout << "Value: " << element->node_value << endl;
	cout << "left child: " << element->left_child << endl;
	cout << "right_child: " << element->right_child << endl;
}

int main()
{
	string codes[4] = {
		"00",
		"10",
		"01",
		"11"
	};

	string values[4] = {
		"AA",
		"BB",
		"CC",
		"DD"
	};

	string print_codes[7] = {
		"",
		"0",
		"1",
		"00",
		"10",
		"01",
		"11"
	};


	TREE_NODE* tree_root;;

	create_tree(tree_root, 3);	
	
	TREE_NODE* element;
	
	for (int i = 0; i < 4; i++) {
		element = tree_root;
		input_values(element, codes[i], values[i]);
	}
	
	for (int i = 0; i < 7; i++) {
		print_tree(tree_root, print_codes[i]);
	}
	
}