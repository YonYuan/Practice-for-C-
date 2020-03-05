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
	//map��ģ����һ����ֵ��
	//vector��ģ����һ������
}

//1������������˳���������Ÿ����Ĳ�ͬ
//
//2������������Ԫ���ǰ��ؼ���������ͷ��ʵģ�˳�������ǰ������������е�λ����˳�����
//
//3���ؼ����ڹ�������������Ҫ�����ã�map�е�Ԫ���ǣ��ؼ��֡�ֵ���ԣ��ؼ������������ң�ֵ������������������ݡ�setÿ��Ԫ��ֻ����һ���ؼ��֣�֧�ָ�Ч�Ĺؼ��ʲ���
//
//4����׼���ṩ8��������������Ҫ��map / set���Ƿ��ظ��ؼ��֣�˳�򱣴��������

//map�Ķ��弰ʹ��
//1������mapͷ�ļ���2��ָ���ؼ��ʺ�ֵ�����ͣ�3���ؼ��ʿ���Ϊ�±꣬������Ӧֵ
//2��size_t��һ�ֻ�����ص��޷������ͣ�������Ƶ��㹻���Ա��ܱ����ڴ��е��������Ĵ�С����ʹ�������±�ʱ���������õ�������
//3����map��������±�����������ؼ��ֲ���map�У��±����������map�д���һ����Ԫ��(�ؼ���)����ӦֵΪĬ�ϳ�ʼ��ֵ��
//4����map��������ȡһ��Ԫ��ʱ����õ�һ��pair�����䱣������public���ݶ���firstΪ��ؼ��֣�secondΪ���Ӧֵ��

void func11_2() {
	COUTSTR(__FUNCTION__);
	//�⼸����������Ҫ�÷���

	//map���洢�ֵ�������

	//set����ֵ���飬ֻ�йؼ��ֵĺô�

	//list������λ������ɾ���������

	//deque����Ϣ����ֻ��ͷ��

	//vector����������ݣ�˳����
}

void func11_3() {
	COUTSTR(__FUNCTION__);
	//map�Ķ���
	map<string, size_t> word_count;
	fstream in("1.txt");//����һ��������
	string word;

	while (in >> word)
	{
		++word_count[word];//���û�л��ʼ��һ��
	}

	//mapͬ��֧�ֵ���������
	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}
}

//֪ʶ��1��set�Ķ�����ʹ�ã���mapֵ��һ��ֵ���ѣ���ֻ�йؼ���
//
//֪ʶ��2��set��find()��ʹ�ã�����һ������������������Ĺؼ�����set�У�������ָ��ùؼ��ʣ��粻�ڣ��򷵻�β�������

void func11_4() {
	COUTSTR(__FUNCTION__);
	//map�Ķ���
	map<string, size_t> word_count;
	fstream in("1.txt");//����һ��������
	string word;

	while (in >> word)
	{
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());//���������
		++word_count[word];//���û�л��ʼ��һ��
	}

	//mapͬ��֧�ֵ���������
	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}

}

//1������������֧��˳��������λ����ز������磺push_back��push_front����Ϊ���ǰ��ؼ��ִ洢��
//
//2�����������ĵ���������˫��ģ�����һЩ���ڹ�ϣ���ܵĲ���
//
//3��multimap��multiset������Ԫ�ؾ�����ͬ�Ĺؼ��֣����Ը�multiset��multimap�д�����ͬ��Ԫ�أ��ǿ��еģ���set��map�������ͬ�ؼ��ֵ�Ԫ��
//
//��ֻ��Ҫʹ�ùؼ���ʱʹ��set����Ҫʹ��Ԫ�ضԣ���Ӧ��ʹ��map

void func11_7() {
	COUTSTR(__FUNCTION__);
	map<string, vector<string>> family;
	string first_name, child_name;

	//��while��ʹ��lambda��䣬���Դ����������������������Ҫ����ĵ��������Ҳ�������У�ע������һ������
	//while ([&]()->bool {cout << "�������ͥ����:"; return cin >> first_name && (first_name != "end"); }())
	cout << "�������ͥ����:";
	while (cin >> first_name && (first_name != "end"))
	{
		cout << "�����뺢�ӵ����֣�";
		while (cin >> child_name && (child_name != "end"))
		{
			family[first_name].push_back(child_name);
		}
	}

	//mapͬ��֧�ֵ���������
	map<string, vector<string>>::iterator mapi;
	for (mapi = family.begin(); mapi != family.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
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

//���������ڶ�����ؼ���ʱ����ؼ��ֵ����ͱ������Ԫ�رȽϵķ����������һ�������ͣ���û�а����ȽϷ������򲻺Ϸ����������ж���Ƚ����͡�

void func11_9() {
	COUTSTR(__FUNCTION__);
	//map�Ķ���
	map<string, list<int>> word_count;
	string word;
	int rowCount = 0;
	char ch;
	ifstream fin("1.txt");
	while (fin.get(ch)) {
		//�÷������Զ�ȡ�����з�
		if (ch == '\n')
		{
			word_count[word].push_back(rowCount);//���û�л��ʼ��һ��
			++rowCount;
			word.clear();
		}
		else
		{
			if (ch != ' ')
			{
				string temp(1, ch);//char �� string��ת�� char*��string��ֱ�Ӹ�ֵ
				word.append(temp);
			}
			else
			{
				word_count[word].push_back(rowCount);//���û�л��ʼ��һ��
				word.clear();
			}
		}
	}
	fin.close();

	//mapͬ��֧�ֵ���������
	map<string, list<int>>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
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
	using compareType = bool(*)(const Sales_data& lhs, const Sales_data& rhs);//ʹ��using�����溯������
	//������ʹ��decltype������ĳ������ʱ�������غ������Ͷ���ָ�����ͣ����������Ҫ��ʾ�ļ���*�ѱ���������Ҫ����ָ�롣���ã�ѡ�񲢷��ز����������ͣ���Ϊ������������Ϊ�����ķ�������
}

void func11_12() {
	COUTSTR(__FUNCTION__);
	vector<pair<string, int>> vec1;//���ȶ����С������ʹ��push_back()
	string str;
	int val;
	size_t i = 0;
	while (cin >> str>>val&&str!="end")
	{
		vec1.push_back(make_pair(str, val));
	}
	vector<pair<string, int>>::iterator it1 = vec1.begin();
	cout << "vector��Ԫ��Ϊ��" << endl;
	for (it1; it1 != vec1.end(); ++it1)
	{
		cout << it1->first << " " << it1->second << endl;
	}

	return;
}

//pair�����ֶ��巽ʽ�����Դ���pair�ķ�ʽҲ�����֣�make_pair(v1, v2)����(����)һ��pair
//
//vec.push_back(std::make_pair(str, i));//make_pair����һ���������������ɵ�pair
//vec.push_back({ str, i });
//vec.emplace_back(str, i); //����

void func11_14() {
	COUTSTR(__FUNCTION__);
	map<string, vector<string>> family;
	vector<pair<string, string>> child;
	map<string, vector<pair<string, string>>> family_child;
	string first_name, child_name, _birthday;

	cout << "�������У�����end�����ʾ����" << endl;
	//��while��ʹ��lambda��䣬���Դ����������������������Ҫ����ĵ��������Ҳ�������У�ע������һ������
	while ([&]()->bool {cout << "�������ͥ����:"; return cin >> first_name && (first_name != "end"); }())
	{
		while ([&]()->bool {cout << "�����뺢�ӵ�����:"; return cin >> child_name && (child_name != "end"); }())
		{
			if([&]()->bool {cout << "�����뺢�ӵ�����:"; return cin >> _birthday && (_birthday != "end"); }())
			{
				family_child[first_name].push_back({ child_name,_birthday });
			}

		}
	}
	COUTSTR("�����ǵ���Ϣ��");
	//mapͬ��֧�ֵ���������
	map<string, vector<pair<string, string>>> ::iterator mapi;
	for (mapi = family_child.begin(); mapi != family_child.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
		cout << mapi->first << " :\n";
		for (const auto &s : mapi->second)
		{
			cout << s.first << " " << s.second << endl;
		}
	}
	return;
}

//1��P295�е����ͣ�����������֧��
//
//2������������������ͱ�����
//
//key_type����ʾ���������͵Ĺؼ�������
//
//mapped_type��ÿ���ؼ��ֹ��������ͣ�ֻ������map
//
//value_type������set����key_type��ͬ������map��Ϊpair<const key_type��mapped_type>
//
//3����������һ�����������ĵ�����ʱ�����ǻ�õ�һ������Ϊ������value_type��ֵ������
//
//4��map��value_type��һ��pair�����ǿ��Ըı�pair��ֵ�����ǲ��ܸı�ؼ��ֳ�Ա��ֵ

void func11_16() {
	COUTSTR(__FUNCTION__);
	map<string, string> family;
	//��ʼ��family
	map<string, string>::iterator fam_iter;
	for (auto &c : family) {
		if (c.first == fam_iter->first) {
			//����c.second
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
	//����	C2039	��push_back�� : ���ǡ�std::multiset<std::string, std::less<_Kty>, std::allocator<_Ty>>���ĳ�Ա	
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

//1��insert()�ڹ������������һ��Ԫ�ػ���һ��Ԫ�ط�Χ������map��setû���ظ��ؼ��֣����Բ�����ͬ��Ԫ�ز�������κε�Ӱ��
//2����map�в���Ԫ�أ�������pair���͡�

void func11_20() {
	COUTSTR(__FUNCTION__);
	//map�Ķ���
	map<string, size_t> word_count;
	fstream in("1.txt");//����һ��������
	string word;

	while (in >> word)
	{	
		auto ret = word_count.insert({ word, 1 });
		if (!ret.second) ++ret.first->second;
	}

	//mapͬ��֧�ֵ���������
	map<string, size_t>::iterator mapi;
	for (mapi = word_count.begin(); mapi != word_count.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
		cout << mapi->first << " ";
		cout << mapi->second << " " << endl;
	}
	return;
}

//
//1����map�����Ԫ�أ�Ԫ�ص����ͱ�����pair�����ǲ�û���ֳɵ�pairԪ�أ�������Ҫ��insert()�Ĳ����б��д���һ��pair
//2��insert�ķ���ֵ����������������Ԫ�����ͣ����ڲ������ظ��ؼ��ֵ�������insert����һ��pair����һ����Ա��ָ�����ָ���ؼ��ֵ�Ԫ�أ��ڶ���Ԫ����һ��boolֵ��ָ������Ԫ�����Ѿ���Ԫ���л��ǲ���ɹ������ؼ������������У�insert���ظ�ֵ�������������ڶ���������Ϊfalse
//3��������������ret.first��pair�ĵ�һ����Ա����map�ĵ�������->֮�󣬽����õ���������ȡ����map�е�Ԫ�أ�Ҳ����һ��pair���ҵ���Ԫ�صĵڶ���ֵ�����е�������
//
//familyy.insert({ "dsa","das" });//c++11֧��
//familyy.insert(pair<string, string>("asd", "das"));//��ʾ����һ��pair
//familyy.insert(make_pair("de", "1"));//��ʾ����һ��pair
//familyy.insert(map<string, string>::value_type("d", "da"));//��ʾ����һ��pair
//
//++ret.first->second;//ret������Ϊpair<map<string,size_t>::iterator , bool>  ret


void func11_22() {
	COUTSTR(__FUNCTION__);
	//map�Ķ���
	map<string, vector<int>> map1;
	auto map_it = map1.insert({ "a",{1,2,3} });
	pair<map<string, vector<int>>::iterator, bool>  map_it2;
	pair<pair<string, vector<int>>, bool>  map_it3;
	return;
}

//��ȡʾ��
void func11_23() {
	COUTSTR(__FUNCTION__);
	map<string, multimap<string, string>> family_child;
	string first_name, child_name, _birthday;

	cout << "�������У�����end�����ʾ����" << endl;
	//��while��ʹ��lambda��䣬���Դ����������������������Ҫ����ĵ��������Ҳ�������У�ע������һ������
	while ([&]()->bool {cout << "�������ͥ����:"; return cin >> first_name && (first_name != "end"); }())
	{
		while ([&]()->bool {cout << "�����뺢�ӵ�����:"; return cin >> child_name && (child_name != "end"); }())
		{
			if ([&]()->bool {cout << "�����뺢�ӵ�����:"; return cin >> _birthday && (_birthday != "end"); }())
			{
				family_child[first_name].insert({ child_name,_birthday });
			}	
		}
	}
	COUTSTR("�����ǵ���Ϣ��");
	//mapͬ��֧�ֵ���������
	auto mapi = family_child.begin();
	for (; mapi != family_child.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
		cout << mapi->first << " :\n";
		for (const auto &s : mapi->second)
		{
			cout << s.first << " " << s.second << endl;
		}
	}
	return;
}

//1����˳������һ�������ǿ�����erase()����һ������������һ������������ɾ��Ԫ�أ���������void������һ���汾��erase()����һ��key_type�Ĳ�����ɾ��ÿ���ؼ���Ϊ������Ԫ�أ�����һ��size_type��ָ����ɾ��Ԫ�ص�����
//
//2��set��֧���±������map��unordered_map֧���±������multimap��unordered_multimapҲû���±��������Ϊ����ͬ��Ԫ��
//
//3��map���±��������һ������(�ؼ���)����ȡ���Ǵ˹ؼ����������ֵ(��mapped_typeֵ)��������map���޴˹ؼ��ʣ������ᴴ��һ���µ�Ԫ�ز����뵽map�У�����ֵ������ֵ��ʼ��
//
//4��c.at(k)�����ʹؼ���Ϊk��Ԫ�أ���k����c�У��׳�out_of_range�쳣
//
//5��map���±����������õ�����*(����value_type)����ֵ��ͬ

//1������map��set�е�Ԫ�ز����Լ�����ʹ��find��count�������ܹؼ���
//find���عؼ���ָ���Ԫ�صĵ���������β���������count���عؼ��ֵ�����
//2��map���±�������ܻ���ɸ����ã��������ǲ�������Ԫ�أ�������find����Ѱ��Ԫ��

void func11_27() {
	COUTSTR(__FUNCTION__);
	map<string, vector<int>>::iterator it;

	return;
}

//1��lower_bound��upper_bound�Ҳ����ؼ��ʵĻ�����ָ��һ����Ӱ������Ĺؼ��ʲ���λ��
//2��equal_range()����������һ���ؼ��֣�����һ��������pair
//
//���ؼ��ִ��ڣ���һ��������ָ��ùؼ���ƥ���Ԫ�أ��ڶ����ؼ���ָ�����һ��Ԫ��ƥ��֮���λ�ã�
//��ؼ��ֲ����ڣ�������������ָ��ؼ��ֿ��Բ����λ��,���պô��ڸ�Ԫ�ص�λ�ã��ڴ�֮ǰ���Բ����Ԫ��

//11.30
//����ָ������÷��ʵڶ�������

void func11_31() {
	COUTSTR(__FUNCTION__);
	string author = "��е����";
	multimap<string, string> Library;
	Library.insert(make_pair(author, "�����ߵ�ñ��"));
	Library.insert(make_pair(author, "������"));
	Library.insert(make_pair(author, "����Ь"));
	Library.insert(make_pair(author, "����"));
	Library.insert(make_pair(author, "����֮��"));
	Library.insert(make_pair(author, "����˹�Ƽ�����"));

	auto it1 = Library.find(author); //���ص�һ���ؼ���Ϊauthor�ĵ�����
	auto it2 = Library.count(author);//���عؼ���Ϊauthor��Ԫ������

	while (it2)
	{
		if (it1->second == "����˹�Ƽ�����")
		{
			Library.erase(it1);//ֱ��ɾ���˹ؼ���ֵ�ԣ��������Ϊָ�����ĵ�����
			break;//��Ҫ,��Ȼ������õ��Ѿ�ɾ���ĵ������������
		}
		++it1;
		--it2;
	}

	auto it3 = Library.begin();

	for (; it3 != Library.end(); ++it3)
	{
		cout << it3->first << "�ı�������" << it3->second << endl;
	}
	return;
}

void func11_32() {
	COUTSTR(__FUNCTION__);
	string author = "��е����";
	multimap<string, string> Library;
	Library.insert(make_pair(author, "�����ߵ�ñ��"));
	Library.insert(make_pair(author, "������"));
	Library.insert(make_pair(author, "����Ь"));
	Library.insert(make_pair(author, "����"));
	Library.insert(make_pair(author, "����֮��"));
	Library.insert(make_pair(author, "����˹�Ƽ�����"));

	auto it1 = Library.find(author); //���ص�һ���ؼ���Ϊauthor�ĵ�����
	auto it2 = Library.count(author);//���عؼ���Ϊauthor��Ԫ������

	while (it2>0)
	{
		if (it1->first == author)
		{
			cout << it1->first << "�ı�������" << it1->second << endl;
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
		else//���ļ��ĺ����Խ�������֤
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
	string text;//��ȡһ��
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


//����汾���ƣ���������keyû�����Ե�˳���ϵʱ������, �Ҳ���Ҫ�ķѶ����ʱ����ά�������е�key����
//����汾���ƣ���������key�����Ե�˳���ϵʱ������, �����ǲ���Ҫ������������, �����Զ�ά������(�ֵ���)
//
//map��key_value������ģ�set�����������ģ����������Ĳ�������������������
//
//������������Ԫ��ʱ�����ȼ���Ԫ�صĹ�ϣֵ����ָ��Ӧ�������Ǹ�Ͱ����Ϊ��������ϸ����ͬ��Ԫ�ط���һ��Ͱ��

void func11_34() {
	COUTSTR(__FUNCTION__);
	
	return;
}

void Practice_11() {
	COUTSTR(__FUNCTION__);
	func11_32();
}