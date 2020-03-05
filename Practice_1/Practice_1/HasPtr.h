#pragma once
#include <string>
#include <vector>

//��ָ���HasPtr

class HasPtr
{
public:
	//����ֵ������
	//friend void swap(HasPtr&, HasPtr&);
	friend bool operator<(const HasPtr& s1, const HasPtr& s2);
	friend void show(std::vector<HasPtr>&);

public:
	HasPtr(const std::string &s = std::string()) :ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	~HasPtr();

	//ָ��ָ�����ڴ�
	HasPtr(const HasPtr& HP) :ps(HP.ps), i(HP.i), use(HP.use) { ++*use; }
	//������������ռ���ڴ棬���� ���ߵ����ͷ�����һ����

	//ָ��ָ��ͬһ���ڴ�
	HasPtr& operator=(const HasPtr& );


private:
	std::string *ps;
	int i;
	
	std::size_t *use;
};

