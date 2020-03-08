#include <iostream>

#include "Bus.h"

int main()
{
    Bus* gameboy = new Bus();

    gameboy->cpu.RunTillStop();

    return 0;
}
