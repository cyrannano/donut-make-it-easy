#include "Interface.hpp"
#include "Cube.hpp"
#include "Square.hpp"

Interface interface_init(true);

int main(int argc, char** argv) {
    Point3D middle = {0,0,0};
    Cube c1(middle);
    Square sq1(30, 25, 15);

    c1.clearTerminal();
    system("setterm -cursor off");
    int i = 1, j = 1;
    int movex = 1; int movey = 1;
    while(true) {
        interface_init.updateWorkspaceSize();
        interface_init.clearTerminal();
        movex = (sq1.getPostion().x + (sq1.getSize()/2) > interface_init.getTerminalSize().x || 
                     sq1.getPostion().x - (sq1.getSize()/2) < 0) ? movex*(-1) : movex;
        movey = (sq1.getPostion().y + (sq1.getSize()/2) > interface_init.getTerminalSize().y*2 || 
                     sq1.getPostion().y - (sq1.getSize()/2) < 0) ? movey*(-1) : movey;
        sq1.move(0.2*movex,0.1*movey);
        sq1.rotate(-2);
        sq1.show();
        usleep(10000);
    }
    system("setterm -cursor on");

    return 0;
}