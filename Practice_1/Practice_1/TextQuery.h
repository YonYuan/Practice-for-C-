#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include "StrBlob.h"
#include "StrVec.h"

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	~TextQuery();

	QueryResult query(const std::string& s)const;

private:
	std::shared_ptr<std::vector<std::string>> file;//Դ�ı�
	std::shared_ptr<StrBlob> fileBlob;//Դ�ı�StrBlob
	//���ʵ��кŵ�ӳ��
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
	//vector�к�
	std::map<std::string, std::shared_ptr<std::vector<line_no>>> wvec;
};

class QueryResult
{
public:
	friend std::ostream& print(std::ostream&, const QueryResult&);

public:
	QueryResult();
	~QueryResult();

	QueryResult(const std::string& s,std::shared_ptr<std::set<TextQuery::line_no>> set,
		std::shared_ptr<std::vector<std::string>> v)
		: word(s), lines(set), file(v)
	{
	}


	//QueryResult(const std::string& s, std::shared_ptr<std::vector<TextQuery::line_no>> set,
	//	std::shared_ptr<std::vector<std::string>> v)
	//	: word(s), veclines(set), file(v)
	//{
	//}

	//QueryResult(const std::string& s, std::shared_ptr<std::vector<TextQuery::line_no>> set,
	//	std::shared_ptr<StrBlob> vBlob)
	//	: word(s), veclines(set), fileBlob(vBlob)
	//{
	//}

	std::set<TextQuery::line_no>::iterator begin() const { return lines->begin(); }
	std::set<TextQuery::line_no>::iterator end() const { return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }



private:
	std::string word;//Ҫ������
	std::shared_ptr<std::set<TextQuery::line_no>> lines;//�к�
	std::shared_ptr<std::vector<std::string>> file;//Դ�ı�

	//std::shared_ptr<std::vector<TextQuery::line_no>> veclines;//vector��
	//std::shared_ptr<StrBlob> fileBlob;//Դ�ı�StrBlob

};
