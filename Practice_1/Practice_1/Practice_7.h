#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Sales_data.h"
using namespace std;

//***********7.1
//知识点1：构造函数—特殊的成员函数，用来控制对象的初始化过程。无返回类型，可重载，不能被声明为const.
//知识点2：若无，则有默认的构造函数，是编译器自己隐式的定义的。又称合成的默认构造函数。
//知识点3：某些类是不能使用默认的构造函数的，以下三个原因：
//1：在未声明任何构造函数的前提下，类内对象的初始化将不受控制
//2：合成的默认构造函数可能会造成不必要的错误，如若没有类内初始值来初始化成员，可能这些成员将是未定义的。
//3：如果类中包含了一个其他类类型的成员，且这个成员的类型没有默认构造函数，那么编译器将无法初始化该对象。
//所以，在撰写类的时候，最好定义一个自己的构造函数。

int Practice_7() {
	//Sales_data total;
	//默认构造函数测试7.11
	Sales_data testConstructor1;
	Sales_data testConstructor2("testConstructor2_bookNo");
	Sales_data testConstructor3("testConstructor2_bookNo", 12, 30);
	Sales_data testConstructor4(cin);
	Sales_data total(cin);
	if (cin) {
		//7.13
		Sales_data trans(cin);
		do
		{
			if (total.isbn() == trans.isbn()) {
				//total.units_sold += trans.units_sold;
				//total.revenue += trans.revenue;
				//***********7.3
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		} while (read(cin, trans));
		print(cout, total) << endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
