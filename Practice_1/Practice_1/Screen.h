#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

class Screen;


//7.27
class Screen
{
public:
	using pos = std::string::size_type;

	Screen();
	~Screen();
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {};
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' ') {};

	friend class Window_mgr;
	//friend void Window_mgr::clear(ScreenIndex);//不要带上形参，否则会被误认为函数声明

	char get() const { return contents[cursor]; }
	char get(pos ht, pos wd)const;	
	Screen &move(pos r, pos c);
	Screen &set(char);
	Screen &set(pos, pos, char);
	Screen &display(std::ostream &os){do_display(os); return *this;}
	const Screen &display(std::ostream &os) const{do_display(os); return *this;}

	pos size()const;

	void some_member() const;


private:
	string contents;
	pos cursor;
	pos height = 0, width = 0;
	mutable size_t access_ctr;

private:
	void do_display(std::ostream &os) const { os << contents; }

};


inline                   // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c;    // move cursor to the column within that row
	return *this;        // return this object as an lvalue
}

inline void Screen::some_member() const
{
	++access_ctr;
}

inline char Screen::get(pos r, pos c) const // declared as inline in the class
{
	pos row = r * width;      // compute row location
	return contents[row + c]; // return character at the given column
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c; // set the new value at the current cursor location
	return *this;         // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  // set specified location to given value
	return *this;                  // return this object as an lvalue
}
inline
//7.33 在头文件中声明函数的定义务必设成内联
Screen::pos Screen::size()const {
	return height * width;
}

#endif // !SCREEN_H



/*
c++ string::size_type详解
	string::size_type类型
	从逻辑上来讲，size()成员函数似乎应该返回整型数值，或如2.2节“建议”中所述的无符号整数。但事实上，size操作返回的是string::size_type类型的值。
	我们需要对这种类型做一些解释。string类类型和许多其他库类型都定义了一些伙伴类型（companion types）。这些伙伴类型使得库类型的使用是机器无关的(machine-independent)。
	size_type就是这些伙伴类型中的一种。它定义为与unsigned型（unsigned int或unsigned long）具有相同的含义，而且可以保证足够大可存储任意string对象的长度。
	为了使用由string类型定义的size_type类型，程序员必须加上作用域操作符来说明所使用的size_type类型是由string类定义的。
	任何存储string的size操作结果的变量必须为string::size_type类型。特别重要的是，不要把size的返回值赋给一个int变量。
	虽然我们不知道string::size_type的确切类型，但可以知道它是unsigned型（2.1.1节）。对于任意一种给定的数据类型，它的unsigned型所能表示的最大正数值比对应的signed要大一倍。
	这个事实表明size_type存储的string长度是int所能存储的两倍。
	使用int变量的另一个问题是，有些机器上int变量的表示范围太小，甚至无法存储实际并不长的string对象。如在有16位int型的机器上，int类型变量最大只能表示32767个字符的string对象。
	而能容纳一个文件内容的string对象轻易就会超过这个数字。因此，为了避免溢出，保存一个string对象size的最安全的方法就是使用标准库类型string:: size_type。
	string类类型和许多其他库类型都定义了一些配套类型（companion type）。通过这些配套类型，库类型的使用就能和机器无关（machine-independent）。string::size_type定义为unsigned型，可以保证足够大的存储string对象的长度。
	注意，任何存储string的size操作结果的变量必须为string::size_type类型。尤其不能把size的返回值赋给一个int变量。（因为size返回的是一个unsigned类型，而int是signed类型。size能表达的大小是int的2倍）。
综上所述：string::size_type 等价于 unsigned ，使用情况为存储字符串的大小
*/