#pragma once
#include <string>
#include <set>

class Folder;
class Message
{
public:
	friend class Folder;
public:
	explicit Message(const std::string &str = "") :contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();

	//13.33 
	//我们的目的是对传入的folder进行修改，传值的方式会使得我们修改的是其副本，const修饰符使得我们不能对其进行修改。所以都不行
	void save(Folder& f);
	void remove(Folder& f);

	void swap(Message& lhs,Message& rhs);



private:
	std::string contents;	//消息文本
	std::set<Folder*> folders;		//包含本Message的Folder

	void add_to_Folders(const Message&);
	void remove_from_Folders();

};

class Folder
{
public:
	Folder();
	~Folder();

	void remMsg(const Message* m);
	void addMsg(const Message* m);

private:
	std::set<const Message*> Msgs;
};
