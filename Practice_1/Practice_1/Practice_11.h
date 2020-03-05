#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include "Sales_data.h"



void func11_1() {
	COUTSTR(__FUNCTION__);
	//map的模板是一个键值对
	//vector的模板是一个类型
}

//1：关联容器与顺序容器有着根本的不同
//
//2：关联容器的元素是按关键词来保存和访问的，顺序容器是按他们在容器中的位置来顺序访问
//
//3：关键词在关联容器中起到重要的作用，map中的元素是（关键字—值）对，关键词是索引左右，值是与索引相关联的数据。set每个元素只包含一个关键字，支持高效的关键词查找
//
//4：标准库提供8个关联容器，主要是map / set，是否重复关键字，顺序保存容器与否

//map的定义及使用
//1：包含map头文件，2：指定关键词和值的类型，3：关键词可作为下标，索引对应值
//2：size_t是一种机器相关的无符号类型，它被设计的足够大以便能保存内存中的任意对象的大小，在使用数组下标时，经常会用到此类型
//3：对map对象进行下标操作，如若关键字不在map中，下标运算符会在map中创建一个新元素(关键词)，对应值为默认初始化值。
//4：从map对象中提取一个元素时，会得到一个pair对象，其保存两个public数据对象，first为其关键字，second为其对应值。

void func11_2() {
	COUTSTR(__FUNCTION__);
	//这几个容器的主要用法：

	//map：存储字典型数据

	//set：坏值检验，只有关键字的好处

	//list：任意位置任意删除添加数据

	//deque：信息处理，只在头部

	//vector：相关联数据，顺序处理
}

void func11_3() {
	COUTSTR(__FUNCTION__);
	//map的定义
	map<string, size_t> word_count;
	fstream in("1.txt");//定义一个输入流
	string word;

	while (in >> word)
	{
		++word_count[word];//如果没有会初始化一个
	}

	//map同样支持迭代器操作
	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}
}

//知识点1：set的定义与使用，与map值差一个值而已，它只有关键字
//
//知识点2：set对find()的使用，返回一个迭代器，如果给定的关键词在set中，迭代器指向该关键词，如不在，则返回尾后迭代器

void func11_4() {
	COUTSTR(__FUNCTION__);
	//map的定义
	map<string, size_t> word_count;
	fstream in("1.txt");//定义一个输入流
	string word;

	while (in >> word)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());//消灭标点符号
		++word_count[word];//如果没有会初始化一个
	}

	//map同样支持迭代器操作
	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}

}

//1：关联容器不支持顺序容器的位置相关操作，如：push_back、push_front，因为其是按关键字存储的
//
//2：关联容器的迭代器都是双向的，还有一些关于哈希性能的操作
//
//3：multimap和multiset允许多个元素具有相同的关键字，所以给multiset和multimap中传入相同的元素，是可行的，而set、map会忽略相同关键字的元素
//
//当只需要使用关键字时使用set，需要使用元素对，则应该使用map

void func11_7() {
	COUTSTR(__FUNCTION__);
	map<string, vector<string>> family;
	string first_name, child_name;

	//在while中使用lambda语句，可以传入多条语句参数，将我们想要传入的的输出参数也放在其中，注意后面的一对括号
	//while ([&]()->bool {cout << "请输入家庭的姓:"; return cin >> first_name && (first_name != "end"); }())
	cout << "请输入家庭的姓:";
	while (cin >> first_name && (first_name != "end"))
	{
		cout << "请输入孩子的名字：";
		while (cin >> child_name && (child_name != "end"))
		{
			family[first_name].push_back(child_name);
		}
	}

	//map同样支持迭代器操作
	map<string, vector<string>>::iterator mapi;
	for (mapi = family.begin(); mapi != family.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " :";
		vector<string>::iterator it1 = mapi->second.begin();
		for (it1; it1 != mapi->second.end(); ++it1)
		{
			cout << *it1 << " ";
		}
	}
}

void func11_8() {
	COUTSTR(__FUNCTION__);
	vector<int> vec1;
	set<int> set1;
	int num;
	while (cin >> num)
	{
		if (find(vec1.begin(), vec1.end(), num) != vec1.end()) {
			vec1.push_back(num);
		}
	}
	COUTLOOP(vec1);
}

//有序容器在定义其关键字时，其关键字的类型必须包含元素比较的方法，如果是一个类类型，且没有包含比较方法，则不合法，可以自行定义比较类型。

void func11_9() {
	COUTSTR(__FUNCTION__);
	//map的定义
	map<string, list<int>> word_count;
	string word;
	int rowCount = 0;
	char ch;
	ifstream fin("1.txt");
	while (fin.get(ch)) {
		//该方法可以读取到换行符
		if (ch == '\n')
		{
			word_count[word].push_back(rowCount);//如果没有会初始化一个
			++rowCount;
			word.clear();
		}
		else
		{
			if (ch != ' ')
			{
				string temp(1, ch);//char 与 string的转换 char*与string可直接赋值
				word.append(temp);
			}
			else
			{
				word_count[word].push_back(rowCount);//如果没有会初始化一个
				word.clear();
			}
		}
	}
	fin.close();

	//map同样支持迭代器操作
	map<string, list<int>>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << endl << mapi->first << endl;
		COUTLOOPITER(mapi->second);
	}
}

void func11_10() {
	COUTSTR(__FUNCTION__);
	vector<int> vec1{ 1,2,3,4,5,6,7,8 };
	vector<int>::iterator vec_iter = vec1.begin() + 1;
	cout << (vec1.begin() < vec_iter) << endl;
	//list<int> list1{ 1,2,3,4,5,6,7,8 };
	//list<int>::iterator list_iter = list1.begin();
	//cout << (list1.begin() < list_iter) << endl;
}


void func11_11() {
	COUTSTR(__FUNCTION__);
	using compareType = bool(*)(const Sales_data& lhs, const Sales_data& rhs);//使用using来代替函数类型
	//当我们使用decltype作用于某个函数时，它返回函数类型而非指针类型，因此我们需要显示的加上*已表明我们需要返回指针。作用：选择并返回操作数的类型，若为函数，则类型为函数的返回类型
}

void func11_12() {
	COUTSTR(__FUNCTION__);
	vector<pair<string, int>> vec1;//事先定义大小，或者使用push_back()
	string str;
	int val;
	size_t i = 0;
	while (cin >> str>>val&&str!="end")
	{
		vec1.push_back(make_pair(str, val));
	}
	vector<pair<string, int>>::iterator it1 = vec1.begin();
	cout << "vector中元素为：" << endl;
	for (it1; it1 != vec1.end(); ++it1)
	{
		cout << it1->first << " " << it1->second << endl;
	}

	return;
}

//pair有三种定义方式，所以创建pair的方式也有三种，make_pair(v1, v2)返回(创建)一个pair
//
//vec.push_back(std::make_pair(str, i));//make_pair返回一个用两个参数构成的pair
//vec.push_back({ str, i });
//vec.emplace_back(str, i); //最简便

void func11_14() {
	COUTSTR(__FUNCTION__);
	map<string, vector<string>> family;
	vector<pair<string, string>> child;
	map<string, vector<pair<string, string>>> family_child;
	string first_name, child_name, _birthday;

	cout << "本输入中，均以end输入表示截至" << endl;
	//在while中使用lambda语句，可以传入多条语句参数，将我们想要传入的的输出参数也放在其中，注意后面的一对括号
	while ([&]()->bool {cout << "请输入家庭的姓:"; return cin >> first_name && (first_name != "end"); }())
	{
		while ([&]()->bool {cout << "请输入孩子的名字:"; return cin >> child_name && (child_name != "end"); }())
		{
			if([&]()->bool {cout << "请输入孩子的生日:"; return cin >> _birthday && (_birthday != "end"); }())
			{
				family_child[first_name].push_back({ child_name,_birthday });
			}

		}
	}
	COUTSTR("孩子们的信息：");
	//map同样支持迭代器操作
	map<string, vector<pair<string, string>>> ::iterator mapi;
	for (mapi = family_child.begin(); mapi != family_child.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " :\n";
		for (const auto &s : mapi->second)
		{
			cout << s.first << " " << s.second << endl;
		}
	}
	return;
}

//1：P295有的类型，关联容器皆支持
//
//2：关联容器额外的类型别名：
//
//key_type：表示此容器类型的关键字类型
//
//mapped_type：每个关键字关联的类型，只适用于map
//
//value_type：对于set，与key_type相同，对于map，为pair<const key_type，mapped_type>
//
//3：当解引用一个关联容器的迭代器时，我们会得到一个类型为容器的value_type的值的引用
//
//4：map的value_type是一个pair，我们可以改变pair的值，但是不能改变关键字成员的值

void func11_16() {
	COUTSTR(__FUNCTION__);
	map<string, string> family;
	//初始化family
	map<string, string>::iterator fam_iter;
	for (auto &c : family) {
		if (c.first == fam_iter->first) {
			//操作c.second
		}
	}
	return;
}

void func11_17() {
	COUTSTR(__FUNCTION__);
	multiset<string> set_str{"a","b","c","b"};
	vector<string> vec_str{"av","bv","cv","c"};
	copy(vec_str.begin(), vec_str.end(), inserter(set_str, set_str.end()));
	//copy(vec_str.begin(), vec_str.end(), back_inserter(set_str));
	//错误	C2039	“push_back” : 不是“std::multiset<std::string, std::less<_Kty>, std::allocator<_Ty>>”的成员	
	copy(set_str.begin(), set_str.end(), inserter(vec_str, vec_str.end()));
	copy(set_str.begin(), set_str.end(), back_inserter(vec_str));

	return;
}

void func11_18() {
	COUTSTR(__FUNCTION__);
	pair<const string, size_t> map_it;
	return;
}

bool compareIsbn2(const Sales_data &data1, const Sales_data &data2)
{
	return 	data1.isbn().size() < data2.isbn().size();
}


void func11_19() {
	COUTSTR(__FUNCTION__);
	using compareType = bool(*)(const Sales_data &lhs, const Sales_data &rhs);
	multiset<Sales_data, compareType> bookstore(compareIsbn2);
	multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
	return;
}

//1：insert()在关联容器中添加一个元素或者一个元素范围，由于map和set没有重复关键字，所以插入相同的元素不会产生任何的影响
//2：向map中插入元素，必须是pair类型。

void func11_20() {
	COUTSTR(__FUNCTION__);
	//map的定义
	map<string, size_t> word_count;
	fstream in("1.txt");//定义一个输入流
	string word;

	while (in >> word)
	{	
		auto ret = word_count.insert({ word, 1 });
		if (!ret.second) ++ret.first->second;
	}

	//map同样支持迭代器操作
	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}
	return;
}

//
//1：向map中添加元素，元素的类型必须是pair，但是并没有现成的pair元素，所以需要在insert()的参数列表中创建一个pair
//2：insert的返回值依赖于容器类型与元素类型，对于不包含重复关键字的容器，insert返回一个pair，第一个成员是指向具有指定关键字的元素，第二个元素是一个bool值，指出插入元素是已经在元素中还是插入成功，若关键词已在容器中，insert返回该值，不做操作，第二个参数变为false
//3：递增计数器：ret.first是pair的第一个成员，是map的迭代器，->之后，解引用迭代器，提取的是map中的元素，也就是一个pair，找到此元素的第二个值，进行递增操作
//
//familyy.insert({ "dsa","das" });//c++11支持
//familyy.insert(pair<string, string>("asd", "das"));//显示创建一个pair
//familyy.insert(make_pair("de", "1"));//显示创建一个pair
//familyy.insert(map<string, string>::value_type("d", "da"));//显示创建一个pair
//
//++ret.first->second;//ret的类型为pair<map<string,size_t>::iterator , bool>  ret


void func11_22() {
	COUTSTR(__FUNCTION__);
	//map的定义
	map<string, vector<int>> map1;
	auto map_it = map1.insert({ "a",{1,2,3} });
	pair<map<string, vector<int>>::iterator, bool>  map_it2;
	pair<pair<string, vector<int>>, bool>  map_it3;
	return;
}

//读取示范
void func11_23() {
	COUTSTR(__FUNCTION__);
	map<string, multimap<string, string>> family_child;
	string first_name, child_name, _birthday;

	cout << "本输入中，均以end输入表示截至" << endl;
	//在while中使用lambda语句，可以传入多条语句参数，将我们想要传入的的输出参数也放在其中，注意后面的一对括号
	while ([&]()->bool {cout << "请输入家庭的姓:"; return cin >> first_name && (first_name != "end"); }())
	{
		while ([&]()->bool {cout << "请输入孩子的名字:"; return cin >> child_name && (child_name != "end"); }())
		{
			if ([&]()->bool {cout << "请输入孩子的生日:"; return cin >> _birthday && (_birthday != "end"); }())
			{
				family_child[first_name].insert({ child_name,_birthday });
			}	
		}
	}
	COUTSTR("孩子们的信息：");
	//map同样支持迭代器操作
	auto mapi = family_child.begin();
	for (; mapi != family_child.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
		cout << mapi->first << " :\n";
		for (const auto &s : mapi->second)
		{
			cout << s.first << " " << s.second << endl;
		}
	}
	return;
}

//1：和顺序容器一样，我们可以向erase()传入一个迭代器或者一个迭代器对来删除元素，函数返回void，还有一个版本的erase()接收一个key_type的参数，删除每个关键词为参数的元素，返回一个size_type，指出被删除元素的数量
//
//2：set不支持下标操作，map和unordered_map支持下标操作，multimap和unordered_multimap也没有下标操作，因为有相同的元素
//
//3：map的下标操作接受一个索引(关键词)，获取的是此关键词相关联的值(即mapped_type值)，但是若map中无此关键词，则它会创建一个新的元素并插入到map中，关联值将进行值初始化
//
//4：c.at(k)：访问关键词为k的元素，若k不在c中，抛出out_of_range异常
//
//5：map的下标操作与解引用迭代器*(返回value_type)返回值不同

//1：对于map和set中的元素查找以及计数使用find和count，都接受关键字
//find返回关键字指向的元素的迭代器或者尾后迭代器，count返回关键字的数量
//2：map的下标操作可能会造成副作用，插入我们不想插入的元素，可以用find代替寻找元素

void func11_27() {
	COUTSTR(__FUNCTION__);
	map<string, vector<int>>::iterator it;

	return;
}

//1：lower_bound和upper_bound找不到关键词的话，会指向一个不影响排序的关键词插入位置
//2：equal_range()函数，接收一个关键字，返回一个迭代器pair
//
//若关键字存在，第一个迭代器指向该关键字匹配的元素，第二个关键字指向最后一个元素匹配之后的位置，
//如关键字不存在，两个迭代器都指向关键字可以插入的位置,即刚好大于该元素的位置，在此之前可以插入该元素

//11.30
//返回指针解引用访问第二个参数

void func11_31() {
	COUTSTR(__FUNCTION__);
	string author = "机械先驱";
	multimap<string, string> Library;
	Library.insert(make_pair(author, "灭世者的帽子"));
	Library.insert(make_pair(author, "法穿杖"));
	Library.insert(make_pair(author, "法穿鞋"));
	Library.insert(make_pair(author, "冰杖"));
	Library.insert(make_pair(author, "巫妖之祸"));
	Library.insert(make_pair(author, "海克斯科技核心"));

	auto it1 = Library.find(author); //返回第一个关键字为author的迭代器
	auto it2 = Library.count(author);//返回关键词为author的元素数量

	while (it2)
	{
		if (it1->second == "海克斯科技核心")
		{
			Library.erase(it1);//直接删除此关键字值对，传入参数为指向它的迭代器
			break;//需要,不然下面调用到已经删除的迭代器，会出粗
		}
		++it1;
		--it2;
	}

	auto it3 = Library.begin();

	for (; it3 != Library.end(); ++it3)
	{
		cout << it3->first << "的宝贝儿：" << it3->second << endl;
	}
	return;
}

void func11_32() {
	COUTSTR(__FUNCTION__);
	string author = "机械先驱";
	multimap<string, string> Library;
	Library.insert(make_pair(author, "灭世者的帽子"));
	Library.insert(make_pair(author, "法穿杖"));
	Library.insert(make_pair(author, "法穿鞋"));
	Library.insert(make_pair(author, "冰杖"));
	Library.insert(make_pair(author, "巫妖之祸"));
	Library.insert(make_pair(author, "海克斯科技核心"));

	auto it1 = Library.find(author); //返回第一个关键字为author的迭代器
	auto it2 = Library.count(author);//返回关键词为author的元素数量

	while (it2>0)
	{
		if (it1->first == author)
		{
			cout << it1->first << "的宝贝儿：" << it1->second << endl;
			--it2;
		}
		++it1;
	}

	return;
}

map<string, string> buildMap(ifstream &map_file) {
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
			//trans_map.insert({ key, value.substr(1) });
		}
		else//对文件的合理性进行了验证
		{
			throw runtime_error("no rule for " + key);
		}
		return trans_map;
	}
}

const string &
mtransform(const string &s, const map<string, string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
	{
		return s;
	}
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;//获取一行
	while (getline(input,text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >>word)
		{
			if (firstword)
				firstword = false;
			else
			{
				cout << " ";
			}
			cout << mtransform(word, trans_map);
		}
		cout << endl;
	}
}


//无序版本优势：当容器中key没有明显的顺序关系时更有用, 且不需要耗费多余的时间来维护容器中的key序列
//有序版本优势：当容器中key有明显的顺序关系时更有用, 且我们不需要考虑排序问题, 容器自动维护序列(字典序)
//
//map的key_value是有序的，set本身就是有序的，有序容器的操作可以用于无序容器
//
//无序容器访问元素时，首先计算元素的哈希值，它指出应该搜索那个桶，因为容器讲哈细致相同的元素放在一个桶中

void func11_34() {
	COUTSTR(__FUNCTION__);
	
	return;
}

void Practice_11() {
	COUTSTR(__FUNCTION__);
	func11_32();
}