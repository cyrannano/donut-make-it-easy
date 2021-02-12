#include "Interface.hpp"  
	
Interface::Interface(): logEnabled(false) {
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminalSize);
}

Interface::Interface(bool log = false): logEnabled(log) {
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminalSize);
	if(logEnabled) std::cout << "Interface initialised" << std::endl;
	if(logEnabled) std::cout << "Cols: " << terminalSize.ws_col << " Rows: " << terminalSize.ws_row << std::endl;
}
	
Interface::~Interface() {
	
}

void Interface::updateWorkspaceSize() {
	winsize newsize;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &newsize);

	if(newsize.ws_col != terminalSize.ws_col || newsize.ws_row != terminalSize.ws_row) {
		if(logEnabled) std::cout << "Terminal size changed" << std::endl;
		terminalSize = newsize;
		if(logEnabled) std::cout << "NewDimentions" << std::endl;
		if(logEnabled) std::cout << "Cols: " << terminalSize.ws_col << " Rows: " << terminalSize.ws_row << std::endl;
		
	}
}