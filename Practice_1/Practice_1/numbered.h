#pragma once
class numbered
{
public:
	numbered();
	~numbered();

	numbered(const int& num) :mysn(num) {};
	numbered(const numbered& numb) :mysn(numb.mysn+1) {};

	int mysn;
};

