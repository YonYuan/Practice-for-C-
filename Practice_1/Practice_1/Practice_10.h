#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <deque>
#include "Sales_data.h"

using namespace std::placeholders;

void func10_1() {
	COUTSTR(__FUNCTION__);
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	int value = 5;
	cout << value << "���ֵĴ���Ϊ��" << count(vec.begin(), vec.end(), value) << endl;
}

void func10_2() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "ds","das","123","123","123","123","123","123","123","123" };
	list<string> vec(begin(a), end(a));
	for (auto c : vec) {
		cout << c << endl;
	}
	int value = 123;
	cout << value << "���ֵĴ���Ϊ��" << count(vec.begin(), vec.end(), to_string(value)) << endl;
}

void func10_3() {
	COUTSTR(__FUNCTION__);
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	cout << "Ԫ��֮��Ϊ��" << accumulate(vec.begin(), vec.end(), 0);
}

void func10_4() {
	COUTSTR(__FUNCTION__);
	double a[10] = { 0.4,1,2.3,5,4,5,4,5,4,5 };
	vector<double> vec(a, a + 10);
	cout << "Ԫ��֮��Ϊ��" << accumulate(vec.begin(), vec.end(), 0);
	//���35����ʧ����
}

void func10_6() {
	COUTSTR(__FUNCTION__);
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	fill_n(vec.begin(), vec.size(), 0);//ע������������������
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i];
	}
}

void func10_7() {
	COUTSTR(__FUNCTION__);
	//(a)��lst��vec֮��Ĵ�Сδ��֤��ͬ��vec.resize(lst.size)
	//(b)��reverse�Ǹı����������ģ���û�иı����С����resize()
}

void func10_8() {
	COUTSTR(__FUNCTION__);
	//������һ�������������ʹ��������������в��������
}

void elimDups(vector<string> &s) {
	COUTSTR("sort()ǰ��");
	COUTLOOP(s);
	COUTSTR("sort()��");
	sort(s.begin(), s.end());//sort����
	COUTLOOP(s);

	COUTSTR("unique()��");
	vector<string>::iterator str = unique(s.begin(), s.end());//unique����
	COUTLOOP(s);

	COUTSTR("erase()��");
	s.erase(str, s.end());//erase()����
	COUTLOOP(s);
}

void func10_9() {
	COUTSTR(__FUNCTION__);
	vector<string> s{ "because","I","Like","Like","C++","very","very","much","that's","why" };
	elimDups(s);
}

void func10_10() {
	COUTSTR(__FUNCTION__);
	//���ڲ���������Ĳ����������Ƕ�������push����
}

//�����㷨С�᣺
//find()������
//accmulate()��ͣ�
//equal()����жϣ�
//fill()��fill_n()��ֵ��
//back_insert()���������
//copy()������
//sort()����
//unique()���Ų����ظ�

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();//s1�Ĵ�С�Ƿ�С��s2
}

void func10_11() {
	COUTSTR(__FUNCTION__);
	vector<string> s{ "because","I","Like","Like","C++","very","very","much","that's","why" };
	elimDups(s);
	stable_sort(s.begin(), s.end(), isShorter);//���Զ���ĺ������ݽ���,�ȳ��ȡ����ֵ���
	COUTSTR("stable_sort�����")
	COUTLOOP(s)
}

//�ƺ����������ĳ����Ա����
bool compareIsbn(Sales_data data1, Sales_data data2)
{
	return 	data1.isbn().size() < data2.isbn().size();
}

void func10_12() {
	COUTSTR(__FUNCTION__);

	Sales_data a("because");//��ʼ������
	Sales_data b("I");
	Sales_data c("Like");
	Sales_data d("your");
	Sales_data e("beautiful");
	Sales_data f("eyes");

	vector<Sales_data> vec1{a,b,c,d,e,f};

	stable_sort(vec1.begin(), vec1.end(), compareIsbn);//����

	COUTSTR("������vector:");
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << vec1[i].isbn() << " ";
	}
}

bool compareStrLongerThanFive(const string s1)
{
	return s1.size() > 5 ?true :false;
}

void func10_13() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//���������ʼ��vector
	auto iter = partition(vec1.begin(), vec1.end(), compareStrLongerThanFive);//����
	COUTSTR("������vector�д���5��Ԫ��:");
	COUTLOOP(vec1);
}

void func10_14() {
	COUTSTR(__FUNCTION__);
	auto f = [](int a,int b) {
		return a + b;
	};
}

//1������ϣ�����㷨���и�������Ĳ�����������lambda���ʽ��һ��lambda���ʽ��ʾһ���ɵ��ô��뵥Ԫ�������Զ����ں������ڲ���
//	 ���ʽ����ʽ��f = [�����б�](�����б�) {������}�������б�Ϊ��ʱ��()��ʡ�ԡ�
//
//2�����δָ���������ݣ���lambda����void��
//
//3��lambdaֻ���ڲ����б��в���һ�������ں����ľֲ����������ں�������ʹ�øñ�����lambda����ֱ��ʹ�ö����ں���֮������ֻ��߾ֲ�static����


void func10_15() {
	COUTSTR(__FUNCTION__);
	int a =0;
	auto f = [a](int &b) {cout << a + b; };
}

void biggies(vector<string> &word,vector<string>::size_type sz) {
	elimDups(word);
	stable_sort(word.begin(), word.end(), [](const string&a, const string &b) {
		return a.size() < b.size(); });

	auto wc = find_if(word.begin(), word.end(), [sz](const string&a) {
		return a.size() >= sz; });

	auto count = word.end() - wc;
	cout<<endl << count << " " << "of length" << sz << "or longer" << endl;

	for_each(wc, word.end(), [](const string s) {
		COUTSTR(s);
	});
}

void func10_16() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//���������ʼ��vector
	biggies(vec1, 3);
}

void func10_17() {
	COUTSTR(__FUNCTION__);
	Sales_data a("because");//��ʼ������
	Sales_data b("I");
	Sales_data c("Like");
	Sales_data d("your");
	Sales_data e("beautiful");
	Sales_data f("eyes");

	vector<Sales_data> vec1{ a,b,c,d,e,f };

	stable_sort(vec1.begin(), vec1.end(), [](Sales_data data1, Sales_data data2) {
		return 	data1.isbn().size() < data2.isbn().size(); });//����

	COUTSTR("������vector:");
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << vec1[i].isbn() << " ";
	}
}

//partition()���ص������һ��ʹν��Ϊtrue��Ԫ�صĺ�һ��λ�õĵ�����
//find_if()���ص��ǵ�һ��ʹν�ʷ��ط�0ֵ��Ԫ�أ���������������Ԫ�أ��򷵻�β������

void biggies2(vector<string> &word, vector<string>::size_type sz) {
	elimDups(word);
	stable_sort(word.begin(), word.end(), [](const string&a, const string &b) {
		return a.size() < b.size(); });

	auto wc = partition(word.begin(), word.end(), [sz](const string&a) {
		return a.size() <= sz; });

	auto count = word.end() - wc;
	cout << endl << count << " " << "of length" << sz << "or longer" << endl;

	for_each(wc, word.end(), [](const string s) {
		COUTSTR(s);
	});
}

void func10_18() {
	COUTSTR(__FUNCTION__);

	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//���������ʼ��vector
	biggies2(vec1, 4);//�ҳ����ȴ���4���ַ���
}

void biggies3(vector<string> &word, vector<string>::size_type sz) {
	elimDups(word);
	stable_sort(word.begin(), word.end(), [](const string&a, const string &b) {
		return a.size() < b.size(); });

	auto wc = stable_partition(word.begin(), word.end(), [sz](const string&a) {
		return a.size() <= sz; });

	auto count = word.end() - wc;
	cout << endl << count << " " << "of length" << sz << "or longer" << endl;

	for_each(wc, word.end(), [](const string s) {
		COUTSTR(s);
	});
}

void func10_19() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//���������ʼ��vector
	biggies3(vec1, 4);//�ҳ����ȴ���4���ַ���
}

void func10_20() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//���������ʼ��vector
	int longersize = 6;
	auto num =count_if(vec1.begin(), vec1.end(), [longersize](const string&a) {
		return (a.size() > longersize);
	});
	COUTSTR(num);
}

//lambda�Ĳ���ʽ��ֵ�������ò�����ʽ������[]��ֵ���񣺱�����ı�����lambda����ʱ����
//
//���ò�����lambda��ʹ�����ò���ı���ʱ��ʵ������ʹ�õ������ö�Ӧ�ı�����Ҳ�Ϳ�����lambda���������޸ĸ�ֵ����������lambda������Ǿֲ����������뱣֤����������lambda�����õľֲ������ĵ�ַ��Ȼ���ڡ�
//
//��ʽ�����ñ���������lambda���еĴ����ƶ�������Ҫʹ����Щ������&��ʾ���ò��� = ��ʾֵ������ʾ��������ʽ������ʹ��ʱ�����벶��ʽ��ͬ��
//
//�������ٲ���������������Ⲷ����ܵ��µĽ�����������á�ָ�벶��
//
//stable_sort()����ʱ��ȳ���Ԫ��ά��ԭ��˳��
//
//partition()���������л��֣�ʹ��ν��Ϊ���Ԫ������ǰ�棬�������һ��ʹν��Ϊ���Ԫ�صĺ�һ��λ�õĵ�����
//
//find_if()���ҵ�һ�������ض���С��Ԫ��

void func10_21() {
	COUTSTR(__FUNCTION__);

	int i = 5;
	auto f = [&i]()->bool {
		if (i == 0)
		{
			return true;
		}
		else if(i>0)
		{
			--i;
			return false;
		}
	};//���ò���β�÷�������
	int j = f();
	cout << j << endl;;
}

bool sizeLonger(const string&a,size_t longersize) {
	return (a.size() > longersize);
}

void func10_22() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//���������ʼ��vector
	int longersize = 6;
	auto num = count_if(vec1.begin(), vec1.end(), bind(sizeLonger, _1, longersize));
	COUTSTR(num);
}

void func10_23() {
	COUTSTR(__FUNCTION__);
	//bind()������ͷ�ļ�Ϊfunctional�������ǽ�������ʽ�����࣬����һ���ɵ��ò���������һ���µĿɵ��ö���
	//auto func1 = bind(func2, _n);//_n��ʾռλ������func1����ʱ�ṩ������func1ʱ���ͻ��滻Ϊfunc2������
}

bool check_int(const int &s, string::size_type sz)
{
	return sz > s;
}

void func10_24() {
	COUTSTR(__FUNCTION__);

	string _string = "MyLove";//����һ��string
	vector<int> vec1{ 5,5,6,8,5,4,9,5,2,4 };//��ʼ��vector  

	string::size_type _length = _string.size();
	//ʹ��bind������Ҫͷ�ļ�������Ҫ���������ռ�
	cout << "С�ڵ���6��������" << count_if(vec1.begin(), vec1.end(), bind(check_int, _1, _length)) << "��";
}

bool check_size(const string &s, string::size_type sz)
{
	return sz > s.size();
}

void biggies4(vector<string> &s, vector<string>::size_type sz)
{
	elimDups(s);//�ֵ�����ɾ���ظ�  
	stable_sort(s.begin(), s.end(), [](const string &a, const string &b) {return a.size() < b.size(); });//����������  
	auto it1 = partition(s.begin(), s.end(), bind(check_size, _1, sz)/*[sz](const string &s){return s.size()<=sz;}*/);
	cout << endl;
	for (it1; it1 != s.end(); ++it1)
	{
		cout << *it1 << " ";
	}
}

void func10_25() {
	COUTSTR(__FUNCTION__);

	vector<string> vec1{ "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	size_t i = 4;
	biggies4(vec1, i);//�ҳ����ȴ���4���ַ���  
	return;
}

//10.26
//1������ĵ�����:����һ��������Ϊ����������һ����������ִ�б���֮��Ĳ���
//�������������Щ�������󶨵������ϣ�������������������Ԫ��
//�����������󶨵�����������ϣ������������й�����IO��
//���������������ƶ���������ǰ�ƶ�������forward_list������������
//�ƶ����������ƶ������е�Ԫ��
//2��������������һ��������Ϊ����������һ�������������������������Ԫ�ء�
//++it��it++��*it����������κ�Ч����ֻ�ܷ���it(���������)��it = t ��itָ���λ�ò���Ԫ��t��
//3�������������Ϊ���֣�
//back_inserter()����һ��ʹ��push_back�ĵ�������ǰ������������֧��push_back()�Ĳ���
//front_inserter()����һ��push_front�ĵ�������
//inserter()����һ��insert�������������������������뵽ָ��������֮ǰ��
//	������������Ĺ������̣�front_insert()��Ϊ���⣬���ǽ�Ԫ�ز�������֮��λ�á�
	
void func10_27() {
	COUTSTR(__FUNCTION__);
	vector<string> vec1{ "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	list<string> list1;
	sort(vec1.begin(), vec1.end());//sort����
	unique_copy(vec1.begin(), vec1.end(), back_inserter(list1));
	COUTLOOPITER(list1);
	return;
}

void func10_28() {
	COUTSTR(__FUNCTION__);
	vector<int> vec1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> vec2;
	deque<int> vec3;
	vector<int> vec4;

	//ʵ�ְ���ͷ�ļ�iterator
	copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2));
	copy(vec1.cbegin(), vec1.cend(), front_inserter(vec3));
	copy(vec1.cbegin(), vec1.cend(), inserter(vec4, vec4.begin()));

	COUTSTR("vec2�ַ�Ϊ��");
	COUTLOOP(vec2);
	COUTSTR("vec3�ַ�Ϊ��");
	COUTLOOP(vec3);
	COUTSTR("vec4�ַ�Ϊ��");
	COUTLOOP(vec4);
	return;
}

void func10_29() {
	COUTSTR(__FUNCTION__);
	//io�����������Ƕ�Ӧ���������ض����͵�Ԫ������������ͨ��ʹ�����������������÷����㷨�����ж����ȡ�����Լ�д����
	fstream inf("1.txt");
	istream_iterator<string> isiter(inf);
	istream_iterator<string> isend;
	vector<string> vec1;
	copy(isiter, isend, back_inserter(vec1));
	COUTLOOPITER(vec1);
	return;
}

void func10_30() {
	COUTSTR(__FUNCTION__);

	istream_iterator<int> is_iter(cin);
	istream_iterator<int> is_eof;
	vector<int> vec1;
	copy(is_iter, is_eof, back_inserter(vec1));
	sort(vec1.begin(), vec1.end());
	COUTLOOPITER(vec1);
	return;
}

void func10_31() {
	COUTSTR(__FUNCTION__);

	istream_iterator<int> is_iter(cin);
	istream_iterator<int> is_eof;
	vector<int> vec1;
	vector<int> vec2;
	copy(is_iter, is_eof, back_inserter(vec1));
	sort(vec1.begin(), vec1.end());
	unique_copy(vec1.begin(), vec1.end(), back_inserter(vec2));
	COUTLOOPITER(vec2);
	return;
}

void func10_33(const string srcFilePath1, const string desFilePath1, const string desFilePath2) {
	COUTSTR(__FUNCTION__);
	ifstream in(srcFilePath1);
	ofstream out1(desFilePath1);
	ofstream out2(desFilePath2);

	istream_iterator<int> is_iter(in);
	istream_iterator<int> is_eof;

	ostream_iterator<int> out_iter1(out1, " ");
	ostream_iterator<int> out_iter2(out2, "\n");

	vector<int> vec1(is_iter, is_eof);
	for (int i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] % 2 == 0)//ż��
		{
			out_iter1++ = vec1[i];//ż������2.txt��
		}
		else
		{
			out_iter2++ = vec1[i];//��������3.txt��
		}
	}

	return;
}

//1�����������������r�������������Ҫ���ǵݼ���������������cbegin()������string
//2��rbegin()ָ��������һ��Ԫ�أ�rend()ָ�������Ԫ��֮ǰ��λ��
//3��ͨ�����÷����������base()��Ա���������Խ���ת��Ϊ��Ӧ����ͨ������

void func10_34() {
	COUTSTR(__FUNCTION__);

	vector<int> day1{ 1,2,3,4,5 };
	for (auto it1 = day1.rbegin(); it1 != day1.rend(); ++it1)//�����++ʵ�����ǵݼ���
	{
		cout << *it1 << " ";
	}
	return;
}

void func10_35() {
	COUTSTR(__FUNCTION__);

	vector<int> day1{ 1,2,3,4,5 };
	for (auto it1 = day1.end(); it1 != day1.begin();)//�����++ʵ�����ǵݼ���
	{
		--it1;
		cout << *it1 << " ";
	}
	return;
}

void func10_36() {
	COUTSTR(__FUNCTION__);
	list<int> list1{ 1,0,3,0,4 };
	cout << *find(list1.rbegin(), list1.rend(), 0);

	return;
}

void func10_37() {
	vector<int> vec1{ 1,0,3,0,4,5,8,9,6,5 };
	list<int> list1;
	//���������++�ǵݼ��������������ƶ���--�ǵ��������������ǰ�ƶ�
	copy(vec1.rbegin() + 3, vec1.rend() - 2, back_inserter(list1));
	COUTLOOPITER(list1);
}

//10.30
//��������������Զ�ȡ�����е�Ԫ�ء�
//���������������������������Ĳ�������д��
//ǰ�������������֧�����������
//˫���������˫��֧�ֶ�д����֧�ֵ����ݼ��������
//������ʵ�����������֧�����й��ܡ�

//list��˫���������vector��������ʵ�����

//copy��������������һ����������������������������������
//reverse�϶�����Ҫ˫���������
//unique��ǰ�������
//_if �����أ�����ν�������İ汾��_copy�����汾���㷨

void func10_38() {
	list<string> list1{ "sdc","sddc","sdec","sfdc","sdec","sdc","sdc","fsdc","sadc","fsdc" };
	list1.sort();//ʹ�����Ա�����汾���㷨������
	list1.unique();//ɾ����ͬԪ��
	COUTLOOPITER(list1);
}

void Practice_10() {
	COUTSTR(__FUNCTION__);
	func10_37();
}