// Finn Nguyen
// CPSC 301-01 
// Tues-Thurs: 10-12:50pm 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "person.h"
using namespace std;

void readData(vector<Person> &employees);
void getCompanies(vector<string> &companyNames, vector<Person> &employees);
void printHighestPaid(vector<Person> &employees);
void separateAndSave(vector<string> &companyNames, vector<Person> &employees);

int main()
{
	vector<Person> employees;
	vector<string> companyNames;

	readData(employees);
	getCompanies(companyNames, employees);
	printHighestPaid(employees);
	separateAndSave(companyNames, employees);

	return 0;
}

void readData(vector<Person> &employees)
{
	ifstream fin;
	Person p;

	fin.open("input.txt");

	if (!fin)
	{
		cout << "Error: could not open file 'input.txt'" << endl;
		return;
	}

	while (fin >> p)
	{
		employees.push_back(p);
	}

	fin.close();
}

void getCompanies(vector<string> &companyNames, vector<Person> &employees)
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		size_t j;

		for (j = 0; j < companyNames.size(); j++)
		{
			if (companyNames[j] == employees[i].getCompanyName())
				break;
		}

		if (j == companyNames.size())
			companyNames.push_back(employees[i].getCompanyName());
	}
}

void printHighestPaid(vector<Person> &employees)
{
	size_t i = 0;

	if (employees.size() == 0)
		return;

	for (size_t j = 1; j < employees.size(); j++)
	{
		if (employees[j].totalPay() > employees[i].totalPay())
			i = j;
	}

	cout << fixed << showpoint << setprecision(2);

	cout << "Highest paid: " << employees[i].fullName() << endl;
	cout << "Employee ID: " << employees[i].getEmployeeId() << endl;
	cout << "Employer: " << employees[i].getCompanyName() << endl;
	cout << "Total Pay: $" << employees[i].totalPay() << endl;
}

void separateAndSave(vector<string> &companyNames, vector<Person> &employees)
{
	for (size_t i = 0; i < companyNames.size(); i++)
	{
		string filename = companyNames[i] + ".txt";
		ofstream fout;
		float total = 0.0;

		fout.open(filename.c_str());

		if (!fout)
		{
			cout << "Error: could not open file '" << filename << "'" << endl;
			continue;
		}

		for (size_t j = 0; j < employees.size(); j++)
		{
			if (employees[j].getCompanyName() == companyNames[i])
			{
				fout << employees[j] << endl;
				total += employees[j].totalPay();
			}
		}

		fout << fixed << showpoint << setprecision(2);
		fout << "Total $" << total << endl;

		fout.close();
	}
}
