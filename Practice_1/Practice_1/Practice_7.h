#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Sales_data.h"
using namespace std;

//***********7.1
//֪ʶ��1�����캯��������ĳ�Ա�������������ƶ���ĳ�ʼ�����̡��޷������ͣ������أ����ܱ�����Ϊconst.
//֪ʶ��2�����ޣ�����Ĭ�ϵĹ��캯�����Ǳ������Լ���ʽ�Ķ���ġ��ֳƺϳɵ�Ĭ�Ϲ��캯����
//֪ʶ��3��ĳЩ���ǲ���ʹ��Ĭ�ϵĹ��캯���ģ���������ԭ��
//1����δ�����κι��캯����ǰ���£����ڶ���ĳ�ʼ�������ܿ���
//2���ϳɵ�Ĭ�Ϲ��캯�����ܻ���ɲ���Ҫ�Ĵ�������û�����ڳ�ʼֵ����ʼ����Ա��������Щ��Ա����δ����ġ�
//3��������а�����һ�����������͵ĳ�Ա���������Ա������û��Ĭ�Ϲ��캯������ô���������޷���ʼ���ö���
//���ԣ���׫д���ʱ����ö���һ���Լ��Ĺ��캯����

int Practice_7() {
	//Sales_data total;
	//Ĭ�Ϲ��캯������7.11
	Sales_data testConstructor1;
	Sales_data testConstructor2("testConstructor2_bookNo");
	Sales_data testConstructor3("testConstructor2_bookNo", 12, 30);
	Sales_data testConstructor4(cin);
	Sales_data total(cin);
	if (cin) {
		//7.13
		Sales_data trans(cin);
		do
		{
			if (total.isbn() == trans.isbn()) {
				//total.units_sold += trans.units_sold;
				//total.revenue += trans.revenue;
				//***********7.3
				total.combine(trans);
			}
			else {
				print(cout, total) << endl;
				total = trans;
			}
		} while (read(cin, trans));
		print(cout, total) << endl;
	}
	else {
		std::cerr << "No data?!" << std::endl;
		return -1;
	}
	return 0;
}
