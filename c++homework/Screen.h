// Copyright [2019] <Copyright zhengxin>
#include<iostream>
#include <string>

class Screen
{
public:
	typedef std::string::size_type pos;
	//���캯��
	Screen() = default;
	Screen(const pos ht, const pos wt) : height(ht), width(wt), contents(ht * wt, ' ') { }
	Screen(const pos ht, const pos wt, const char c) : height(ht), width(wt), contents(ht * wt, c) { }
public:
	//��Ա����
	Screen& cursor_move(const pos r, const pos c)
	{
		cursor = r * width + c;
		return *this;
	}
	Screen& set_ch(const pos r, const pos c, const char ch)
	{
		contents[r * width + c] = ch;
		return *this;
	}
	Screen& set_ch(const char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen& display(void)
	{
		std::cout << contents;
		return *this;
	}

private:
	//���ݳ�Ա
	std::string contents;
	pos cursor = 0;
	pos height = 0;
	pos width = 0;
};

