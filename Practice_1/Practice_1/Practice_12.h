#pragma once
#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
//#include <cstring>
#include <map>
#include "StrBlob.h"
#include "TextQuery.h"
using namespace std;

//
//1�������������ڣ�ȫ�ֶ����ڳ�������ʱ���䣬�ڳ������ʱ���١��ֲ��Զ����󣬵����ǽ����䶨�����ڳ����ʱ�����������뿪��ʱ�����١��ֲ�static�����ڵ�һ��ʹ��ǰ���䣬�ڳ������ʱ����
//
//2������static���Զ������⣬C++��֧�ֶ�̬����ķ��䡣��̬����Ķ���������������������ﴴ���޹أ�ֻ�б���ʾ���ͷ�ʱ����Щ����Żᱻ����
//
//3����̬������ͷ��Ǳ���м������׳�����ĵط���Ϊ�˰�ȫʹ�ö�̬���󣬱�׼�ⶨ������������ָ������������̬������󣬵�һ������Ӧ�ñ��ͷ�ʱ��ָ����������ָ�����ȷ���Զ��ͷ���
//
//4����̬�ڴ棺����ֲ�static������static���󡢶������κκ���֮��Ķ����ɱ������Զ����������١�ջ�ڴ棺���涨���ں���֮�ڵķ�static����ջ������ڶ���ĳ��������ʱ�Ŵ���
//
//5�����˾�̬�ڴ��ջ�ڴ棬ÿ������ӵ��һ���ڴ�أ��ⲿ���ڴ汻��Ϊ���ɿռ��ѣ������ö����洢��̬����Ķ����ڳ�������ʱ����Ķ��������������ɳ��������ƣ�Ҳ����˵������̬������ʹ��ʱ�����Ǳ�����ʽ�����٣�������ȷ�Ĺ���̬�ڴ�
//
//6��C++�ж�̬�ڴ�Ĺ�����ͨ��һ�����������ɵģ�new���ڶ�̬�ڴ���Ϊ�������ռ䲢����һ��ָ��ö����ָ�롣delete������һ����̬�����ָ�룬���ٸö��󣬲��ͷ���֮�������ڴ�
//
//7�������ͷ��ڴ棺�ڴ�й©��������ָ�������ڴ��������ͷ����ڴ棬�ͻ�������÷Ƿ��ڴ��ָ��
//
//8��Ϊ�˸���ȫ��ʹ�ö�̬�ڴ棬�±�׼�ⶨ������������ָ������������̬����ͷ�ļ�Ϊmemory������ָ�����Ҫ���þ����Զ��ͷ���ָ��Ķ���shared_ptr����������ָ��ָ��ͬһ����unique_ptr�������ռ��ָ�����
//
//9������ָ��������vector���÷�������ͬ�ĵط���������shared_ptr�Ķ��巽ʽ
//
//shared_ptr<string> p1;//����һ������ָ�룬ָ�����Ϊstring����
//shared_ptr<list<int>> p2;
//
//vector<string> p1;//����ָ��Ҳ��ģ��
//vector<list<int>> p2;
//
//10������ָ���ʹ�÷�ʽ����������ָ�����ƣ�������Ҳ�Ƿ�����ָ��������������ж���ʹ�ã�������Ƿ�Ϊ��
//
//11��make_shared()�������ȫ�ķ����ʹ�ö�̬�ڴ�ķ������˺����ڶ�̬�ڴ��з���һ�����󲢳�ʼ����������ָ��ö����shared_ptr��ͷ�ļ�Ϊmemory
//
//shared_ptr<int> p3 = make_shared<int>(42);//p3Ϊ����ָ�룬ָ��һ��ֵΪ42�Ķ���
//auto p3 = make_shared<int>(42);//����auto�Ƚϼ�㣬���������κβ�������ֵ��ʼ��
//
//12��ÿ��shared_ptr����һ�������ļ���������Ϊ���ü��������������Ǹö������õĴ���������������ز���ʱ�������½����󣬶���ֱ��ָ��Դ����
//
//���������
//		1����һ��shared_ptr��ʼ����һ��shared_ptr(����)
//		
//		2����һ��shared_ptr���ݸ�һ��������������ֵ����(����)
//		
//		3����Ϊ�����ķ���ֵ��(���ص�������Ŀ�����Ҳ���ǻ����õĴ��� + 1)
//
//�������ݼ������
//
//		1����shared_ptr����һ����ֵ(Ҳ����˵����ָ��������һ����ַ��ԭ��ָ��Ķ����Ѿ�û�������ߣ�����Զ��ͷ�)
//		
//		2��һ��shared_ptr�뿪��������ʱ���ᱻ����(�ݼ�)
//
//��һ��shared_ptr�ļ�������Ϊ0�����ͻ��Զ��ͷ��Լ�������Ķ���ǰ������ָ��Ķ���ֻ��һ�������ߡ�
//
//13����ָ��һ����������һ��shared_ptr������ʱ���ö���ᱻ�Զ����٣�����������������ݼ��ö�������ü����������ô�����Ϊ0�������ٸö���
//
//14��������ڴ��Ƿ����٣�����ָ����ڴ��shared_ptr���󶼱����٣�Ҳ���Ǽ�����Ϊ0
//
//15��ʹ�ö�̬�ڴ��ԭ���ö����������ͬ�ĵײ����ݡ�Ҳ����˵�����������Ȼ���������ǲ�����Ԫ�صĿ��������ǽ������ָ�򿽱�����һ��ָ���������һ������Ҳָ���Լ���ָ��Ķ��������ڱ����ͷ��Ժ󣬻�����һ������ָ������ԭ����ָ��Ķ���

//
//1��new��delete���������ָ����˵�ǳ����׳������ʹ������ָ��������̬�ڴ�
//
//2�������ɿռ������ڴ��������ģ����new�޷�Ϊ�����������������Ƿ���ָ��ö����ָ��
//
//3��Ĭ������£�new����Ķ�����Ĭ�ϳ�ʼ���ģ����˵���������ͻ���������ͽ���Ϊ�����(l���磺int����ָ��һ��Ϊ��ʼ����int)�������Ͷ�����Ĭ�Ϲ��캯�����г�ʼ��(����string�������һ����string)��
//
//4������ʹ��ֵ��ʼ��(������һ��С���ż���)��ֵ��ʼ�����������Ͷ����������ö����ֵ
//
//5��autoֻ�е�һ����ʱ����ʹ�ã�����ʹ��new����const����
//
//6��delete����������������ٸ���ָ����ָ��Ķ����ͷŶ�Ӧ���ڴ棬delete�Ĳ���������ָ��̬����Ķ������һ����ָ�롣
//
//7����������ָ�����Ķ�̬�ڴ��ڱ���ʽ���ͷ�ǰһֱ������ڣ���Ϊ���������������Ͳ�ͬ����Ȼ�������͵�ָ������뿪����������٣��������ڴ���Ȼ����
//
//8��ͬһ���ڴ��ͷ����Σ������������͵�ָ��ָ��ͬһ�����ɿռ������ڴ棬�ڶ�һ��ָ�����delete֮����ָ����ڴ�Ҳ�ᱻ�ͷţ����ٶԵڶ���ָ�����delete����������ɿռ��ƻ�
//
//9������ʹ��delete��ʹ���Ѿ��ͷŵ��Ķ����Ǿ���������(ʹ��new��deleteʱ)�����Ծ����ܵ�ʹ������ָ��
//
//10���ںܶ�����ϣ���ʹdelete��ĳ���������͵�ָ��(Ҳ����˵�ͷ��˶�Ӧ���ڴ�ռ�)����Ȼָ���Ѿ���Ч����������Ȼ�������ͷſռ�Ķ�Ӧ��ַ������˿���ָ�룬Ҳ����˵����Ҫ����ָ�룬���Խ�����Ϊ��ָ��

vector<int>* func12_6_1() {
	COUTSTR(__FUNCTION__);
	return new vector<int>{ 1,2,3 };
}

vector<int>* func12_6_2(vector<int>* pvec) {
	COUTSTR(__FUNCTION__);
	int cinint;
	while (cin >> cinint)
	{
		pvec->push_back(cinint);
	}
	return pvec;
}

void func12_6() {
	COUTSTR(__FUNCTION__);
	vector<int>* pvec = func12_6_2(func12_6_1());
	COUTLOOPITER((*pvec));
	delete pvec;
	return;
}

shared_ptr<vector<int>> func12_7_1() {
	COUTSTR(__FUNCTION__);
	//vector<int> vec1{ 1,23,45,6 };
	//return make_shared<vector<int>>(vec1);

	//return make_shared<vector<int>>();

	vector<int> vec1{ 1,23,45,6 };
	return make_shared<vector<int>>(vector<int>{ 1, 23, 45, 6 });

}

shared_ptr<vector<int>> func12_7_2(shared_ptr<vector<int>> spvec) {
	COUTSTR(__FUNCTION__);
	int cinint;
	//while (cin >> cinint)
	//{
	//	spvec->push_back(cinint);
	//}
	return spvec;
}

void func12_7() {
	COUTSTR(__FUNCTION__);
	shared_ptr<vector<int>> spvec = func12_7_2(func12_7_1());
	COUTLOOPITER((*spvec));
	return;
}

void func12_8() {
	COUTSTR(__FUNCTION__);
	vector<int>* pvec = func12_6_2(func12_6_1());
	COUTLOOPITER((*pvec));
	delete pvec;
	return;
}

void process(shared_ptr<string> str) {
	//��ָ��str�ڹ������ڱ����٣��ͷŵ��ڴ棬spter���Ϊ��ָ�룬vs2017 �����ϵ㱨��
	return;
}

void func12_11() {
	COUTSTR(__FUNCTION__);
	shared_ptr<string> spstr = make_shared<string>("mind");
	//process(shared_ptr<string>(spstr.get()));
	return;
}

void func12_12() {
	COUTSTR(__FUNCTION__);
	auto p = new string("mind");
	auto sp = make_shared<string>("mind");
	process(sp);//��ȷ
	//process(new string());//����
	//process(p);//����,����ֱ��ת��
	process(shared_ptr<string>(p));//pָ����ڴ��ڴ�������б����٣�pΪ��ָ��
	return;
}

void func12_13() {
	COUTSTR(__FUNCTION__);
	auto sp = make_shared<string>("mind");
	//auto p = sp.get();//������Ҫʹ��get
	//delete p;//vs2017 �����ϵ㱨������ָ�����գ�
	return;
}

//1�������new��delete֮�䷢�����쳣�����쳣δ����������ڴ����Զ���ᱻ�ͷţ�(�ǳ�Σ�գ�����)��������ָ��ֻҪ�뿪�����򣬼�������һ������������ָ�뱻���٣��ÿ��ڴ�Ҳ�ᱻ�ͷţ����˵����ʵ��ʹ�ù�����Ӧʹ��shared_ptr����ֹ�ڴ�й©
//
//2����ȷ��ʹ������ָ�룺
//
//	 1����ʹ����ͬ������ָ��ֵ��ʼ���������ָ��
//	 
//	 2����delete get()���ص�ָ��
//	 
//	 3����ʹ��get()��ʼ����reset��һ��ֻ��ָ��
//	 
//	 4������ʹ�õ�����ָ��������Դ����new������ڴ棬��ס����һ��ɾ����

struct destination { string i; };
struct connection {
	string j;
	destination des;
};
void coutdes(const destination des) {
	cout << des.i << endl;
}
void coutcon(const connection con) {
	cout << con.j << endl << con.des.i << endl;
}
connection connect(destination* des) {
	COUTSTR("connect: ");
	connection con;
	con.j = "connection init over: ";
	con.des.i = des->i + " over: ";
	coutcon(con);
	return con;
}
void disconnect(connection con) {
	COUTSTR("disconnect: OVER");
};
void end_connection(connection *p) {
	COUTSTR("end_connection: ");
	p->j = "connection quit: ";
	p->des.i = "destination quit: ";
	disconnect(*p);
	coutcon(*p);
}
void f(destination &d) {
	COUTSTR("f: ");
	coutdes(d);
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
}
void func12_14() {
	COUTSTR(__FUNCTION__);
	destination d;
	d.i = "destination init: ";
	f(d);
	return;
}

void f2(destination &d) {
	COUTSTR("f: ");
	coutdes(d);
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) {
		COUTSTR("end_connection: ");
		p->j = "connection quit: ";
		p->des.i = "destination quit: ";
		disconnect(*p);
		coutcon(*p);
	});
}
void func12_15() {
	COUTSTR(__FUNCTION__);
	destination d;
	d.i = "destination init: ";
	f2(d);
	return;
}

//1��unique_ptrӵ������ָ��Ķ�������һһ��Ӧ��ϵ��unique_ptr������ʱ�������Ҳ�ᱻ���٣�unique_ptr��֧�ֿ����͸�ֵ���������ֱ�ӳ�ʼ���ķ�ʽ�������Ƕ���һ��unique_ptrʱ�����뽫��󶨵�һ��new���ص�ָ����
//
//u.release()��������ָ��Ŀ���Ȩ������ָ�룬��������Ϊ�գ�
//u.reset(q)������ṩ������ָ��q����uָ��������󣬷���u�ÿգ���ָ�������Ȩת�ƣ�����û���ͷ��ڴ�
//
//3����unique_ptr��Ҫ������ʱ�����Խ��п���������unique_ptrָ�룬����һ������Ŀ���P473ҳ

void func12_16() {
	COUTSTR(__FUNCTION__);
	unique_ptr<int> uqi(new int(1));
	unique_ptr<int> uqi2(new int(7));
	//uqi = uqi2;//�ú�����ɾ��
	uqi.reset(uqi2.release());
	return;
}

void func12_20() {
	COUTSTR(__FUNCTION__);

	ifstream in("1.txt");
	string s;
	StrBlob blob;
	while (getline(in, s))
	{
		blob.push_back(s);
	}
	for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg.getCurr() != pend.getCurr();
		pbeg.incr())
		cout << pbeg.deref() << std::endl;
	return;
}

void func12_21() {
	COUTSTR(__FUNCTION__);

	ifstream in("1.txt");
	string s;
	StrBlob blob;
	while (getline(in, s))
	{
		blob.push_back(s);
	}
	for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg.getCurr() != pend.getCurr();
		pbeg.incr())
		cout << pbeg.deref() << std::endl;
	return;
}

string& tranStrRule1(string &str) {
	int _time = 1;
	for (auto ch = str. begin(); ch != str.end()-1;++ch) {
		auto ch_next = ch + 1;
		if (*ch == *ch_next) {
			++_time;
			if (_time > 2) {
				str.erase(ch_next);
				--_time;
				--ch;
			}
		}
		else
		{
			_time = 1;
		}
	}
	return str;
}

string& tranStrRule2(string &str) {
	int _time = 1;
	for (auto ch = str.begin(); ch < str.end() - 2; ++ch) {
		auto ch_next = ch + 1;
		auto ch_next2 = ch + 2;
		if (_time >= 2) {
			if (*ch_next == *ch_next2) {
				ch =str.erase(ch_next2);
				--ch;
				--ch;
			}
		}
		if (*ch == *ch_next) {
			++_time;
		}
		else
		{
			_time = 1;
		}
	}
	return str;
}

void func12_temp() {
	COUTSTR(__FUNCTION__);

	map<string,string> vecStr;
	int strNum;
	string str;
	while ([&]()->bool {cout << "������ת��������:"; return cin >> strNum && (strNum >=1); }())
	{
		while (vecStr.size() < strNum&&[&]()->bool {cout << "�����뵥��:"; return cin >> str&& str!="end"; }())
		{
			string _str = str;
			vecStr[str] = tranStrRule2(tranStrRule1(_str));

		}
		if (vecStr.size() >= strNum)
		{
			break;
		}
	}
	auto mapi = vecStr.begin();
	for (; mapi != vecStr.end(); ++mapi)//C++ 11֧��:const auto &s : word_count
	{
		//������Ա�ֱ����ؼ��ֺͶ�Ӧֵ
		cout << mapi->first << "    " << mapi->second << endl;
	}
	return;
}


int max(int x, int y)
{
	return x > y ? x : y;
}

int func12_temp2()
{
	int dp[10001];
	int cost[3] = { 150, 200, 350 };

	int t, n, i, j;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < 3; i++)
		{
			for (j = cost[i]; j <= n; j++)
			{
				dp[j] = max(dp[j], dp[j - cost[i]] + cost[i]);
			}
		}
		cout << n - dp[n] << endl;
	}
	return 0;
}

//1���������Ӧ��Ӧ��ʹ�ñ�׼��������������ʹ�ö�̬���������
//
//2����new����Ķ�̬����᷵��һ��Ԫ�����͵�ָ�룬����δ�õ��������͵Ķ���
//
//3����̬���鲢�����������ͣ����ܵ���begin()��end()���������106ҳ
//
//4���ͷŶ�̬����ʱ����Ҫ��ָ����ǰ��[] �������е�Ԫ�ذ�����������
//
//5���ַ������泣����ͬ����ͨ�ľֲ�����������static duration lifetime, ��������������������ж�������


void func12_23() {
	COUTSTR(__FUNCTION__);

	const char *s1 = "abc";
	const char *s2 = "efg";//�ַ������泣��,�ַ���ĩβ�пո�
	string stra = "a";
	string strb = "b";//��׼��string����
	char *p = new char[strlen(s1) + strlen(s2) + 1];//����ָ��Ҫ�������ĸ���
	strcpy_s(p,strlen(s1)+1 ,s1);//����
	strcat_s(p,sizeof(s2), s2);//����
	cout << p << endl;
	strcpy_s(p,strlen((stra + strb).c_str())+1, (stra + strb).c_str());//����ת��Ϊc�����ַ���(c����string����)
	cout << p << endl;
	delete[] p;
	return;
}

void func12_24() {
	COUTSTR(__FUNCTION__);
	string str;
	cin >> str;
	const char* strp = str.c_str();//��δʹ�ö�̬�ڴ�
	char* p = new char[strlen(strp) + 1];//���䶯̬�ڴ�ʱ����֤���Ȳ���
	strcpy_s(p, strlen(strp) + 1, strp);//����ת��Ϊc�����ַ���(c����string����)
	cout << p << endl;
	delete [] p;//�ᱨ��,��֪��Ϊɶ
	return;
}

void func12_25() {
	COUTSTR(__FUNCTION__);
	char * pa = new char[10];
	delete[] pa;
	return;
}

//
//1��new�ڴ������������������һ�𣬶�allocator���ڴ����Ͷ�������룬���ṩһ�����͸�֪���ڴ���䷽������������ڴ�ʱԭʼ�ġ�δ�����
//2������allocator�����ڴ�֮�󡣱����ھ���construnct���й���������������ֱ�Ϊ����������λ�õ�ָ�룬Ԫ�����͵�ֵ
//3���Թ�����Ԫ�ؽ���destory���������ٶ���deallocator

void func12_26() {
	COUTSTR(__FUNCTION__);
	int n = 20;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	string *q = p;//q�൱�ڸ�ֵλ����λ
	while (cin>>s&&q!=p+n&&s!="end")
	{
		alloc.construct(q++, s);
		const size_t size = q - p;
		cout << size << endl;
	}
	while (q!=p)
	{
		alloc.destroy(--q);
		const size_t size = q - p;
		cout << size << endl;
	}
	alloc.deallocate(p, n);//��������ڴ棬�ͷŶ���
	return;
}

void func12_27() {
	COUTSTR(__FUNCTION__);
	ifstream infile("1.txt");
	TextQuery tq(infile);//��������ļ����ݣ�������map
	//
	while (true)
	{
		COUTSTR("enter word to look for , or q to quit: ");
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}
}

void func12_28() {

	ifstream in("1.txt");
	string line;
	vector<string> vec1;
	while (getline(in, line))
	{
		vec1.push_back(line);
	}

	for (size_t i = 0; i < vec1.size(); ++i)
	{
		cout << vec1[i] << endl;
	}//����ı���������
	map<string, set<int>> map1;

	string s;
	cout << "��������ҵĵ���(����q�˳�)��";
	while ((cin >> s) && (s != "q"))
	{
		for (size_t i = 0; i < vec1.size(); ++i)
		{
			istringstream word(vec1[i]);
			string m;
			while (word >> m)
			{
				if (s == m)
				{
					map1[s].insert(i);
					break;
				}
			}
		}

		cout << s << " occours " << map1[s].size() << " times " << endl;
		auto it1 = map1[s].begin();
		for (it1; it1 != map1[s].end(); ++it1)
		{
			cout << "		" << "(line " << *it1 << ") " << vec1[*it1] << endl;
		}
	}

	return;
}

void Practice_12() {
	COUTSTR(__FUNCTION__);	
	func12_27();
}