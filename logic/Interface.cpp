#include "Interface.hpp"  
	
Interface::Interface(): logEnabled(true) {
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminalSize);
}

Interface::Interface(bool log = true): logEnabled(log) {
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
        clearTerminal();
		if(logEnabled) std::cout << "Terminal size changed" << std::endl;
		terminalSize = newsize;
		if(logEnabled) std::cout << "NewDimentions" << std::endl;
		if(logEnabled) std::cout << "Cols: " << terminalSize.ws_col << " Rows: " << terminalSize.ws_row << std::endl;
		
	}
}

void Interface::printCharacter(Pos p, std::string c) {
	printf("%c[%d;%df", 0x1B, (int)round(p.y/2.0), (int)round(p.x));
	std::cout << c;
	fflush(stdout);
}

void Interface::clearTerminal() {
	printf("\033[2J");
	printf("\033[1;1H");
}

Pos Interface::getTerminalSize() {
	return {(double)terminalSize.ws_col, (double)terminalSize.ws_row};
}
