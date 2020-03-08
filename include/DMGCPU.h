#ifndef DMGCPU_H
#define DMGCPU_H

#include <cstdint>
#include <string>
#include <vector>

class Bus;

class DMGCPU
{
    /*

    Register layout

    ---------
    | A | F |
    ---------
    | B | C |
    ---------
    | D | E |
    ---------
    | H | L |
    ---------
    |  SP   |
    ---------
    |  PC   |
    ---------

    */

    //F register should probably not be here.
public:
    uint8_t A = 0x00;//accumulator
    uint8_t F = 0x00;//flags (Ignore)
    uint8_t B = 0x00;
    uint8_t C = 0x00;
    uint8_t D = 0x00;
    uint8_t E = 0x00;
    uint8_t H = 0x00;
    uint8_t L = 0x00;

    uint16_t SP = 0x0000;//stack pointer
    uint16_t PC = 0x0000;//program counter

    //Flags
    bool z = false;//zero
    bool n = false;//subtract
    bool h = false;//half carry (Ignore)
    bool c = false;//carry

private:
    Bus *bus = nullptr;

public:
    DMGCPU();
    ~DMGCPU();

    void ConnectBus(Bus *n) { bus = n; }

    void WriteBus(uint16_t addr, uint8_t data);
    uint8_t ReadBus(uint16_t addr);

    void Advance();

    void Reset();
    void RunTillStop();
    void PrintStatus();

private:
    void Execute(uint8_t oppcode);

    //instruction set implementation

    struct INSTRUCTION
    {
        std::string name = "Null";
        void (DMGCPU::*opp)() = nullptr;
        uint8_t cycles = 0;
    };

    std::vector<INSTRUCTION> lookup_1;

    //instruction bindings

    void NOP();

    void LD_SP();

    void XOR_B();
    void XOR_C();
    void XOR_D();
    void XOR_E();
    void XOR_H();
    void XOR_L();
    void XOR_HL();
    void XOR_A();
    void LD_HL();

    //instruction behaviour implementations

    void XOR(uint8_t operand);

    //Read and write HL

    void write_HL(uint16_t val);
    uint16_t read_HL();

    //Addressing modes

    uint8_t Imm8();
    uint16_t Imm16();
    uint8_t Ptr8();
    uint16_t Ptr16();
};

#endif // DMGCPU_H
