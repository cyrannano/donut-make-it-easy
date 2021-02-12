#include "Interface.hpp"
#include "Cube.hpp"

int main(int argc, char** argv) {
    // Interface interface_init(true);
    Point3D middle = {0,0,0};
    Cube c1(middle);

    c1.clearTerminal();
    system("setterm -cursor off");
    int i = 1, j = 1;
    while(true) {
        // interface_init.updateWorkspaceSize();
        c1.updateWorkspaceSize();
        // c1.clearTerminal();
        c1.printCharacter({i,j}, '#');
        if(i > c1.getTerminalSize().x) {
            i = 0;
            if(j <= c1.getTerminalSize().y) j++;
            else {
                break;
            }
        }else {
            i++;
        }
        usleep(5000);
    }
    system("setterm -cursor on");

    return 0;
}