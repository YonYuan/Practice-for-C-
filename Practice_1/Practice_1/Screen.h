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
	//friend void Window_mgr::clear(ScreenIndex);//��Ҫ�����βΣ�����ᱻ����Ϊ��������

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
//7.33 ��ͷ�ļ������������Ķ�������������
Screen::pos Screen::size()const {
	return height * width;
}

#endif // !SCREEN_H



/*
c++ string::size_type���
	string::size_type����
	���߼���������size()��Ա�����ƺ�Ӧ�÷���������ֵ������2.2�ڡ����顱���������޷�������������ʵ�ϣ�size�������ص���string::size_type���͵�ֵ��
	������Ҫ������������һЩ���͡�string�����ͺ�������������Ͷ�������һЩ������ͣ�companion types������Щ�������ʹ�ÿ����͵�ʹ���ǻ����޹ص�(machine-independent)��
	size_type������Щ��������е�һ�֡�������Ϊ��unsigned�ͣ�unsigned int��unsigned long��������ͬ�ĺ��壬���ҿ��Ա�֤�㹻��ɴ洢����string����ĳ��ȡ�
	Ϊ��ʹ����string���Ͷ����size_type���ͣ�����Ա��������������������˵����ʹ�õ�size_type��������string�ඨ��ġ�
	�κδ洢string��size��������ı�������Ϊstring::size_type���͡��ر���Ҫ���ǣ���Ҫ��size�ķ���ֵ����һ��int������
	��Ȼ���ǲ�֪��string::size_type��ȷ�����ͣ�������֪������unsigned�ͣ�2.1.1�ڣ�����������һ�ָ������������ͣ�����unsigned�����ܱ�ʾ���������ֵ�ȶ�Ӧ��signedҪ��һ����
	�����ʵ����size_type�洢��string������int���ܴ洢��������
	ʹ��int��������һ�������ǣ���Щ������int�����ı�ʾ��Χ̫С�������޷��洢ʵ�ʲ�������string����������16λint�͵Ļ����ϣ�int���ͱ������ֻ�ܱ�ʾ32767���ַ���string����
	��������һ���ļ����ݵ�string�������׾ͻᳬ��������֡���ˣ�Ϊ�˱������������һ��string����size���ȫ�ķ�������ʹ�ñ�׼������string:: size_type��
	string�����ͺ�������������Ͷ�������һЩ�������ͣ�companion type����ͨ����Щ�������ͣ������͵�ʹ�þ��ܺͻ����޹أ�machine-independent����string::size_type����Ϊunsigned�ͣ����Ա�֤�㹻��Ĵ洢string����ĳ��ȡ�
	ע�⣬�κδ洢string��size��������ı�������Ϊstring::size_type���͡����䲻�ܰ�size�ķ���ֵ����һ��int����������Ϊsize���ص���һ��unsigned���ͣ���int��signed���͡�size�ܱ��Ĵ�С��int��2������
����������string::size_type �ȼ��� unsigned ��ʹ�����Ϊ�洢�ַ����Ĵ�С
*/