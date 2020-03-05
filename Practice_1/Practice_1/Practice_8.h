#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

//8.1.2
istream& func(istream &is)
{
	string mm;
	while (is >> mm)
		cout << mm << endl;
	is.clear();//����������λ�ĺ���
	return is;
}

void func8_4()
{
	/*�����ļ�������open��close������֮��������򿪶�����дģʽ*/
	string infile = "1.txt";//�����ļ���
	vector<string> vec;//����һ��vector
	ifstream in(infile);//ifstream������һ��������in(�ļ���)��������ʼ�����ļ��ж�ȡ����
	if (in)//����ļ��Ķ�ȡ�Ƿ�ɹ�,�������õ�ϰ�ߣ�
	{
		string buf;
		while (getline(in, buf))//ÿ�ж�������ķ���������getline
		{
			istringstream record(buf);
			func(record);
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << infile << endl;
	}
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
		istringstream record(*i);
		func(record);
	}
	return;
}


void func8_11()
{
	/*�����ļ�������open��close������֮��������򿪶�����дģʽ*/
	string infile = "1.txt";//�����ļ���
	vector<string> vec;//����һ��vector
	ifstream in(infile);//ifstream������һ��������in(�ļ���)��������ʼ�����ļ��ж�ȡ����
	if (in)//����ļ��Ķ�ȡ�Ƿ�ɹ�,�������õ�ϰ�ߣ�
	{
		string buf;
		istringstream record;
		while (getline(in, buf))//ÿ�ж�������ķ���������getline
		{
			record.str(buf);
			func(record);
			record.clear();
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << infile << endl;
	}
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;

	}
	return;
}


void func8_5()
{
	/*�����ļ�������open��close������֮��������򿪶�����дģʽ*/
	string infile = "1.txt";//�����ļ���
	vector<string> vec;//����һ��vector
	ifstream in(infile);//ifstream������һ��������in(�ļ���)��������ʼ�����ļ��ж�ȡ����
	if (in)//����ļ��Ķ�ȡ�Ƿ�ɹ�,�������õ�ϰ�ߣ�
	{
		string buf;
		while (in>>buf)//ÿ�ж�������ķ���������getline
		{
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << infile << endl;
	}
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
	}
	return;
}	  

void func8_8()
{
	/*�����ļ�������open��close������֮��������򿪶�����дģʽ*/
	string infile = "1.txt";//�����ļ���
	vector<string> vec;//����һ��vector
	ifstream in(infile);//ifstream������һ��������in(�ļ���)��������ʼ�����ļ��ж�ȡ����
	if (in)//����ļ��Ķ�ȡ�Ƿ�ɹ�,�������õ�ϰ�ߣ�
	{
		string buf;
		while (in >> buf)//ÿ�ж�������ķ���������getline
		{
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << infile << endl;
	}
	COUTSTR("1")
	for (auto i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
	}
	in.close();
	COUTSTR("2")
	ofstream out2(infile, ofstream::app);
	out2.close();
	COUTSTR("3:��ofstream::app�������ԭ���ļ�����")
	ofstream out(infile);
	out.close();



	return;
}


int Practice_8() {
	COUTSTR("Practice_8:")
	//func(cin);
	//func8_4();
	func8_11();
	//func8_5();
	//func8_8();
	return 0;
}

//badbit :���ѱ���
//eofbit :���ﵽ���ļ�����λ��
//failbit ��IO����ʧ��