#include <iostream>

#include "Bus.h"

int main()
{
    Bus* gameboy = new Bus();

    gameboy->cpu.A = 0x11;

    gameboy->cpu.RunTillStop();

    return 0;
}
