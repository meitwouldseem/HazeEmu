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
    uint8_t& GetRef(uint16_t addr);

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

    // _ at the end of a binding denotes 16bit reg being used as a pointer
    // D8 means 8bit immediate data

    void NOP();

    void LD_SP();
    void LD_HL();

    //8bit xor bindings
    void XOR_B();
    void XOR_C();
    void XOR_D();
    void XOR_E();
    void XOR_H();
    void XOR_L();
    void XOR_HL_();
    void XOR_A();
    void XOR_D8();

    //16bit increment bindings
    void INC_BC();
    void INC_DE();
    void INC_HL();
    void INC_SP();

    //8bit increment bindings
    void INC_B();
    void INC_C();
    void INC_D();
    void INC_E();
    void INC_H();
    void INC_L();
    void INC_HL_();
    void INC_A();

    //16bit decrement bindings
    void DEC_BC();
    void DEC_DE();
    void DEC_HL();
    void DEC_SP();

    //8bit decrement bindings
    void DEC_B();
    void DEC_C();
    void DEC_D();
    void DEC_E();
    void DEC_H();
    void DEC_L();
    void DEC_HL_();
    void DEC_A();

    //instruction behaviour implementations

    void XOR(uint8_t operand);

    void INC(uint8_t &operand);
    void INC(uint8_t &hi, uint8_t &lo);
    void DEC(uint8_t &operand);
    void DEC(uint8_t &hi, uint8_t &lo);

    //Read and write HL

    void WritePair(uint16_t val, uint8_t &hi, uint8_t &lo);
    uint16_t ReadPair(uint8_t hi, uint8_t lo);

    //Addressing modes

    uint8_t Imm8();
    uint16_t Imm16();
    uint8_t Ptr8();
    uint16_t Ptr16();
};

#endif // DMGCPU_H
