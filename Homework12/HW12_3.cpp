#include <iostream>
#include <string>
using namespace std;

// R7.27

// Design a structure type Person that contains the name of a person
// and pointers to the person’s father and mother. Write statements 
// that define a structure value for yourself and your parents, 
// correctly establishing the pointer links. (Use nullptr for your parents’ parents.)

int main()
{
	struct Person {
		string name = "";
		Person* father = NULL;
		Person* mother = NULL;
	};

	Person* me = new Person;
	Person* mom = new Person;
	Person* dad = new Person;
	me->name = "Jason";
	me->father = dad;
	me->mother = mom;

	dad->name = "David";
	mom->name = "Diane";

	cout << me->name;
}