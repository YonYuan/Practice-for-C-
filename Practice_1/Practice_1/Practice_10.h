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
	cout << value << "出现的次数为：" << count(vec.begin(), vec.end(), value) << endl;
}

void func10_2() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "ds","das","123","123","123","123","123","123","123","123" };
	list<string> vec(begin(a), end(a));
	for (auto c : vec) {
		cout << c << endl;
	}
	int value = 123;
	cout << value << "出现的次数为：" << count(vec.begin(), vec.end(), to_string(value)) << endl;
}

void func10_3() {
	COUTSTR(__FUNCTION__);
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	cout << "元素之和为：" << accumulate(vec.begin(), vec.end(), 0);
}

void func10_4() {
	COUTSTR(__FUNCTION__);
	double a[10] = { 0.4,1,2.3,5,4,5,4,5,4,5 };
	vector<double> vec(a, a + 10);
	cout << "元素之和为：" << accumulate(vec.begin(), vec.end(), 0);
	//输出35，损失精度
}

void func10_6() {
	COUTSTR(__FUNCTION__);
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	fill_n(vec.begin(), vec.size(), 0);//注意其三个参数的意义
	for (size_t i = 0; i < vec.size(); ++i)
	{
		cout << vec[i];
	}
}

void func10_7() {
	COUTSTR(__FUNCTION__);
	//(a)：lst和vec之间的大小未保证相同，vec.resize(lst.size)
	//(b)：reverse是改变容器容量的，并没有改变其大小，用resize()
}

void func10_8() {
	COUTSTR(__FUNCTION__);
	//产生了一个插入迭代器，使用这个迭代器进行插入操作。
}

void elimDups(vector<string> &s) {
	COUTSTR("sort()前：");
	COUTLOOP(s);
	COUTSTR("sort()后：");
	sort(s.begin(), s.end());//sort排序
	COUTLOOP(s);

	COUTSTR("unique()后：");
	vector<string>::iterator str = unique(s.begin(), s.end());//unique排序
	COUTLOOP(s);

	COUTSTR("erase()后：");
	s.erase(str, s.end());//erase()操作
	COUTLOOP(s);
}

void func10_9() {
	COUTSTR(__FUNCTION__);
	vector<string> s{ "because","I","Like","Like","C++","very","very","much","that's","why" };
	elimDups(s);
}

void func10_10() {
	COUTSTR(__FUNCTION__);
	//基于插入迭代器的操作本质上是对容器的push操作
}

//泛型算法小结：
//find()搜索，
//accmulate()求和，
//equal()相等判断，
//fill()、fill_n()赋值，
//back_insert()插入操作，
//copy()拷贝，
//sort()排序，
//unique()重排并消重复

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();//s1的大小是否小于s2
}

void func10_11() {
	COUTSTR(__FUNCTION__);
	vector<string> s{ "because","I","Like","Like","C++","very","very","much","that's","why" };
	elimDups(s);
	stable_sort(s.begin(), s.end(), isShorter);//将自定义的函数传递进来,先长度、后字典序
	COUTSTR("stable_sort排序后：")
	COUTLOOP(s)
}

//似乎不能是类的某个成员函数
bool compareIsbn(Sales_data data1, Sales_data data2)
{
	return 	data1.isbn().size() < data2.isbn().size();
}

void func10_12() {
	COUTSTR(__FUNCTION__);

	Sales_data a("because");//初始化对象
	Sales_data b("I");
	Sales_data c("Like");
	Sales_data d("your");
	Sales_data e("beautiful");
	Sales_data f("eyes");

	vector<Sales_data> vec1{a,b,c,d,e,f};

	stable_sort(vec1.begin(), vec1.end(), compareIsbn);//排序

	COUTSTR("排序后的vector:");
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
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	auto iter = partition(vec1.begin(), vec1.end(), compareStrLongerThanFive);//排序
	COUTSTR("排序后的vector中大于5的元素:");
	COUTLOOP(vec1);
}

void func10_14() {
	COUTSTR(__FUNCTION__);
	auto f = [](int a,int b) {
		return a + b;
	};
}

//1：我们希望对算法进行更多参数的操作，衍生出lambda表达式，一个lambda表达式表示一个可调用代码单元，它可以定义在函数的内部。
//	 表达式的形式：f = [捕获列表](参数列表) {函数体}，参数列表为空时，()可省略。
//
//2：如果未指定返回内容，则lambda返回void。
//
//3：lambda只有在捕获列表中捕获一个它所在函数的局部变量才能在函数体中使用该变量，lambda可以直接使用定义在函数之外的名字或者局部static变量


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
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	biggies(vec1, 3);
}

void func10_17() {
	COUTSTR(__FUNCTION__);
	Sales_data a("because");//初始化对象
	Sales_data b("I");
	Sales_data c("Like");
	Sales_data d("your");
	Sales_data e("beautiful");
	Sales_data f("eyes");

	vector<Sales_data> vec1{ a,b,c,d,e,f };

	stable_sort(vec1.begin(), vec1.end(), [](Sales_data data1, Sales_data data2) {
		return 	data1.isbn().size() < data2.isbn().size(); });//排序

	COUTSTR("排序后的vector:");
	for (int i = 0; i < vec1.size(); ++i)
	{
		cout << vec1[i].isbn() << " ";
	}
}

//partition()返回的是最后一个使谓词为true的元素的后一个位置的迭代器
//find_if()返回的是第一个使谓词返回非0值的元素，若不存在这样的元素，则返回尾迭代器

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
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	biggies2(vec1, 4);//找出长度大于4的字符串
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
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	biggies3(vec1, 4);//找出长度大于4的字符串
}

void func10_20() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	int longersize = 6;
	auto num =count_if(vec1.begin(), vec1.end(), [longersize](const string&a) {
		return (a.size() > longersize);
	});
	COUTSTR(num);
}

//lambda的捕获方式：值捕获、引用捕获、隐式捕获，在[]中值捕获：被捕获的变量在lambda创建时拷贝
//
//引用捕获：在lambda中使用引用捕获的变量时，实际上所使用的是引用对应的变量，也就可以在lambda函数体内修改该值。但是由于lambda捕获的是局部变量，必须保证函数结束后、lambda所调用的局部变量的地址仍然存在。
//
//隐式捕获：让编译器根据lambda体中的代码推断我们需要使用哪些变量。&表示引用捕获， = 表示值捕获。显示捕获与隐式捕获混合使用时，必须捕获方式不同。
//
//尽量减少捕获的数据量，避免捕获可能导致的结果，避免引用、指针捕获。
//
//stable_sort()排序时相等长度元素维持原有顺序
//
//partition()对容器进行划分，使得谓词为真的元素排在前面，返回最后一个使谓词为真的元素的后一个位置的迭代器
//
//find_if()查找第一个具有特定大小的元素

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
	};//引用捕获、尾置返回类型
	int j = f();
	cout << j << endl;;
}

bool sizeLonger(const string&a,size_t longersize) {
	return (a.size() > longersize);
}

void func10_22() {
	COUTSTR(__FUNCTION__);
	string a[10] = { "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	vector<string> vec1(a, a + 10);//利用数组初始化vector
	int longersize = 6;
	auto num = count_if(vec1.begin(), vec1.end(), bind(sizeLonger, _1, longersize));
	COUTSTR(num);
}

void func10_23() {
	COUTSTR(__FUNCTION__);
	//bind()函数，头文件为functional，作用是将参数隐式的增多，接受一个可调用参数，生成一个新的可调用对象。
	//auto func1 = bind(func2, _n);//_n表示占位符，由func1调用时提供。调用func1时，就会替换为func2函数。
}

bool check_int(const int &s, string::size_type sz)
{
	return sz > s;
}

void func10_24() {
	COUTSTR(__FUNCTION__);

	string _string = "MyLove";//给定一个string
	vector<int> vec1{ 5,5,6,8,5,4,9,5,2,4 };//初始化vector  

	string::size_type _length = _string.size();
	//使用bind不仅需要头文件，还需要声明命名空间
	cout << "小于等于6的数字有" << count_if(vec1.begin(), vec1.end(), bind(check_int, _1, _length)) << "个";
}

bool check_size(const string &s, string::size_type sz)
{
	return sz > s.size();
}

void biggies4(vector<string> &s, vector<string>::size_type sz)
{
	elimDups(s);//字典排序、删除重复  
	stable_sort(s.begin(), s.end(), [](const string &a, const string &b) {return a.size() < b.size(); });//按长度排序  
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
	biggies4(vec1, i);//找出长度大于4的字符串  
	return;
}

//10.26
//1：特殊的迭代器:接受一个容器作为参数，产生一个迭代器，执行遍历之外的操作
//插入迭代器：这些迭代器绑定到容器上，可以用来向容器插入元素
//流迭代器：绑定到输入输出流上，用来遍历所有关联的IO流
//反向迭代器：向后移动而不是向前移动，出了forward_list其他容器都有
//移动迭代器：移动容器中的元素
//2：插入器，接受一个容器作为参数，生成一个迭代器，可以向容器中添加元素。
//++it，it++，*it都不会产生任何效果，只能返回it(插入迭代器)，it = t 在it指向的位置插入元素t。
//3：插入迭代器分为三种：
//back_inserter()创建一个使用push_back的迭代器，前提是容器必须支持push_back()的操作
//front_inserter()创建一个push_front的迭代器，
//inserter()创建一个insert迭代器，接受两个参数。插入到指定迭代器之前。
//	区别就是其具体的工作过程，front_insert()最为特殊，总是将元素插在容器之首位置。
	
void func10_27() {
	COUTSTR(__FUNCTION__);
	vector<string> vec1{ "diuwudh","udh","diudh","wudh","diuwu","h","diuw","diuwudhg257","h","d" };
	list<string> list1;
	sort(vec1.begin(), vec1.end());//sort排序
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

	//实现包含头文件iterator
	copy(vec1.cbegin(), vec1.cend(), back_inserter(vec2));
	copy(vec1.cbegin(), vec1.cend(), front_inserter(vec3));
	copy(vec1.cbegin(), vec1.cend(), inserter(vec4, vec4.begin()));

	COUTSTR("vec2字符为：");
	COUTLOOP(vec2);
	COUTSTR("vec3字符为：");
	COUTLOOP(vec3);
	COUTSTR("vec4字符为：");
	COUTLOOP(vec4);
	return;
}

void func10_29() {
	COUTSTR(__FUNCTION__);
	//io迭代器将他们对应的流当作特定类型的元素序列来处理。通过使用流迭代器，可以用泛型算法从流中对象读取数据以及写数据
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
		if (vec1[i] % 2 == 0)//偶数
		{
			out_iter1++ = vec1[i];//偶数放在2.txt中
		}
		else
		{
			out_iter2++ = vec1[i];//奇数放在3.txt中
		}
	}

	return;
}

//1：反向迭代器，加上r，反向迭代器需要的是递减运算符，操作会从cbegin()反向处理string
//2：rbegin()指向的是最后一个元素，rend()指向的是首元素之前的位置
//3：通过调用反向迭代器的base()成员函数，可以将其转换为对应的普通迭代器

void func10_34() {
	COUTSTR(__FUNCTION__);

	vector<int> day1{ 1,2,3,4,5 };
	for (auto it1 = day1.rbegin(); it1 != day1.rend(); ++it1)//这里的++实际上是递减的
	{
		cout << *it1 << " ";
	}
	return;
}

void func10_35() {
	COUTSTR(__FUNCTION__);

	vector<int> day1{ 1,2,3,4,5 };
	for (auto it1 = day1.end(); it1 != day1.begin();)//这里的++实际上是递减的
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
	//反向迭代器++是递减的运算符，向后移动，--是递增的运算符，向前移动
	copy(vec1.rbegin() + 3, vec1.rend() - 2, back_inserter(list1));
	COUTLOOPITER(list1);
}

//10.30
//输入迭代器：可以读取序列中的元素。
//输出迭代器，看作是输入迭代器的补集，可写。
//前向迭代器：单向，支持输入输出。
//双向迭代器：双向，支持读写，还支持递增递减运算符。
//随机访问迭代器：基本支持所有功能。

//list：双向迭代器。vector：随机访问迭代器

//copy的三个参数，第一二个数输入迭代器，第三个是输出迭代器
//reverse肯定是需要双向迭代器的
//unique是前向迭代器
//_if 非重载，满足谓词条件的版本。_copy拷贝版本的算法

void func10_38() {
	list<string> list1{ "sdc","sddc","sdec","sfdc","sdec","sdc","sdc","fsdc","sadc","fsdc" };
	list1.sort();//使用其成员函数版本的算法，排序
	list1.unique();//删除相同元素
	COUTLOOPITER(list1);
}

void Practice_10() {
	COUTSTR(__FUNCTION__);
	func10_37();
}