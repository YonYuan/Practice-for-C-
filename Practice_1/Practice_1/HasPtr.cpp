#include "pch.h"
#include "HasPtr.h"
#include <iostream>

using std::cout;
using std::endl;

//���캯���У�����Ķ�̬�ڴ������Ҫdelete
HasPtr::~HasPtr()
{
	if (--*use == 0) {
		delete ps;
		delete use;
	}
	std::cout<<"�������������������ٶ���"<<std::endl;
}

HasPtr& HasPtr::operator=(const HasPtr & rhs)
{
	++*rhs.use;
	if (--*use == 0) {
		delete ps;//����ɾ��ԭ�ڴ�
		delete use;
	}

	////��ʱֵ��֤�Ը�ֵ������
	//std::string *p = new std::string(*rhs.ps);//new���ص���ָ�������ڴ桢�����˶����ָ��
	//ps = p;

	ps = rhs.ps;
	//ֱ�Ӹ�ֵ��������ָ��ͬʱָ����ͬ�ײ��ڴ棬Ȼ��������ʱ�����ظ��ͷŵĴ���������ζ�������������ָ���ظ�������ͬ���ڴ�
	//ʹ�����ü�����ʱ����⿼��

	i = rhs.i;
	use = rhs.use;
	return *this;
	// TODO: �ڴ˴����� return ���
}

//���¶����swapӦ����ֵ���͵���
//void swap(HasPtr &lhs, HasPtr &rhs)
//{
//
//	COUTSTR("do swap");
//	using std::swap;
//	swap(lhs.ps, rhs.ps);
//	swap(lhs.i, rhs.i);
//}

bool operator<(const HasPtr & s1, const HasPtr & s2)
{
	COUTSTR("do <");
	return *s1.ps < *s2.ps;
}

void show(std::vector<HasPtr>& vec)
{
	std::vector<HasPtr>::iterator it1 = vec.begin();
	for (it1; it1 != vec.end(); ++it1)
	{
		cout << *(it1->ps) << endl;
	}
}
