#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>

using namespace std;

void func9_2() {
	COUTSTR("func9_2:");
	list<deque<int>> list92;
}

bool func9_4(vector<int>::iterator ibegin, vector<int>::iterator iend, int i) {
	while (ibegin != iend)
	{
		if (*ibegin == i)
		{
			return true;
		}
		else
		{
			++ibegin;
		}
	}
	return false;
}

void func9_4_2() {
	COUTSTR("func9_4:");
	vector<int> vec{ 5,6,7,8,9,10,11,12,13,14 };//必须事先指定这个大小，才知道end的指向
	int find_member;
	COUTSTR("cin a number to find:")
		cin >> find_member;
	if (func9_4(vec.begin(), vec.end(), find_member))
	{
		cout << "We have found it" << endl;
	}
	else
		cout << "Sorry,there is no " << find_member << " in the range" << endl;
}

vector<int>::iterator func9_5(vector<int>::iterator ibegin, vector<int>::iterator iend, int i) {
	while (ibegin != iend)
	{
		if (*ibegin == i)
		{
			return ibegin;
		}
		else
		{
			++ibegin;
		}
	}
	return iend;
}

void func9_5_2() {
	COUTSTR("func9_5:");
	vector<int> vec{ 5,6,7,8,9,10,11,12,13,14 };//必须事先指定这个大小，才知道end的指向
	int find_member;
	COUTSTR("cin a number to find:")
		cin >> find_member;
	if (func9_5(vec.begin(), vec.end(), find_member) != vec.end())
	{
		cout << "We have found it" << endl;
	}
	else
		cout << "Sorry,there is no " << find_member << " in the range" << endl;
}

void func9_11() {
	COUTSTR("func9_11:");
	vector<int> vec1;    // 0
	vector<int> vec2(10);    // 0
	vector<int> vec3(10, 1);  // 1
	vector<int> vec4{ 1,2,3,4,5 }; // 1,2,3,4,5
	vector<int> vec5(vec2); // same as other_vec
	vector<int> vec6(vec3.begin(), vec3.end()); // same as other_vec
	//9.13
	list<int> list1(10, 1);
	vector<double> vec7(list1.begin(), list1.end());
	vector<double> vec8;
	vec8.assign(list1.begin(), list1.end());
	for (auto a : vec7) {
		cout << a;
	}

}

void func9_14() {
	COUTSTR("func9_14:");

	//9.13
	list<const char*> list1{ "a","ab","abc" };
	vector<string> vecstr(list1.begin(), list1.end());
	vector<string> vecstr2s;
	vecstr2s.assign(list1.begin(), list1.end());
	for (auto a : vecstr) {
		cout << a;
	}
}

void func9_16() {
	COUTSTR("func9_16:");
	list<int> list1(7, 8);
	vector<int> vec2(7, 8);
	//创建的目标容器
	vector<int> vec1(list1.begin(), list1.end());
	vector<int> vec3(vec2.begin(), vec2.end() - 1);

	//验证正确性
	cout << (vec1 == vec2)
		<< (vec1 < vec2)
		<< (vec1 > vec3);
	return;
}

//向标准容器中添加元素的方法：
//
//1：push_back()		forward_list和array不支持
//
//2：push_font()		forward_list，array，deque支持
//
//3：emplace()			通过构造函数直接构造元素，所以参数列表可以直接用构造函数
//															
//4：insert()			vector，deque，list，string支持（耗时），forward_list有独立版本

void func9_18() {
	COUTSTR("func9_18:");
	deque<string> deque1;
	list<string> list1;
	string str;
	while (cin >> str)
	{
		list1.emplace_back(str);
		if (str == "break") {
			COUTSTR("break:")
				break;
		}
	}

	for (auto c : deque1) {
		cout << c;
	}

	return;
}

void func9_22() {//对容器的操作会改变指向容器的迭代器
	COUTSTR("func9_22:");
	vector<int> iv{ 1,2,3,4,5,6,7,8,9 };
	int some_val = 3;
	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	while (iter != mid)
		if (*mid == some_val) {
			mid = iv.insert(mid, 2 * some_val);
			iter = iv.begin();
		}
		else
			--mid;

	for (auto a : iv) {
		cout << a;
	}
	//验证正确性
	return;
}

void func9_24() {//对容器的操作会改变指向容器的迭代器
	COUTSTR("func9_24:");
	vector<int> vec1;
	int a = vec1.front();//terminating with uncaught exception of type std::out_of_range
	//int b = vec1[0];// Segmentation fault: 11
	//int c = vec1.at(0);
	//int d = *vec1.begin();//需要解引用
	//cout 
	//	<< a << " " 
	//	<< b << " " 
	//	<< c << " " 
	//	<< d << endl;
	//cout << c;
	return;
}

void func9_26() {//对容器的操作会改变指向容器的迭代器
	COUTSTR("func9_26:");
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	vector<int> vec1(ia, ia + 11);//拷贝操作
	list<int> list1(ia, ia + 11);

	vector<int>::iterator it1 = vec1.begin();//使用迭代器
	list<int>::iterator it2 = list1.begin();

	while (it1 != vec1.end())//删除操作
	{
		if ((*it1) % 2 == 0)
		{
			it1 = vec1.erase(it1);//将删除位置更新
		}
		else//若判断非偶数，则移到下一位置
		{
			++it1;
		}
	}

	while (it2 != list1.end())
	{
		if (*it2 % 2 != 0)
		{
			it2 = list1.erase(it2);//将删除位置更新
		}
		else//若判断非偶数，则移到下一位置
		{
			++it2;
		}
	}

	//验证结果
	vector<int>::iterator it3 = vec1.begin();//需要重新定义临时迭代器
	list<int>::iterator it4 = list1.begin();
	for (it3; it3 != vec1.end(); ++it3)
	{
		cout << *it3 << " ";
	}
	cout << endl;
	for (it4; it4 != list1.end(); ++it4)
	{
		cout << *it4 << " ";
	}

	return;
}

void func9_27() {
	COUTSTR("func9_27:");

	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	forward_list<int> forward_list1(ia, ia + 9);

	forward_list<int>::iterator it1 = forward_list1.begin();//第一个元素
	forward_list<int>::iterator it2 = forward_list1.before_begin();//首前元素

	while (it1 != forward_list1.end())//删除操作
	{
		if ((*it1) % 2 == 1)
		{
			it1 = forward_list1.erase_after(it2);//特殊操作erase_after,删除的是迭代器参数之后的参数，返回同erase()
		}
		else//若判断非偶数，则移到下一位置
		{
			it2 = it1;//将首前元素的标记置为第一个元素
			++it1;
		}
	}

	//验证结果
	forward_list<int>::iterator it4 = forward_list1.begin();
	for (it4; it4 != forward_list1.end(); ++it4)
	{
		cout << *it4 << " ";
	}

}

void func9_28(forward_list<string> &fstr, string str1oc, string str) {
	COUTSTR("func9_28:");

	forward_list<string>::iterator it1 = fstr.begin();//第一个元素
	forward_list<string>::iterator it2 = fstr.before_begin();//首前元素

	while (it1 != fstr.end())//删除操作
	{
		if (*it1 == str1oc)
		{
			it1 = fstr.insert_after(it1, str);//特殊操作erase_after,删除的是迭代器参数之后的参数，返回同erase()
			break;
		}
		else
		{
			forward_list<string>::iterator it_t = it1;//最后一个元素
			++it1;
			if (it1 == fstr.end())
			{
				it_t = fstr.insert_after(it_t, str);
			}
		}
	}
}

void func9_28_2() {

	//forward_list<string> list1{ "sad1", "sad2", "sad3", "sad4", "sad5", "sad6" };
	forward_list<string> list1{ "sad1", "sad2", "sad3", "sad4" };

	string a = "sad5";
	string b = "sad";

	func9_28(list1, a, b);

	forward_list<string>::iterator it1 = list1.begin();
	for (it1; it1 != list1.end(); ++it1)
	{
		cout << *it1 << " ";
	}

	return;
}

//容器(除array)有许多的删除元素的方法
//
//pop_back()			forward_list不支持
//
//pop_front()			vector和string不支持
//
//erase()
//
//clear()

void func9_29() {
	COUTSTR("func9_29:");
	forward_list<int> vi{ 1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin(), prev = vi.before_begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert_after(prev, *iter);
			advance(iter, 2);
			advance(prev, 2);
		}
		else
			iter = vi.erase_after(prev);
	}
	forward_list<int>::iterator it1 = vi.begin();
	for (it1; it1 != vi.end(); ++it1)
	{
		cout << *it1 << " ";
	}
}

void func9_32() {
	COUTSTR("func9_32:");
	forward_list<int> vi{ 1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin(), prev = vi.before_begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert_after(prev, *iter++);

			advance(iter, 2);
			advance(prev, 2);
		}
		else
			iter = vi.erase_after(prev);
	}
	forward_list<int>::iterator it1 = vi.begin();
	for (it1; it1 != vi.end(); ++it1)
	{
		cout << *it1 << " ";
	}
}

void func9_33() {
	COUTSTR("func9_33:");
	vector<int> vi{ 1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		++iter;
		vi.insert(iter, 42);
		++iter;
	}
	vector<int>::iterator it1 = vi.begin();
	for (it1; it1 != vi.end(); ++it1)
	{
		cout << *it1 << " ";
	}
}

void func9_34() {
	COUTSTR(__FUNCTION__);
	vector<int> vi{ 1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2)
		{
			iter = vi.insert(iter, 0);
			++iter;

		}
		++iter;
	}
	vector<int>::iterator it1 = vi.begin();
	for (it1; it1 != vi.end(); ++it1)
	{
		cout << *it1 << " ";
	}
}

void func9_38() {
	COUTSTR(__FUNCTION__);
	vector<int> vec1;
	int a;
	while (cin >> a)
	{
		vec1.push_back(a);
		cout << "vector的大小" << vec1.size() << endl;;
		cout << "vector的容量" << vec1.capacity() << endl;
	}
	return;
}

void func9_39() {
	COUTSTR(__FUNCTION__);
	vector<string> svec;
	svec.reserve(1024);
	string word;
	while (cin >> word) {
		svec.push_back(word);
	}
	svec.resize(svec.size() + svec.size() / 2);
	vector<string>::iterator it1 = svec.begin();
	for (it1; it1 != svec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
}

//reverse(n)函数，分配能容纳n个元素的内存。
//capacity()，返回容器的容量。
//resize改变size但不改变capacity 没法释放vector的内存
//reserve改变capacity 但只保证扩大会成功

void func9_41() {
	COUTSTR(__FUNCTION__);
	vector<char> vec1(6, 'a');
	string _string(vec1.begin(), vec1.end());//此时不是本节所介绍的特殊方法
	cout << _string << endl;
}

void func9_42() {
	COUTSTR(__FUNCTION__);
	string str;
	char str_t;
	str.reserve(100);
	while (cin >> str_t)
	{
		str.push_back(str_t);
	}
	cout << str << endl;
}

void func9_43(string &s, string oldVal, string newVal)
{
	int _size = oldVal.size();
	string::iterator it1 = s.begin();
	string::iterator it2 = newVal.begin();
	string::iterator it3 = newVal.end();

	for (it1; it1 <= (s.end() - oldVal.size()); ++it1)
	{
		//pos可以由两个迭代器相减得到,返回截取到的string
		string str_t = s.substr(it1 - s.begin(), _size);
		if (str_t == oldVal)//substr()的作用就是截取string中的一段
		{
			it1 = s.erase(it1, it1 + _size);//返回的是最后一个被删除的元素之后的位置
			it1 = s.insert(it1, it2, it3);//返回的是最后一个被插入的元素的位置
			//s.insert(it1 - s.begin(), newVal);
			advance(it1, newVal.size());//向前一定大小
		}
	}
	cout << s;
}

void func9_43_2() {
	string s = "than, jiang";
	string oldVal = "an";
	string newVal = "k";
	func9_43(s, oldVal, newVal);
}

void func9_44(string &s, string oldVal, string newVal)
{
	int _size = oldVal.size();
	string::iterator it1 = s.begin();
	string::iterator it2 = newVal.begin();
	string::iterator it3 = newVal.end();

	for (it1; it1 <= (s.end() - oldVal.size()); ++it1)
	{
		//pos可以由两个迭代器相减得到,返回截取到的string
		string str_t = s.substr(it1 - s.begin(), _size);
		if (str_t == oldVal)//substr()的作用就是截取string中的一段
		{
			s.replace(it1 - s.begin(), _size, newVal);
			advance(it1, newVal.size());//向前一定大小
		}
	}
	//cout << s;//对string得replace操作似乎不会使指针失效
}

void func9_44_2() {
	string s = "than, jiang";
	string oldVal = "an";
	string newVal = "k";
	func9_44(s, oldVal, newVal);
}

void func9_45(string &name, string &frontVal, string &backVal)
{
	string::iterator it1 = name.begin();
	name.append(backVal);
	name.insert(it1, frontVal.begin(), frontVal.end());
}

void func9_46(string &name, string &frontVal, string &backVal)
{
	name.insert(name.size(), backVal);
	name.insert(0, frontVal);
}

void func9_47()
{
	COUTSTR(__FUNCTION__)
		//string中的搜索函数，需要注意的是函数的返回值：string::size_type类型，找到时返回第一个匹配的下标位置，找不到时返回npos.，注意皆为unsigned类型
		string s = "ab2c3d7R4E6";
	string number = "0123456789";
	unsigned pos = 0;
	while ((pos = s.find_first_of(number, pos)) != string::npos)//注意有两个参数，从pos开始查找
	{
		cout << "在第" << pos + 1 << "个位置找到数字" << s[pos] << endl;
		++pos;
	}
	pos = 0;//重新置零
	while ((pos = s.find_first_not_of(number, pos)) != string::npos)//注意有两个参数，从pos开始查找
	{
		cout << "在第" << pos + 1 << "个位置找到英文字母" << s[pos] << endl;
		++pos;
	}

	return;
}

void func9_48()
{
	COUTSTR(__FUNCTION__);
	string s = "acenmorsuvwxz";
	//ifstream infile(argv[1]);
	ifstream infile("1.txt");
	string str;
	infile >> str;//单词文件读入
	cout << "原字符串为：" << str << endl;

	unsigned pos1 = 0;
	unsigned pos2 = 0;
	unsigned _legenth = 0;
	unsigned pos3 = 0;

	while ((pos1 = str.find_first_of(s, pos1)) != string::npos)//找到第一个不出头字符
	{
		pos2 = pos1;
		if ((pos2 = str.find_first_not_of(s, pos2)) != string::npos)//从第一个不出头字符开始找到第一个出头字符
		{
			if (pos2 - pos1 >= _legenth)//找出最大长度并记录此区间的首位置
			{
				_legenth = pos2 - pos1;
				pos3 = pos1;
			}
		}
		++pos1;
	}
	string _string = str.substr(pos3, _legenth);
	cout << "最长不出头串：" << _string << endl;
	return;
}

void func9_50()
{
	COUTSTR(__FUNCTION__);
	vector<string> _string(5, "10");
	int sum1 = 0;
	double sum2 = 0.0;
	for (auto i = _string.begin(); i != _string.end(); ++i)
	{
		sum1 += stoi(*i);
		sum2 += stod(*i);
		cout << stod(*i) << endl;
	}
	cout << "int和为：" << sum1 << endl;
	cout << "double和为：" << sum2 << endl;
	return;
}

class Date
{
public://class默认是私有继承，记得要加public
	unsigned _year;
	unsigned _month;
	unsigned _day;
	void _show()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
	//构造函数
	Date(string);
};

Date::Date(string s)
{
	vector<string> args{ ","," ","/","\0" };//分割的方式
	string number = "0123456789";
	vector<string> month{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };//月份集合
	//处理间隔
	func9_44(s, args[0], args[1]);
	func9_44(s, args[2], args[1]);

	//提取月份
	string First = s.substr(0, s.find_first_of(args[1]));
	if (First.find_first_of(number) == 0)//开头是数字。直接转化为月份
	{
		_month = stoi(First);

	}
	else//开头是字母
	{
		for (int i = 0; i < month.size(); ++i) {//遍历月份

			if (First.find_first_of(month[i]) != string::npos)
			{
				_month = i + 1;
				break;
			}
		}
	}
	//提取日期
	auto firstempty = s.find_first_of(args[1]);
	auto lastempty = s.find_last_of(args[1]);
	_day = stoi(s.substr(firstempty, lastempty));
	//提取年份
	_year = stoi(s.substr(s.find_last_of(args[1])));
}

void func9_51()
{
	COUTSTR(__FUNCTION__);
	Date _today("2/25/2017");
	_today._show();

	Date _tomorrow("January 1,1995");
	_tomorrow._show();

	Date _2tomorrow("Jan 1 1995");
	_2tomorrow._show();
}

unsigned priority(char a)
{
	if (a == '?')
		return 0;
	if (a == '+' || a == '-')
		return 1;
	if (a == '*' || a == '/')
		return 2;
	if (a == '(' || a == ')')
		return 3;
}

void func9_52()
{
	COUTSTR(__FUNCTION__);

	string a = "(8+15*4+5-6/3+4)*25";
	stack<char>op;
	string op_type{ "+-*/()" };
	string data_temp = "";
	if (a[0] == '+' || a[0] == '-')
	{
		a = '0' + a;
	}
	for (auto i : a)
	{
		if (op_type.find(i) == op_type.npos)
		{
			data_temp += i;
		}
		else
		{
			cout << data_temp;
			data_temp = "";
			if (!op.empty())
			{
				while (!op.empty() && priority(i) <= priority(op.top()))
				{
					cout << op.top();
					op.pop();
				}
				op.push(i);
			}
			else
				op.push(i);
			if (op.top() == '(')
				op.top() = '?';
			if (op.top() == ')')
			{
				op.pop();
				while (op.top() != '?')
				{
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}
	}
	if (!op.empty())
	{
		cout << data_temp;
		while (!op.empty())
		{
			cout << op.top();
			op.pop();
		}
	}
	return;
}

void Practice_9() {
	COUTSTR("Practice_9:");
	func9_52();
}


//几种顺序容器的特点
//
//vector：可变大小，支持快速随机访问，尾部插入数据很快
//
//deque：双端队列。支持快速随机访问，头部插入数据很快
//
//list：双向链表。支持双向顺序访问，在其任何位置插入删除数据都很快
//
//array：固定大小数组，不能改变大小。(注意这里与普通的内置数组类型是不一样的)
//
//string：与vector类似，专用于保存字符。

//在通常情况下，使用vector是非常好的选择。且新版本的标准库容器比旧版本快很多。C++程序应该使用标准库容器，而不是原始的数据结构如：内置数组。
//
//(a)list，因为可能需要在容器的中间位置插入元素
//
//(b)deque，因为需要在头部进行元素的删除，deque效率更高
//
//(c)vector，无具体的删除插入操作，未知数量，vector是个不错的选择。

//容器中的元素类型可以是另一个容器
//
//本节中的几个比较重要的容器操作：
//
//c.empty()：c中存储了元素，返回false.
//
//c.cbegin()：返回const_iterator
//
//c.clear()：清空容器

//限制如下：
//
//迭代器指向同一个容器或者最后一个元素之后的位置
//
//可以反复递增begin直到end
//
//迭代器指向的元素范围是左闭合区间，注意end指向的是最后一个元素之后的位置。
//9.15
//判定容器之间的大小关系须遵循：
//
//1：大小和元素对应相等，则容器相等
//
//2：短容器的每个元素都等于长容器的对应元素，则短容器小于长容器
//
//3：两容器皆不是另一容器的子序列，则比较结果取决于第一个不相等元素的比较结果
