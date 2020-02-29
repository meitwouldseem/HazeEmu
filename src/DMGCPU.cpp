#include "DMGCPU.h"
#include "Bus.h"

#include <iostream>

DMGCPU::DMGCPU()
{
    using a = DMGCPU;
    lookup_1 =
    {
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"LD_SP_16",&a::LD_SP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1}
    };
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
        std::cout << "HALT signal received" << std::endl;
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

    std::cout << "Oppcode: " << std::hex << +oppcode << " Received" << std::endl;

    (this->*lookup_1[oppcode].opp)();
}

void DMGCPU::PrintStatus()
{
    using namespace std;
    cout << "PC: " << hex << +PC << dec << " (" << +PC << ")" << endl;
    cout << "SP: " << hex << +SP << dec << " (" << +SP << ")" << endl;
}

//Instruction set implementation

void DMGCPU::NOP() {return;}

void DMGCPU::LD_SP() {SP = Imm16();}

uint8_t DMGCPU::Imm8()
{
    uint8_t byte = ReadBus(PC);
    PC++;
    return byte;
}

uint16_t DMGCPU::Imm16()
{
    //These need to be 16 bit integers to make space for the bit shift

    uint16_t lo = ReadBus(PC);
    PC++;
    uint16_t hi = ReadBus(PC);
    PC++;

    return (hi << 8) | lo;
}

uint8_t DMGCPU::Ptr8()
{
    uint16_t offset = Imm8();

    return ReadBus(0xFF00 + offset);
}

uint16_t DMGCPU::Ptr16()
{
    uint16_t addr = Imm16();

    return ReadBus(addr);
}
