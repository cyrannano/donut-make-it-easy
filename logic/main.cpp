#include "Interface.hpp"

int main(int argc, char* argv[]) {
    Interface interface_init(true);

    while(true) {
        interface_init.updateWorkspaceSize();
    }
    return 0;
}