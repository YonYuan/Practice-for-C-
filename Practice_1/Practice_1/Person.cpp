#include "pch.h"
#include "Person.h"


Person::Person()
{
}


Person::~Person()
{
}

inline void Person::Show_info()
{
	cout << name << "'s" << " address is " << address << endl;
}
