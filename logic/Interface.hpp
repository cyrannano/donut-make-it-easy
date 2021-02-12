#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

struct Pos {
	int x;
	int y;
};

class Interface  
{
	private:
		winsize terminalSize;
		bool logEnabled;
	public:

		Interface();
		Interface(bool);
		~Interface();

		void updateWorkspaceSize();
		void printCharacter(Pos, char);
		void clearTerminal();
		Pos getTerminalSize();
};
#endif