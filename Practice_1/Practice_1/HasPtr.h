#pragma once
#include <string>
#include <vector>

//类指针的HasPtr

class HasPtr
{
public:
	//用于值类型类
	//friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& s1, const HasPtr& s2);
	friend void show(std::vector<HasPtr>&);

public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	~HasPtr();

	//指针指向新内存
	HasPtr(const HasPtr& HP) :ps(HP.ps), i(HP.i), use(HP.use) { ++*use; }
	//变量的声明不占用内存，不是 或者单独释放其中一个？

	//指针指向同一个内存
	HasPtr& operator=(const HasPtr& );


private:
	std::string *ps;
	int i;
	
	std::size_t *use;
};

