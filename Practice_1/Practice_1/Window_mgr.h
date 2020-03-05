#pragma once
#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <string>
#include <iostream>
#include <vector>
#include "Screen.h"

using namespace std;

class Window_mgr
{
public:
	using ScreenIndex = vector<Screen>::size_type;

	Window_mgr();
	~Window_mgr();

	void clear(ScreenIndex);

private:
	std::vector<Screen> screens{ Screen(24,80,' ') };
};

void Window_mgr::clear(ScreenIndex i)
{
	// s is a reference to the Screen we want to clear
	Screen &s = screens[i];
	// reset the contents of that Screen to all blanks
	s.contents = std::string(s.height * s.width, ' ');
}

#endif // !WINDOW_MGR_H

