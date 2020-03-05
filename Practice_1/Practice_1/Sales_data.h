#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Sales_data {

public:
	//********7.11
	Sales_data() = default;
	//Sales_data():units_sold(0), revenue(0) {};//7.14
	Sales_data(const string &s) :bookNo(s) {};
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {};
	//Sales_data(const string &s):Sales_data(s, 0, 0) {};//委托构造函数的初始化赋值
	//Sales_data() :Sales_data(" ", 0, 0){}
	//Sales_data(std::istream &is = std::cin) { read(is, *this); }//将默认实参直接赋予变量即可
	//当提供默认实参时，视为默认构造函数 并对值进行了初始化，所以不能有多个类似的构造函数同时进行初始化，发生默认构造函数重复定义的错误
	//7.12
	Sales_data(std::istream &is) { read(is, *this); };
	//***********7.2
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	bool compareIsbn(Sales_data data1, Sales_data data2);

private://     访问说明符的作用域是开始知道下一个访问说明符或者类结束。不想被使用该类的程序看到的代码细节，都要private.
	//7.18：封装实现了类的接口和实现的分离，隐藏了类的实现细节，用户只能接触到类的接口。
	//	优点：
	//	隐藏类的实现细节；
	//	让使用者只能通过程序规定的方法来访问数据；
	//	可以方便的加入存取控制语句，限制不合理操作；
	//	类自身的安全性提升，只能被访问不能被修改；
	//	类的细节可以随时改变，不需要修改用户级别的代码；

	//***********7.3
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold;
	double revenue;
	//7.21
	friend istream& read(istream &is, Sales_data &item);
	friend ostream& print(ostream &os, const Sales_data &item);
};
