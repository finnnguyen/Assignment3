// Finn Nguyen
// CPSC 301-01 
// Tues-Thurs: 10-12:50pm 

#include <iomanip>
#include "person.h"

Person::Person()
{
}

void Person::setFirstName(string fName)
{
	firstName = fName;
}

string Person::getFirstName()
{
	return firstName;
}

void Person::setLastName(string lName)
{
	lastName = lName;
}

string Person::getLastName()
{
	return lastName;
}

void Person::setEmployeeId(int id)
{
	employeeID = id;
}

int Person::getEmployeeId()
{
	return employeeID;
}

void Person::setCompanyName(string coName)
{
	companyName = coName;
}

string Person::getCompanyName()
{
	return companyName;
}

void Person::setPayRate(float rate)
{
	payRate = rate;
}

float Person::getPayRate()
{
	return payRate;
}

void Person::setHoursWorked(float hours)
{
	hoursWorked = hours;
}

float Person::getHoursWorked()
{
	return hoursWorked;
}

float Person::totalPay()
{
	float total = hoursWorked*payRate;
	
	total = (int)(total*100)/100.0;

	return total;
}

string Person::fullName()
{
	return firstName + " " + lastName;
}

ostream& operator<<(ostream& os, Person& p)
{
	os << fixed << showpoint << setprecision(2);
	os << left << setw(10) << p.firstName << " "
		<< setw(10) << p.lastName << " "
		<< right << setw(5) << p.employeeID << " "
		<< left << setw(10) << p.companyName << " $"
		<< p.totalPay();
	return os;
}

istream& operator>>(istream& is, Person& p)
{
	is >> p.firstName >> p.lastName >> p.employeeID >> p.companyName 
		>> p.hoursWorked >> p.payRate;
	return is;
}

