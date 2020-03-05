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
	vector<int> vec{ 5,6,7,8,9,10,11,12,13,14 };//��������ָ�������С����֪��end��ָ��
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
	vector<int> vec{ 5,6,7,8,9,10,11,12,13,14 };//��������ָ�������С����֪��end��ָ��
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
	//������Ŀ������
	vector<int> vec1(list1.begin(), list1.end());
	vector<int> vec3(vec2.begin(), vec2.end() - 1);

	//��֤��ȷ��
	cout << (vec1 == vec2)
		<< (vec1 < vec2)
		<< (vec1 > vec3);
	return;
}

//���׼���������Ԫ�صķ�����
//
//1��push_back()		forward_list��array��֧��
//
//2��push_font()		forward_list��array��deque֧��
//
//3��emplace()			ͨ�����캯��ֱ�ӹ���Ԫ�أ����Բ����б����ֱ���ù��캯��
//															
//4��insert()			vector��deque��list��string֧�֣���ʱ����forward_list�ж����汾

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

void func9_22() {//�������Ĳ�����ı�ָ�������ĵ�����
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
	//��֤��ȷ��
	return;
}

void func9_24() {//�������Ĳ�����ı�ָ�������ĵ�����
	COUTSTR("func9_24:");
	vector<int> vec1;
	int a = vec1.front();//terminating with uncaught exception of type std::out_of_range
	//int b = vec1[0];// Segmentation fault: 11
	//int c = vec1.at(0);
	//int d = *vec1.begin();//��Ҫ������
	//cout 
	//	<< a << " " 
	//	<< b << " " 
	//	<< c << " " 
	//	<< d << endl;
	//cout << c;
	return;
}

void func9_26() {//�������Ĳ�����ı�ָ�������ĵ�����
	COUTSTR("func9_26:");
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	vector<int> vec1(ia, ia + 11);//��������
	list<int> list1(ia, ia + 11);

	vector<int>::iterator it1 = vec1.begin();//ʹ�õ�����
	list<int>::iterator it2 = list1.begin();

	while (it1 != vec1.end())//ɾ������
	{
		if ((*it1) % 2 == 0)
		{
			it1 = vec1.erase(it1);//��ɾ��λ�ø���
		}
		else//���жϷ�ż�������Ƶ���һλ��
		{
			++it1;
		}
	}

	while (it2 != list1.end())
	{
		if (*it2 % 2 != 0)
		{
			it2 = list1.erase(it2);//��ɾ��λ�ø���
		}
		else//���жϷ�ż�������Ƶ���һλ��
		{
			++it2;
		}
	}

	//��֤���
	vector<int>::iterator it3 = vec1.begin();//��Ҫ���¶�����ʱ������
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

	forward_list<int>::iterator it1 = forward_list1.begin();//��һ��Ԫ��
	forward_list<int>::iterator it2 = forward_list1.before_begin();//��ǰԪ��

	while (it1 != forward_list1.end())//ɾ������
	{
		if ((*it1) % 2 == 1)
		{
			it1 = forward_list1.erase_after(it2);//�������erase_after,ɾ�����ǵ���������֮��Ĳ���������ͬerase()
		}
		else//���жϷ�ż�������Ƶ���һλ��
		{
			it2 = it1;//����ǰԪ�صı����Ϊ��һ��Ԫ��
			++it1;
		}
	}

	//��֤���
	forward_list<int>::iterator it4 = forward_list1.begin();
	for (it4; it4 != forward_list1.end(); ++it4)
	{
		cout << *it4 << " ";
	}

}

void func9_28(forward_list<string> &fstr, string str1oc, string str) {
	COUTSTR("func9_28:");

	forward_list<string>::iterator it1 = fstr.begin();//��һ��Ԫ��
	forward_list<string>::iterator it2 = fstr.before_begin();//��ǰԪ��

	while (it1 != fstr.end())//ɾ������
	{
		if (*it1 == str1oc)
		{
			it1 = fstr.insert_after(it1, str);//�������erase_after,ɾ�����ǵ���������֮��Ĳ���������ͬerase()
			break;
		}
		else
		{
			forward_list<string>::iterator it_t = it1;//���һ��Ԫ��
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

//����(��array)������ɾ��Ԫ�صķ���
//
//pop_back()			forward_list��֧��
//
//pop_front()			vector��string��֧��
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
		cout << "vector�Ĵ�С" << vec1.size() << endl;;
		cout << "vector������" << vec1.capacity() << endl;
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

//reverse(n)����������������n��Ԫ�ص��ڴ档
//capacity()������������������
//resize�ı�size�����ı�capacity û���ͷ�vector���ڴ�
//reserve�ı�capacity ��ֻ��֤�����ɹ�

void func9_41() {
	COUTSTR(__FUNCTION__);
	vector<char> vec1(6, 'a');
	string _string(vec1.begin(), vec1.end());//��ʱ���Ǳ��������ܵ����ⷽ��
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
		//pos��������������������õ�,���ؽ�ȡ����string
		string str_t = s.substr(it1 - s.begin(), _size);
		if (str_t == oldVal)//substr()�����þ��ǽ�ȡstring�е�һ��
		{
			it1 = s.erase(it1, it1 + _size);//���ص������һ����ɾ����Ԫ��֮���λ��
			it1 = s.insert(it1, it2, it3);//���ص������һ���������Ԫ�ص�λ��
			//s.insert(it1 - s.begin(), newVal);
			advance(it1, newVal.size());//��ǰһ����С
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
		//pos��������������������õ�,���ؽ�ȡ����string
		string str_t = s.substr(it1 - s.begin(), _size);
		if (str_t == oldVal)//substr()�����þ��ǽ�ȡstring�е�һ��
		{
			s.replace(it1 - s.begin(), _size, newVal);
			advance(it1, newVal.size());//��ǰһ����С
		}
	}
	//cout << s;//��string��replace�����ƺ�����ʹָ��ʧЧ
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
		//string�е�������������Ҫע����Ǻ����ķ���ֵ��string::size_type���ͣ��ҵ�ʱ���ص�һ��ƥ����±�λ�ã��Ҳ���ʱ����npos.��ע���Ϊunsigned����
		string s = "ab2c3d7R4E6";
	string number = "0123456789";
	unsigned pos = 0;
	while ((pos = s.find_first_of(number, pos)) != string::npos)//ע����������������pos��ʼ����
	{
		cout << "�ڵ�" << pos + 1 << "��λ���ҵ�����" << s[pos] << endl;
		++pos;
	}
	pos = 0;//��������
	while ((pos = s.find_first_not_of(number, pos)) != string::npos)//ע����������������pos��ʼ����
	{
		cout << "�ڵ�" << pos + 1 << "��λ���ҵ�Ӣ����ĸ" << s[pos] << endl;
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
	infile >> str;//�����ļ�����
	cout << "ԭ�ַ���Ϊ��" << str << endl;

	unsigned pos1 = 0;
	unsigned pos2 = 0;
	unsigned _legenth = 0;
	unsigned pos3 = 0;

	while ((pos1 = str.find_first_of(s, pos1)) != string::npos)//�ҵ���һ������ͷ�ַ�
	{
		pos2 = pos1;
		if ((pos2 = str.find_first_not_of(s, pos2)) != string::npos)//�ӵ�һ������ͷ�ַ���ʼ�ҵ���һ����ͷ�ַ�
		{
			if (pos2 - pos1 >= _legenth)//�ҳ���󳤶Ȳ���¼���������λ��
			{
				_legenth = pos2 - pos1;
				pos3 = pos1;
			}
		}
		++pos1;
	}
	string _string = str.substr(pos3, _legenth);
	cout << "�����ͷ����" << _string << endl;
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
	cout << "int��Ϊ��" << sum1 << endl;
	cout << "double��Ϊ��" << sum2 << endl;
	return;
}

class Date
{
public://classĬ����˽�м̳У��ǵ�Ҫ��public
	unsigned _year;
	unsigned _month;
	unsigned _day;
	void _show()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
	//���캯��
	Date(string);
};

Date::Date(string s)
{
	vector<string> args{ ","," ","/","\0" };//�ָ�ķ�ʽ
	string number = "0123456789";
	vector<string> month{ "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };//�·ݼ���
	//������
	func9_44(s, args[0], args[1]);
	func9_44(s, args[2], args[1]);

	//��ȡ�·�
	string First = s.substr(0, s.find_first_of(args[1]));
	if (First.find_first_of(number) == 0)//��ͷ�����֡�ֱ��ת��Ϊ�·�
	{
		_month = stoi(First);

	}
	else//��ͷ����ĸ
	{
		for (int i = 0; i < month.size(); ++i) {//�����·�

			if (First.find_first_of(month[i]) != string::npos)
			{
				_month = i + 1;
				break;
			}
		}
	}
	//��ȡ����
	auto firstempty = s.find_first_of(args[1]);
	auto lastempty = s.find_last_of(args[1]);
	_day = stoi(s.substr(firstempty, lastempty));
	//��ȡ���
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


//����˳���������ص�
//
//vector���ɱ��С��֧�ֿ���������ʣ�β���������ݺܿ�
//
//deque��˫�˶��С�֧�ֿ���������ʣ�ͷ���������ݺܿ�
//
//list��˫������֧��˫��˳����ʣ������κ�λ�ò���ɾ�����ݶ��ܿ�
//
//array���̶���С���飬���ܸı��С��(ע����������ͨ���������������ǲ�һ����)
//
//string����vector���ƣ�ר���ڱ����ַ���

//��ͨ������£�ʹ��vector�Ƿǳ��õ�ѡ�����°汾�ı�׼�������Ⱦɰ汾��ܶࡣC++����Ӧ��ʹ�ñ�׼��������������ԭʼ�����ݽṹ�磺�������顣
//
//(a)list����Ϊ������Ҫ���������м�λ�ò���Ԫ��
//
//(b)deque����Ϊ��Ҫ��ͷ������Ԫ�ص�ɾ����dequeЧ�ʸ���
//
//(c)vector���޾����ɾ�����������δ֪������vector�Ǹ������ѡ��

//�����е�Ԫ�����Ϳ�������һ������
//
//�����еļ����Ƚ���Ҫ������������
//
//c.empty()��c�д洢��Ԫ�أ�����false.
//
//c.cbegin()������const_iterator
//
//c.clear()���������

//�������£�
//
//������ָ��ͬһ�������������һ��Ԫ��֮���λ��
//
//���Է�������beginֱ��end
//
//������ָ���Ԫ�ط�Χ����պ����䣬ע��endָ��������һ��Ԫ��֮���λ�á�
//9.15
//�ж�����֮��Ĵ�С��ϵ����ѭ��
//
//1����С��Ԫ�ض�Ӧ��ȣ����������
//
//2����������ÿ��Ԫ�ض����ڳ������Ķ�ӦԪ�أ��������С�ڳ�����
//
//3���������Բ�����һ�����������У���ȽϽ��ȡ���ڵ�һ�������Ԫ�صıȽϽ��
