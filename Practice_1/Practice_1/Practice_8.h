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
	is.clear();//对流进行置位的函数
	return is;
}

void func8_4()
{
	/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
	string infile = "1.txt";//代表文件名
	vector<string> vec;//声明一个vector
	ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据
	if (in)//检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		while (getline(in, buf))//每行独立输入的方法，利用getline
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
	/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
	string infile = "1.txt";//代表文件名
	vector<string> vec;//声明一个vector
	ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据
	if (in)//检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		istringstream record;
		while (getline(in, buf))//每行独立输入的方法，利用getline
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
	/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
	string infile = "1.txt";//代表文件名
	vector<string> vec;//声明一个vector
	ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据
	if (in)//检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		while (in>>buf)//每行独立输入的方法，利用getline
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
	/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
	string infile = "1.txt";//代表文件名
	vector<string> vec;//声明一个vector
	ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据
	if (in)//检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		while (in >> buf)//每行独立输入的方法，利用getline
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
	COUTSTR("3:无ofstream::app将会清空原本文件数据")
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

//badbit :流已崩溃
//eofbit :流达到了文件结束位置
//failbit ：IO操作失败