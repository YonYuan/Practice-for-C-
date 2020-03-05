#pragma once
class Debug
{
public:
	Debug();
	~Debug();

#ifdef CONSTEXPR_CTORS
	constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
	constexpr Debug(bool h, bool i, bool o) :
		hw(h), io(i), other(o) { }
	constexpr bool any() { return hw || io || other; }
	constexpr bool hardware() { return hw || io; }
	constexpr bool app() { return other; }
#else
	Debug(bool b = true) : hw(b), io(b), other(b) { }
	Debug(bool h, bool i, bool o) :
		hw(h), io(i), other(o) { }
	bool any() const { return hw || io || other; }
	bool hardware() const { return hw || io; }
	bool app() const { return other; }
#endif//constexpr函数必须有返回值，必须有return语句。
	//字面值常量类：数据成员都是字面值类型的聚合类
	//字面值类型：算术类型、指针、引用，不是字面值类型的有：IO库、String类型
	//字面值常量类的构造函数可以是constexpr, 一般来说为空
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }
private:
	bool hw;    // hardware errors other than IO errors
	bool io;    // IO errors
	bool other; // other errors
};

