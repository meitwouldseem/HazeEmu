#include "Bus.h"

Bus::Bus()
{
    cpu.ConnectBus(this);
}

Bus::~Bus()
{
    //dtor
}

void Bus::write(uint16_t addr, uint8_t data)
{
    if (addr >= 0x0000 && addr <= 0xffff)
        ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr)
{
    if (addr >= 0x0000 && addr <= 0x00ff) {
        return bootrom[addr];
    } else if (addr >= 0x0000 && addr <= 0xffff) {
        return ram[addr];
    }

    return 0x00;
}
