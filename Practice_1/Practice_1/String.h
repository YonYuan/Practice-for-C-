#pragma once
#include <memory>

class String
{
public:
	String() { String(""); };
	String(const char* ch) ;
	String(const String&);
	String& operator=(const String&);
	~String();

	size_t size() const { return first_free - elements; }		//����ʹ�õ�Ԫ����Ŀ
	char *begin()const { return elements; }
	char *end()const { return first_free; }

	void show() { for (auto ich = elements; ich != first_free; ++ich) std::cout << *ich; cout << std::endl; }

private:
	std::allocator<char> alloc;

	void free();
	std::pair<char*, char*> alloc_n_copy(const char*a, const char*b);
	void range_initializer(const char*a, const char*b);

	char *elements;		//ָ����Ԫ��
	char *first_free;	//ָ���һ������Ԫ��
};

