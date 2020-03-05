#pragma once
#include <iostream>
#include <vector>

using namespace std;

//*******6.54
int f(int a, int b);

void Practice_6_54() {
	using PF = int(*)(int, int);
	using PF2 = decltype(f)(*);
	typedef int(*PF3)(int, int);
	std::vector<PF> a;//用的是函数指针形参
}

//*******6.55 6.56
int fadd(int a, int b){return a + b;}
int fsubtract(int a, int b) { return a - b; }
int fmultiply(int a, int b) { return a * b; }
int fdivide(int a, int b) { return b != 0 ? a / b : 0; }//声明定义函数

void Practice_6_55() {
	using PF = int(*)(int, int);
	std::vector<PF> a{fadd, fsubtract, fmultiply, fdivide };//初始化
	
	for (auto f : a) {
		cout << f(2, 2) << endl;
	}
	return;
}
//*******


