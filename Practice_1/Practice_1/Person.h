#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include<vector>
using namespace std;

class Person
{
public:
	Person();
	~Person();
	Person(string Client_name, string Client_address) :name(Client_name), address(Client_address) {};
	Person(istream &is) { read(is, *this); }
	void Show_info();
	//类内定义函数
	//*************7.5
	//返回姓名地址的函数，只可访问，不可修改
	string getname() const { return name; }
	string getaddress() const { return address; }
	//7.22
	string& setname() { return name; }
	string& setaddress() { return address; }
private:
	string name;
	string address;//内部变量

	friend istream& read(istream& is, Person &person);
	friend ostream& print(ostream &os, const Person &person);
};

//**************7.9
istream& read(istream& is, Person &person) {
	is >> person.setname() >> person.setaddress();
	return is;
}

ostream& print(ostream &os, const Person &person) {
	os << person.getaddress() << '  '<< person.getaddress();
	return os;
}

#endif // PERSON_H

