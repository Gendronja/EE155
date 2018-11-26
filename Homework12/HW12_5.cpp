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

void print_course(COURSE* my_course)
{
	cout << "Course number: " << my_course -> course_number << endl;
	cout << "Number of units: " << my_course->num_of_units << endl;
}

void fill_info(int number_of_courses)
{
	COURSE* my_course;
	for (int i = 0; i < number_of_courses; i++) {

		my_course = new COURSE;

		cout << "Please input a course number: " << endl;
		cin >> my_course->course_number;

		cout << "Please input the number of units this course is worth" << endl;
		cin >> my_course->num_of_units;

		print_course(my_course);
	}
}

int main()
{
	int number_of_courses;

	cout << "Please input the number of courses you are taking" << endl;
	cin >> number_of_courses;
	
	fill_info(number_of_courses);

	return 0;
}