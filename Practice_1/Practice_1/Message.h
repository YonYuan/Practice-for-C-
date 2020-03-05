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
	//���ǵ�Ŀ���ǶԴ����folder�����޸ģ���ֵ�ķ�ʽ��ʹ�������޸ĵ����丱����const���η�ʹ�����ǲ��ܶ�������޸ġ����Զ�����
	void save(Folder& f);
	void remove(Folder& f);

	void swap(Message& lhs,Message& rhs);



private:
	std::string contents;	//��Ϣ�ı�
	std::set<Folder*> folders;		//������Message��Folder

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
