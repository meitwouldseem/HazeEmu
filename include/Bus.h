#ifndef BUS_H
#define BUS_H

#include <cstdint>
#include "DMGCPU.h"

class Bus
{
    public:
        Bus();
        ~Bus();

        void write(uint16_t addr, uint8_t data);
        uint8_t read(uint16_t addr);//might need bool readonly = false as arg 2 here. Don't know yet

        //devices on the bus go under this line.

        DMGCPU cpu;

        //This ram spans the entire length of the bus at the moment
        std::array<uint8_t, 64 * 1024> ram;

};

#endif // BUS_H
