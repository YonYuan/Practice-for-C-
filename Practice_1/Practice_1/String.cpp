#include "pch.h"
#include "String.h"
#include <algorithm>


String::String(const char * ch)
{
	size_t _size = strlen(ch);
	range_initializer(ch, ch + _size);
	//first_free=std::uninitialized_copy(ch, ch+_size+1, elements);
}

String::String(const String & rhs)
{
	range_initializer(rhs.elements, rhs.first_free);
	COUTSTR("�������캯��ing")
}

String & String::operator=(const String &rhs)
{

	auto newstr = alloc_n_copy(rhs.elements, rhs.first_free);
	free();
	elements = newstr.first;
	first_free = newstr.second;
	COUTSTR("���ƿ��������ing");
	return *this;
	// TODO: �ڴ˴����� return ���
}

String::~String()
{
	free();
}

std::pair<char*, char*> String::alloc_n_copy(const char * a, const char * b)
{
	auto s1 = alloc.allocate(b - a);//allocate����Ϊ�����ڴ�Ĵ�С
	auto s2 = std::uninitialized_copy(a, b, s1);//������ֵ����a��b֮���Ԫ�ؿ�����s1,���ص������һ������Ԫ��֮���λ��
	return std::make_pair(s1, s2);//������βָ��
}

void String::range_initializer(const char * a, const char * b)
{
	auto _t =alloc_n_copy(a, b);
	elements = _t.first;
	first_free = _t.second;
}

void String::free()
{
	if (elements) {
		std::for_each(elements, first_free, [this](char &rhs) {alloc.destroy(&rhs);
		});
		alloc.deallocate(elements, first_free - elements);
	}
}
