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
#endif//constexpr���������з���ֵ��������return��䡣
	//����ֵ�����ࣺ���ݳ�Ա��������ֵ���͵ľۺ���
	//����ֵ���ͣ��������͡�ָ�롢���ã���������ֵ���͵��У�IO�⡢String����
	//����ֵ������Ĺ��캯��������constexpr, һ����˵Ϊ��
	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }
private:
	bool hw;    // hardware errors other than IO errors
	bool io;    // IO errors
	bool other; // other errors
};

