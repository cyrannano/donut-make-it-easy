#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>

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

};
#endif