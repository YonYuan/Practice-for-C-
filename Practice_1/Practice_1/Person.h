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
	//���ڶ��庯��
	//*************7.5
	//����������ַ�ĺ�����ֻ�ɷ��ʣ������޸�
	string getname() const { return name; }
	string getaddress() const { return address; }
	//7.22
	string& setname() { return name; }
	string& setaddress() { return address; }
private:
	string name;
	string address;//�ڲ�����

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

