#include "DMGCPU.h"
#include "Bus.h"

#include <iostream>

DMGCPU::DMGCPU()
{

}

DMGCPU::~DMGCPU()
{
    //dtor
}

void DMGCPU::Reset()
{
    A = 0x00;
    B = 0x00;
    C = 0x00;
    D = 0x00;
    E = 0x00;
    F = 0x00;

    H = 0x00;
    L = 0x00;

    SP = 0x0000;
    PC = 0x0000;

    z = false;
    n = false;
    h = false;
    c = false;
}

void DMGCPU::WriteBus(uint16_t addr, uint8_t data)
{
    bus->write(addr, data);
}

uint8_t DMGCPU::ReadBus(uint16_t addr)
{
    return bus->read(addr);
}

void DMGCPU::RunTillStop()
{
    //we are going to go until a HALT is raised or PC exceeds 512
    try
    {
        while(PC < 0xffff)
        {
            PrintStatus();
            Advance();
        }
    }
    catch(char const*)
    {
        std::cerr << "HALT signal received" << std::endl;
    }
}

void DMGCPU::Advance()
{
    //fetch
    uint8_t opp = ReadBus(PC);
    PC++;

    //decode/execute
    Execute(opp);
}

void DMGCPU::Execute(uint8_t oppcode)
{
    if (oppcode == 0x00)
        throw "HALT";

    std::cerr << "Oppcode: " << std::hex << +oppcode << " Received" << std::endl;
}

void DMGCPU::PrintStatus()
{
    std::cout << "PC: " << std::hex << +PC << std::dec << " (" << +PC << ")" << std::endl;
}
