#include "pch.h"
#include "TextQuery.h"

using namespace std;

TextQuery::TextQuery(ifstream &infile) : file(new vector<string>)
{
	for (string line; getline(infile,line);)
	{
		file->push_back(line);
		fileBlob->push_back(line);
		line_no lineNo = file->size() - 1;
		istringstream line_stream(line);//sitringstream文本分解单词
		
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			//use reference avoid count of shared_ptr add.
			auto& lines = wm[word];//返回map的secound
			if (!lines) lines.reset(new std::set<line_no>);
			lines->insert(lineNo);
			//如果用vector
			//auto& lines2 = wvec[word];//返回map的secound
			//if (!lines2) lines.reset(new std::vector<line_no>);
			//lines2->push_back(lineNo);
		}
	}
}

TextQuery::~TextQuery()
{
}

QueryResult TextQuery::query(const string & str)const
{

	// use static just allocate once.
	static shared_ptr<set<line_no>> nodate(new std::set<line_no>);
	auto found = wm.find(str);
	if (found == wm.end())
		return QueryResult(str, nodate, file);
	else
		return QueryResult(str, found->second, file);

	//auto foundvec = wvec.find(str);
	//if (foundvec == wvec.end())
	//	return QueryResult(str, nodate, file);
	//else
	//	return QueryResult(str, found->second, file);
}

QueryResult::QueryResult()
{
}

QueryResult::~QueryResult()
{
}

std::ostream& print(std::ostream& out, const QueryResult& qr) {

	out << qr.word << " occurs " << qr.lines->size()
		<< (qr.lines->size() > 1 ? " times" : " time") << std::endl;
	for (auto i : *qr.lines)
		out << "\t(line " << i + 1 << ") " << qr.file->at(i) << std::endl;
	return out;

}
