#pragma once
#include<vector>
#include <iostream>

class Example
{
public:
	Example();
	~Example();

	static double rate;//�����ڴˣ��������⣬��Ϊֵ�Կ��Ըı䣬����Ҫ�������ʼ��
	static const int vecSize = 20;
	static std::vector<double> vec;
};

