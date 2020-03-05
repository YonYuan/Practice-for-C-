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
//1：对象生命周期：全局对象在程序启动时分配，在程序结束时销毁。局部自动对象，当我们进入其定义所在程序块时被创建，在离开块时被销毁。局部static对象在第一次使用前分配，在程序结束时销毁
//
//2：除了static和自动对象外，C++还支持动态对象的分配。动态分配的对象的生存期与它们在哪里创建无关，只有被显示的释放时，这些对象才会被销毁
//
//3：动态对象的释放是编程中极其容易出问题的地方，为了安全使用动态对象，标准库定义了两个智能指针类型来管理动态分配对象，当一个对象应该被释放时，指向它的智能指针可以确保自动释放它
//
//4：静态内存：保存局部static对象、类static对象、定义在任何函数之外的对象，由编译器自动创建和销毁。栈内存：保存定义在函数之内的非static对象，栈对象仅在定义的程序块运行时才存在
//
//5：除了静态内存和栈内存，每个程序还拥有一个内存池，这部分内存被称为自由空间或堆，程序用堆来存储动态分配的对象：在程序运行时分配的对象，其生存周期由程序来控制，也就是说，当动态对象不再使用时，我们必须显式的销毁：必须正确的管理动态内存
//
//6：C++中动态内存的管理是通过一对运算符来完成的，new：在动态内存中为对象分配空间并返回一个指向该对象的指针。delete：接受一个动态对象的指针，销毁该对象，并释放与之关联的内存
//
//7：忘记释放内存：内存泄漏，在尚有指针引用内存的情况下释放了内存，就会产生引用非法内存的指针
//
//8：为了更安全的使用动态内存，新标准库定义了两种智能指针类型来管理动态对象，头文件为memory，智能指针的主要作用就是自动释放所指向的对象，shared_ptr类型允许多个指针指向同一对象，unique_ptr类型则独占所指向对象
//
//9：智能指针类似与vector，用法上有相同的地方，下面是shared_ptr的定义方式
//
//shared_ptr<string> p1;//定义一个智能指针，指向对象为string类型
//shared_ptr<list<int>> p2;
//
//vector<string> p1;//智能指针也是模版
//vector<list<int>> p2;
//
//10：智能指针的使用方式与内置类型指针相似，解引用也是返回所指向对象，若在条件判断中使用，检测其是否为空
//
//11：make_shared()函数：最安全的分配和使用动态内存的方法，此函数在动态内存中分配一个对象并初始化它，返回指向该对象的shared_ptr，头文件为memory
//
//shared_ptr<int> p3 = make_shared<int>(42);//p3为智能指针，指向一个值为42的对象
//auto p3 = make_shared<int>(42);//利用auto比较简便，若不传递任何参数，会值初始化
//
//12：每个shared_ptr都有一个关联的计数器，称为引用计数，个人理解就是该对象被引用的次数，发生拷贝相关操作时，不会新建对象，而是直接指向源对象
//
//递增情况：
//		1：用一个shared_ptr初始化另一个shared_ptr(拷贝)
//		
//		2：将一个shared_ptr传递给一个函数当参数，值传递(拷贝)
//		
//		3：作为函数的返回值，(返回的是自身的拷贝，也就是活引用的次数 + 1)
//
//计数器递减情况：
//
//		1：给shared_ptr赋予一个新值(也就是说自身指向了另外一个地址，原来指向的对象已经没有引用者，则会自动释放)
//		
//		2：一个shared_ptr离开其作用域时，会被销毁(递减)
//
//当一个shared_ptr的计数器变为0，他就会自动释放自己所管理的对象，前提是其指向的对象只有一个引用者。
//
//13：当指向一个对象的最后一个shared_ptr被销毁时，该对象会被自动销毁：利用析构函数，会递减该对象的引用计数，当引用次数变为0，会销毁该对象
//
//14：相关联内存是否销毁：所有指向该内存的shared_ptr对象都被销毁，也就是计数器为0
//
//15：使用动态内存的原因：让多个对象共享相同的底层数据。也就是说拷贝的情况虽然发生，但是并不是元素的拷贝，而是将本身的指向拷贝给另一个指针对象，让这一个对象也指向自己所指向的对象，这样在本身释放以后，还有另一个对象指向自身原来所指向的对象。

//
//1：new和delete相对于智能指针来说非常容易出错，最好使用智能指针来管理动态内存
//
//2：在自由空间分配的内存是无名的，因此new无法为其分配对象命名，而是返回指向该对象的指针
//
//3：默认情况下，new分配的对象是默认初始化的，这就说明内置类型或者组合类型将是为定义的(l例如：int，会指向一个为初始化的int)，类类型对象将用默认构造函数进行初始化(例如string，会产生一个空string)。
//
//4：建议使用值初始化(在最后加一对小括号即可)，值初始化的内置类型对象有着良好定义的值
//
//5：auto只有单一参数时可以使用，可以使用new分配const对象
//
//6：delete完成两个操作：销毁给定指针所指向的对象，释放对应的内存，delete的参数必须是指向动态分配的对象或是一个空指针。
//
//7：内置类型指针管理的动态内存在被显式的释放前一直都会存在，因为内置类型与类类型不同，虽然内置类型的指针会在离开作用域后被销毁，但是其内存依然存在
//
//8：同一块内存释放两次：两个内置类型的指针指向同一块自由空间分配的内存，在对一个指针进行delete之后，其指向的内存也会被释放，若再对第二个指针进行delete，会造成自由空间破坏
//
//9：忘记使用delete，使用已经释放掉的对象都是经常发生的(使用new和delete时)，所以尽可能的使用智能指针
//
//10：在很多机器上，即使delete了某个内置类型的指针(也就是说释放了对应的内存空间)，虽然指针已经无效，但是其仍然保留这释放空间的对应地址，变成了空悬指针，也就是说我们要保留指针，可以将其置为空指针

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
	//该指针str在工作域内被销毁，释放掉内存，spter会成为空指针，vs2017 触发断点报错
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
	process(sp);//正确
	//process(new string());//报错
	//process(p);//报错,不能直接转换
	process(shared_ptr<string>(p));//p指向的内存在处理过程中被销毁，p为空指针
	return;
}

void func12_13() {
	COUTSTR(__FUNCTION__);
	auto sp = make_shared<string>("mind");
	//auto p = sp.get();//尽量不要使用get
	//delete p;//vs2017 触发断点报错（智能指针悬空）
	return;
}

//1：如果在new和delete之间发生了异常，且异常未被捕获，则该内存就永远不会被释放！(非常危险！！！)，而智能指针只要离开作用域，计数器减一，则随着智能指针被销毁，该块内存也会被释放，这就说明在实际使用过程中应使用shared_ptr来防止内存泄漏
//
//2：正确的使用智能指针：
//
//	 1：不使用相同的内置指针值初始化多个智能指针
//	 
//	 2：不delete get()返回的指针
//	 
//	 3：不使用get()初始化或reset另一个只能指针
//	 
//	 4：当你使用的智能指针管理的资源不是new分配的内存，记住传递一个删除器

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

//1：unique_ptr拥有其所指向的对象，属于一一对应关系，unique_ptr被销毁时，其对象也会被销毁，unique_ptr不支持拷贝和赋值，必须采用直接初始化的方式，当我们定义一个unique_ptr时，必须将其绑定到一个new返回的指针上
//
//u.release()：放弃对指针的控制权，返回指针，并将其置为空，
//u.reset(q)：如果提供了内置指针q，令u指向这个对象，否则将u置空，将指针的所有权转移，但并没有释放内存
//
//3：在unique_ptr快要被销毁时，可以进行拷贝：返回unique_ptr指针，这是一种特殊的拷贝P473页

void func12_16() {
	COUTSTR(__FUNCTION__);
	unique_ptr<int> uqi(new int(1));
	unique_ptr<int> uqi2(new int(7));
	//uqi = uqi2;//该函数已删除
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
	while ([&]()->bool {cout << "请输入转换单词数:"; return cin >> strNum && (strNum >=1); }())
	{
		while (vecStr.size() < strNum&&[&]()->bool {cout << "请输入单词:"; return cin >> str&& str!="end"; }())
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
	for (; mapi != vecStr.end(); ++mapi)//C++ 11支持:const auto &s : word_count
	{
		//两个成员分别代表关键字和对应值
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

//1：大多数的应用应该使用标准库容器，而不是使用动态分配的数组
//
//2：用new分配的动态数组会返回一个元素类型的指针，而并未得到数组类型的对象
//
//3：动态数组并不是数组类型，不能调用begin()和end()函数，详见106页
//
//4：释放动态数组时，需要在指针名前加[] ，数组中的元素按照逆序销毁
//
//5：字符串字面常量不同于普通的局部变量，具有static duration lifetime, 这整个程序的生命周期中都将存在


void func12_23() {
	COUTSTR(__FUNCTION__);

	const char *s1 = "abc";
	const char *s2 = "efg";//字符串字面常量,字符串末尾有空格
	string stra = "a";
	string strb = "b";//标准库string对象
	char *p = new char[strlen(s1) + strlen(s2) + 1];//必须指明要分配对象的个数
	strcpy_s(p,strlen(s1)+1 ,s1);//复制
	strcat_s(p,sizeof(s2), s2);//接上
	cout << p << endl;
	strcpy_s(p,strlen((stra + strb).c_str())+1, (stra + strb).c_str());//必须转换为c类型字符串(c中无string类型)
	cout << p << endl;
	delete[] p;
	return;
}

void func12_24() {
	COUTSTR(__FUNCTION__);
	string str;
	cin >> str;
	const char* strp = str.c_str();//并未使用动态内存
	char* p = new char[strlen(strp) + 1];//分配动态内存时，保证长度不变
	strcpy_s(p, strlen(strp) + 1, strp);//必须转换为c类型字符串(c中无string类型)
	cout << p << endl;
	delete [] p;//会报错,不知道为啥
	return;
}

void func12_25() {
	COUTSTR(__FUNCTION__);
	char * pa = new char[10];
	delete[] pa;
	return;
}

//
//1：new内存分配与对象构造组合在了一起，而allocator将内存分配和对象构造分离，它提供一种类型感知的内存分配方法，它分配的内存时原始的、未构造的
//2：利用allocator分配内存之后。必须在经过construnct进行构造对象，两个参数分别为：创建对象位置的指针，元素类型的值
//3：对构造后的元素进行destory操作，销毁对象，deallocator

void func12_26() {
	COUTSTR(__FUNCTION__);
	int n = 20;
	allocator<string> alloc;
	auto const p = alloc.allocate(n);
	string s;
	string *q = p;//q相当于赋值位后置位
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
	alloc.deallocate(p, n);//分配多少内存，释放多少
	return;
}

void func12_27() {
	COUTSTR(__FUNCTION__);
	ifstream infile("1.txt");
	TextQuery tq(infile);//保存给定文件数据，并建立map
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
	}//输出文本，做检验
	map<string, set<int>> map1;

	string s;
	cout << "请输入查找的单词(输入q退出)：";
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