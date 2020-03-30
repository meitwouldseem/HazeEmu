#include <iostream>
#include <string>

#include "Bus.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        string arg1 = argv[1];

        if (arg1 == "-h")
        {
            cout << "Options:\n"
                "  -h   :   Display this help info\n"
                "  -i   :   Start the emulator in interactive mode\n";
            return 0;
        }
        else if (arg1 == "-i")
        {

        }
        else
        {
            cout << "Argument not recognized/n";
        }
    }


    Bus* gameboy = new Bus();

    gameboy->cpu.RunTillStop();

    return 0;
}
