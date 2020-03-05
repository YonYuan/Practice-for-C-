#pragma once
#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Sales_data {

public:
	//********7.11
	Sales_data() = default;
	//Sales_data():units_sold(0), revenue(0) {};//7.14
	Sales_data(const string &s) :bookNo(s) {};
	Sales_data(const string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {};
	//Sales_data(const string &s):Sales_data(s, 0, 0) {};//ί�й��캯���ĳ�ʼ����ֵ
	//Sales_data() :Sales_data(" ", 0, 0){}
	//Sales_data(std::istream &is = std::cin) { read(is, *this); }//��Ĭ��ʵ��ֱ�Ӹ����������
	//���ṩĬ��ʵ��ʱ����ΪĬ�Ϲ��캯�� ����ֵ�����˳�ʼ�������Բ����ж�����ƵĹ��캯��ͬʱ���г�ʼ��������Ĭ�Ϲ��캯���ظ�����Ĵ���
	//7.12
	Sales_data(std::istream &is) { read(is, *this); };
	//***********7.2
	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

	bool compareIsbn(Sales_data data1, Sales_data data2);

private://     ����˵�������������ǿ�ʼ֪����һ������˵������������������뱻ʹ�ø���ĳ��򿴵��Ĵ���ϸ�ڣ���Ҫprivate.
	//7.18����װʵ������Ľӿں�ʵ�ֵķ��룬���������ʵ��ϸ�ڣ��û�ֻ�ܽӴ�����Ľӿڡ�
	//	�ŵ㣺
	//	�������ʵ��ϸ�ڣ�
	//	��ʹ����ֻ��ͨ������涨�ķ������������ݣ�
	//	���Է���ļ����ȡ������䣬���Ʋ����������
	//	������İ�ȫ��������ֻ�ܱ����ʲ��ܱ��޸ģ�
	//	���ϸ�ڿ�����ʱ�ı䣬����Ҫ�޸��û�����Ĵ��룻

	//***********7.3
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold;
	double revenue;
	//7.21
	friend istream& read(istream &is, Sales_data &item);
	friend ostream& print(ostream &os, const Sales_data &item);
};
