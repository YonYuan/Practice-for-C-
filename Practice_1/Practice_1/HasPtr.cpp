#include "pch.h"
#include "HasPtr.h"
#include <iostream>

using std::cout;
using std::endl;

//构造函数中，分配的动态内存对象，需要delete
HasPtr::~HasPtr()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	std::cout<<"调用析构函数，后销毁对象"<<std::endl;
}

HasPtr& HasPtr::operator=(const HasPtr & rhs)
{
	++*rhs.use;
	if (--*use == 0) {
		delete ps;//首先删除原内存
		delete use;
	}

	////临时值保证自赋值的意义
	//std::string *p = new std::string(*rhs.ps);//new返回的是指向分配好内存、创建了对象的指针
	//ps = p;

	ps = rhs.ps;
	//直接赋值导致两个指针同时指向相同底层内存，然后在析构时引发重复释放的错误，无论如何都尽量避免内置指针重复赋给相同的内存
	//使用引用计数器时则额外考虑

	i = rhs.i;
	use = rhs.use;
	return *this;
	// TODO: 在此处插入 return 语句
}

//重新定义的swap应用于值类型的类
//void swap(HasPtr &lhs, HasPtr &rhs)
//{
//
//	COUTSTR("do swap");
//	using std::swap;
//	swap(lhs.ps, rhs.ps);
//	swap(lhs.i, rhs.i);
//}

bool operator<(const HasPtr & s1, const HasPtr & s2)
{
	COUTSTR("do <");
	return *s1.ps < *s2.ps;
}

void show(std::vector<HasPtr>& vec)
{
	std::vector<HasPtr>::iterator it1 = vec.begin();
	for (it1; it1 != vec.end(); ++it1)
	{
		cout << *(it1->ps) << endl;
	}
}
