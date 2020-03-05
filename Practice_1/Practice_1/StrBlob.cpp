#include "pch.h"
#include "StrBlob.h"

StrBlob::StrBlob():data(make_shared<vector<string>>())
{
}

StrBlob::~StrBlob()
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il):data(make_shared<vector<string>>(il))
{
}

//StrBlob::StrBlob(const StrBlob& strb): data(make_shared<std::vector<std::string>>(*(strb.data)))
//{
//}
//
//StrBlob & StrBlob::operator=(const StrBlob & strb)
//{
//	data = make_shared<std::vector<std::string>>(new std::vector<std::string>);
//	*data = *strb.data;
//	// TODO: 在此处插入 return 语句
//}

void StrBlob::pop_back() 
{ 
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string & StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string & StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

std::string & StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
	// TODO: 在此处插入 return 语句
}

std::string & StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
	// TODO: 在此处插入 return 语句
}
//型为size_type，是一个无符号类型，即使是负数，也会自动转化为非负。

void StrBlob::check(size_type i, const std::string & msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

StrBlobPtr::~StrBlobPtr()
{
}

//解引用
string & StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end!");
	return (*p)[curr];
	// TODO: 在此处插入 return 语句
}

//递增访问下一个位置，并检查有没有越界
StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr! ");
	++curr;
	return *this;
	// TODO: 在此处插入 return 语句
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret) {
		throw runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size())
	{
		throw out_of_range(msg);
	}
	return ret;
}


ConstStrBlobPtr::ConstStrBlobPtr()
{
}

ConstStrBlobPtr::~ConstStrBlobPtr()
{
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

