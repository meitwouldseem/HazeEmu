#include "DMGCPU.h"
#include "Bus.h"

#include <iostream>

DMGCPU::DMGCPU()
{
    using a = DMGCPU;
    lookup_1 =
    {
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"INC_BC",&a::INC_BC,1},{"INC_B",&a::INC_B,1},{"DEC_B",&a::DEC_B,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"DEC_BC",&a::DEC_BC,1},{"INC_C",&a::INC_C,1},{"DEC_C",&a::DEC_C,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//0
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"INC_DE",&a::INC_DE,1},{"INC_D",&a::INC_D,1},{"DEC_D",&a::DEC_D,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"DEC_DE",&a::DEC_DE,1},{"INC_E",&a::INC_E,1},{"DEC_E",&a::DEC_E,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//1
        {"NOP",&a::NOP,1},{"LD_HL",&a::LD_HL,1},{"NOP",&a::NOP,1},{"INC_HL",&a::INC_HL,1},{"INC_H",&a::INC_H,1},{"DEC_H",&a::DEC_H,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"DEC_HL",&a::DEC_HL,1},{"INC_L",&a::INC_L,1},{"DEC_L",&a::DEC_L,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//2
        {"NOP",&a::NOP,1},{"LD_SP",&a::LD_SP,1},{"NOP",&a::NOP,1},{"INC_SP",&a::INC_SP,1},{"INC(HL)",&a::INC_HL_,1},{"DEC(HL)",&a::DEC_HL_,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"DEC_SP",&a::DEC_SP,1},{"INC_A",&a::INC_A,1},{"DEC_A",&a::DEC_A,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//3
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//4
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//5
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//6
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//7
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//8
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//9
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"XOR_B",&a::XOR_B,1},{"XOR_C",&a::XOR_C,1},{"XOR_D",&a::XOR_D,1},{"XOR_E",&a::XOR_E,1},{"XOR_H",&a::XOR_H,1},{"XOR_L",&a::XOR_L,1},{"XOR(HL)",&a::XOR_HL_,1},{"XOR_A",&a::XOR_A,1},//A
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//B
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//C
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//D
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"XOR_D8",&a::XOR_D8,1},{"NOP",&a::NOP,1},//E
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

uint8_t& DMGCPU::GetRef(uint16_t addr)
{
    return bus->getref(addr);
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

//8bit xor bindings
void DMGCPU::XOR_B() {XOR(B);}
void DMGCPU::XOR_C() {XOR(C);}
void DMGCPU::XOR_D() {XOR(D);}
void DMGCPU::XOR_E() {XOR(E);}
void DMGCPU::XOR_H() {XOR(H);}
void DMGCPU::XOR_L() {XOR(L);}
void DMGCPU::XOR_HL_() {XOR(ReadBus(read_pair(H, L)));}
void DMGCPU::XOR_A() {XOR(A);}
void DMGCPU::XOR_D8() {XOR(Imm8());}

//16bit increment bindings
void DMGCPU::INC_BC() {write_pair(read_pair(B, C)+1, B, C);}
void DMGCPU::INC_DE() {write_pair(read_pair(D, E)+1, D, C);}
void DMGCPU::INC_HL() {write_pair(read_pair(H, L)+1, H, L);}
void DMGCPU::INC_SP() {SP++;}

//8bit increment bindings
void DMGCPU::INC_B() {INC(B);}
void DMGCPU::INC_C() {INC(C);}
void DMGCPU::INC_D() {INC(D);}
void DMGCPU::INC_E() {INC(E);}
void DMGCPU::INC_H() {INC(H);}
void DMGCPU::INC_L() {INC(L);}
void DMGCPU::INC_HL_() {INC(GetRef(read_pair(H, L)));}
void DMGCPU::INC_A() {INC(A);}

//16bit decrement bindings
void DMGCPU::DEC_BC() {write_pair(read_pair(B, C)-1, B, C);}
void DMGCPU::DEC_DE() {write_pair(read_pair(D, E)-1, D, C);}
void DMGCPU::DEC_HL() {write_pair(read_pair(H, L)-1, H, L);}
void DMGCPU::DEC_SP() {SP--;}

//8bit decrement bindings
void DMGCPU::DEC_B() {DEC(B);}
void DMGCPU::DEC_C() {DEC(C);}
void DMGCPU::DEC_D() {DEC(D);}
void DMGCPU::DEC_E() {DEC(E);}
void DMGCPU::DEC_H() {DEC(H);}
void DMGCPU::DEC_L() {DEC(L);}
void DMGCPU::DEC_HL_() {DEC(GetRef(read_pair(H, L)));}
void DMGCPU::DEC_A() {DEC(A);}

//helper functions

void DMGCPU::write_pair(uint16_t val, uint8_t &hi, uint8_t &lo)
{
    hi = val >> 8;
    lo = val;
}

uint16_t DMGCPU::read_pair(uint8_t hi, uint8_t lo)
{
    return (hi << 8) | lo;
}

//XOR operations always write to the ACC (A) so this function need not return a value
void DMGCPU::XOR(uint8_t operand)
{
    A = A ^ operand;
    z = (A==0x00);
}

//16 bit increment/decrement operation does not modify flags and as such requires no generalized implementation

void DMGCPU::INC(uint8_t &operand)
{
    operand++;
    n = false;
    z = (operand==0x00);
}

void DMGCPU::DEC(uint8_t &operand)
{
    operand--;
    n = true;
    z = (operand==0x00);
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

//uint8_t DMGCPU::Ptr8()
//{
//    uint16_t offset = Imm8();
//
//    return ReadBus(0xFF00 + offset);
//}
//
//uint16_t DMGCPU::Ptr16()
//{
//    uint16_t addr = Imm16();
//
//    return ReadBus(addr);
//}
