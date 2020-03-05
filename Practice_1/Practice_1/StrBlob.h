#pragma once
#include <vector>
#include <memory>
using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
public:
	StrBlobPtr begin();
	StrBlobPtr end();
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	~StrBlob();
	StrBlob(std::initializer_list<std::string> il);

	//StrBlob(const StrBlob&);
	//StrBlob& operator=(const StrBlob& );


	//  explicit�����þ������ƹ��캯������ʽת��
	//	�ŵ㣺�����Զ��Ľ�������ת�������������֪��������
	//	ȱ�㣺�����ù��캯����ʾ����һ�����󣬲��������

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	std::string& front();
	std::string& back();
	std::string& front() const;
	std::string& back() const;

private:
	std::shared_ptr<std::vector<std::string>> data;

	void check(size_type i, const std::string &msg)const;

public:

};

class StrBlobPtr
{
public:
	StrBlobPtr() :curr(0) {}
	~StrBlobPtr();
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {};

	string& deref() const;
	StrBlobPtr& incr();
	const size_t getCurr() const { return curr; }

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	//����
	weak_ptr<vector<string>> wptr;//ָ��ǰ���ݵ�����������ָ��
	size_t curr;//vector�е�λ��
};

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr();
	~ConstStrBlobPtr();

	ConstStrBlobPtr(const StrBlob& a,const size_t sz = 0) :wptr(a.data), curr(sz) {};

private:
	weak_ptr<vector<string>> wptr;//ָ��ǰ���ݵ�����������ָ��
	size_t curr;//vector�е�λ��
};
