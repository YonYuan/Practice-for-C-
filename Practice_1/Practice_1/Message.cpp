#include "pch.h"
#include "Message.h"

Message::Message(const Message &m):
	contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);//放置在m的folders中，然后把this添加进去
}

Message & Message::operator=(const Message &rhs)
{
	//首先对左值对应的folder进行清理，合成版本不会进行该操作
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
	// TODO: 在此处插入 return 语句
}

Message::~Message()
{
	remove_from_Folders();
}

inline void Message::save(Folder & f)
{
	folders.insert(&f);
	f.addMsg(this);
}

inline void Message::remove(Folder & f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void Message::swap(Message & lhs, Message & rhs)
{
	using std::swap;
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f->remMsg(&rhs);
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}

void Message::add_to_Folders(const Message &m)
{
	for (auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(this);
}

void Folder::remMsg(const Message * m)
{
	Msgs.erase(m);
}

void Folder::addMsg(const Message * m)
{
	Msgs.insert(m);
}
