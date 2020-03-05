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
//	// TODO: �ڴ˴����� return ���
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
	// TODO: �ڴ˴����� return ���
}

std::string & StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
	// TODO: �ڴ˴����� return ���
}
//��Ϊsize_type����һ���޷������ͣ���ʹ�Ǹ�����Ҳ���Զ�ת��Ϊ�Ǹ���

void StrBlob::check(size_type i, const std::string & msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

StrBlobPtr::~StrBlobPtr()
{
}

//������
string & StrBlobPtr::deref() const
{
	auto p = check(curr, "dereference past end!");
	return (*p)[curr];
	// TODO: �ڴ˴����� return ���
}

//����������һ��λ�ã��������û��Խ��
StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr! ");
	++curr;
	return *this;
	// TODO: �ڴ˴����� return ���
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

