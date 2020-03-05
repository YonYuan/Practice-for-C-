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
	size_t size() const { return first_free - elements; }		//正在使用的元素数目
	size_t capacity()const { return cap - elements; }			//返回可以保存的元素数目，容器大小
	std::string *begin()const { return elements; }
	std::string *end()const { return first_free; }

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const std::string & s);

private:
	std::allocator<std::string> alloc;

	void chk_n_alloc(){ if(size()==capacity()) reallocate();}
	//检查并重新分配内存
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void alloc_n_move(size_t new_cap);

	void free();				//销毁元素并释放内存
	void reallocate();			//重新分配内存

	std::string *elements;		//指向首元素
	std::string *first_free;	//指向第一个空闲元素
	std::string *cap;			//指向数组为侯位置的指针
};

