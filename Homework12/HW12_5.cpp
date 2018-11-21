#include <iostream>
#include <string>
using namespace std;


//Write a program which(a) defines a new structure called COURSE
//with two fields, a string for course_number and an int for num_of_units.
//The main program asks the user to input the number of
//courses she / he is taking this semester.For each course, the main
//program then prompts the user to input the course number(without any spaces within, e.g., EE155)
//and the number of units. Right after it reads the information for each course into the corresponding
//fields of a variable my_course of type COURSE, the main program calls a function and passes the variable 
//my_course to print the values in both its fields.

struct COURSE {
	string course_number = "";
	int num_of_units = 0;
};

void print_course(COURSE my_course)
{
	cout << "Number of units: " << my_course.num_of_units << endl;
	cout << "Course number: " << my_course.course_number << endl;
}

int main()
{

	COURSE my_course;

	cout << "Please input the number of units you are taking this semester" << endl;
	cin >> my_course.num_of_units;
	cout << "Please input the course number (without any spaces within, e.g., EE155)" << endl;
	cin >> my_course.course_number;

	print_course(my_course);

	return 0;
}