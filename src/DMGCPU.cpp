#include "DMGCPU.h"
#include "Bus.h"

#include <iostream>

DMGCPU::DMGCPU()
{
    using a = DMGCPU;
    lookup_1 =
    {
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//0
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//1
        {"NOP",&a::NOP,1},{"LD_HL",&a::LD_HL,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//2
        {"NOP",&a::NOP,1},{"LD_SP",&a::LD_SP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//3
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//4
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//5
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//6
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//7
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//8
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//9
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"XOR_B",&a::XOR_B,1},{"XOR_C",&a::XOR_C,1},{"XOR_D",&a::XOR_D,1},{"XOR_E",&a::XOR_E,1},{"XOR_H",&a::XOR_H,1},{"XOR_L",&a::XOR_L,1},{"XOR_HL",&a::XOR_HL,1},{"XOR_A",&a::XOR_A,1},//A
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//B
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//C
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//D
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//E
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1}//F
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
    cout << "A: " << hex << +A << dec << " (" << +A << ")" << endl;
    cout << "B: " << hex << +B << dec << " (" << +B << ")" << endl;
    cout << "C: " << hex << +C << dec << " (" << +C << ")" << endl;
    cout << "D: " << hex << +D << dec << " (" << +D << ")" << endl;
    cout << "E: " << hex << +E << dec << " (" << +E << ")" << endl;
    cout << "HL: " << hex << +read_pair(H, L) << dec << " (" << +read_pair(H, L) << ")" << endl;
    cout << "SP: " << hex << +SP << dec << " (" << +SP << ")" << endl;
    cout << "PC: " << hex << +PC << dec << " (" << +PC << ")" << endl;
    cout << "Flags:  z=" << z << " n=" << n << " h=" << h << " c=" << c << endl;
}

//Instruction set bindings

void DMGCPU::NOP() {return;}

void DMGCPU::LD_SP() {SP = Imm16();}
void DMGCPU::LD_HL() {write_pair(Imm16(), H, L);}

void DMGCPU::XOR_B() {XOR(B);}
void DMGCPU::XOR_C() {XOR(C);}
void DMGCPU::XOR_D() {XOR(D);}
void DMGCPU::XOR_E() {XOR(E);}
void DMGCPU::XOR_H() {XOR(H);}
void DMGCPU::XOR_L() {XOR(L);}
void DMGCPU::XOR_HL() {XOR(ReadBus(read_pair(H, L)));}
void DMGCPU::XOR_A() {XOR(A);}

void DMGCPU::write_pair(uint16_t val, uint8_t &hi, uint8_t &lo)
{
    hi = val >> 8;
    lo = val;
}

uint16_t DMGCPU::read_pair(uint8_t hi, uint8_t lo)
{
    return (hi << 8) | lo;
}

//instruction behaviour implementations

//XOR operations always target the ACC (A) so this function need not return a value
void DMGCPU::XOR(uint8_t operand)
{
    A = A ^ operand;
    if (A == 0x00)
        z=true;
}

//addressing modes

uint8_t DMGCPU::Imm8()
{
    uint8_t byte = ReadBus(PC);
    PC++;
    return byte;
}

uint16_t DMGCPU::Imm16()
{
    //hi and lo need to be 16 bit integers to make space for the bit shift

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
