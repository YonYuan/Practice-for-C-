#pragma once
#include <string>
#include <iostream>
class Employee
{
public:
	Employee();
	Employee(const std::string& s_empName);
	~Employee();

	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&)= delete;

	void printID() const { std::cout << empID << " : " << empName << std::endl; }

private:
	std::string empName;
	int empID;

private:
	static int si_empID;
};

