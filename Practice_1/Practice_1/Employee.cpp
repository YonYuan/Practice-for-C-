#include "pch.h"
#include "Employee.h"

int Employee::si_empID = 0;

Employee::Employee():empID(si_empID)
{
	++si_empID;
}

Employee::
Employee(const std::string & s_empName):empName(s_empName),empID(si_empID)
{
	++si_empID;
}


Employee::~Employee()
{
}
