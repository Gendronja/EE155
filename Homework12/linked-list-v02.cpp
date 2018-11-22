#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>

using namespace std;


struct node {
   int id;
   node* next;
};


void print_list(node* list){
int j = 0;
node * element;
element = list;
while(element!=NULL){
   cout << "List element #" << j << ": id = " << element->id << endl;
   element = element->next;
   j++;
}
}

int main() {
node* my_list;
node* element; 
int i;

// create the first element in the list 
// and assign its id value 0 and its next pointer value NULL
my_list = new node;
my_list->id = 0;
my_list->next = NULL;

// create the nex five elements and assign id values
element = my_list;
for(i = 1; i < 5; i++){
   element->next = new node;
   element = element->next;
   element->id = i;
} 
element->next = NULL;

cout << "The original list" << endl;
// traverse the original list from the begining to end and print id values
print_list(my_list);

// insert a new element with id value 5 after the first element with id value 4; if there is no element with id value 4, then add the new element at the end of the list
element = my_list;
while((element->id!=4)&&(element->next!=NULL)){
   element = element->next;
}
node* new_node;
new_node = new node;
new_node->id = 5;
new_node->next = element->next;
element->next = new_node;


int k, m;
cout << "Enter a positive integer" << endl;
cin >> k;
cout << "Enter an integer id value" << endl;
cin >> m;

// insert a new element with id value m BEFORE the element whose id value == k; if there is no element with id value == k, then add such a new element at the start of the list

// INSERT YOUR CODE HERE


cout << "The extended list" << endl;
// traverse the extended list from the begining to end and print id values
print_list(my_list);

}
