#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <math.h>

struct Pos {
	double x;
	double y;
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
		void printCharacter(Pos, std::string);
		void clearTerminal();
		Pos getTerminalSize();
		bool rayCasting(Pos);
};
#endif