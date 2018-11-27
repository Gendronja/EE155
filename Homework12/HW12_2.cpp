#include <iostream>
#include <string>
using namespace std;

// R7.23
// Rewrite the statements in Section 7.8.2 so that the street address and employee structures are allocated on the free store.

struct Employee
{
	string name;
	StreetAddress* office;
	Employee* next_employee;
};

int main()
{
	StreetAddress accounting;
	accounting.house_number = 1729;
	accounting.street_name = "Park Avenue";

	Employee* employees;
	Employee* current_employee;
	
	employees = new Employee;
	employees->name = "Smith, Harry";
	employees->office = &accounting;
	employees->next_employee = new Employee;
	
	current_employee = employees->next_employee;
	current_employee->name = "Lee, Sally";
	current_employee->office = &accounting;
}