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

    while(true) {
        interface_init.updateWorkspaceSize();
        interface_init.clearTerminal();
        sq1.move(0.2,0.1);
        sq1.rotate(-2);
        sq1.show();
        usleep(10000);
    }
    system("setterm -cursor on");

    return 0;
}