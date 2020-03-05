#pragma once
#include <string>
#include <memory>

class StrVec
{
public:
	StrVec() :elements(nullptr), first_free(nullptr), cap(nullptr) {};
	StrVec(std::initializer_list<std::string> l_str);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	StrVec(const StrVec&&);
	StrVec& operator=(const StrVec);
	~StrVec();

	void push_back(const std::string&);
	size_t size() const { return first_free - elements; }		//����ʹ�õ�Ԫ����Ŀ
	size_t capacity()const { return cap - elements; }			//���ؿ��Ա����Ԫ����Ŀ��������С
	std::string *begin()const { return elements; }
	std::string *end()const { return first_free; }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const std::string & s);

private:
	std::allocator<std::string> alloc;

	void chk_n_alloc(){ if(size()==capacity()) reallocate();}
	//��鲢���·����ڴ�
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void alloc_n_move(size_t new_cap);

	void free();				//����Ԫ�ز��ͷ��ڴ�
	void reallocate();			//���·����ڴ�

	std::string *elements;		//ָ����Ԫ��
	std::string *first_free;	//ָ���һ������Ԫ��
	std::string *cap;			//ָ������Ϊ��λ�õ�ָ��
};

