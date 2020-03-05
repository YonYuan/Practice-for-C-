#pragma once
#include<vector>
#include <iostream>

class Example
{
public:
	Example();
	~Example();

	static double rate;//声名在此，定义在外，因为值仍可以改变，但是要在外面初始化
	static const int vecSize = 20;
	static std::vector<double> vec;
};

