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
    void HALT();

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

    //8bit load bindings (A)
    void LD_A_B();
    void LD_A_C();
    void LD_A_D();
    void LD_A_E();
    void LD_A_H();
    void LD_A_L();
    void LD_A_HL_();
    //void LD_A_A();
    void LD_A_D8();

    //8bit load bindings (B)
    //void LD_B_B();
    void LD_B_C();
    void LD_B_D();
    void LD_B_E();
    void LD_B_H();
    void LD_B_L();
    void LD_B_HL_();
    void LD_B_A();
    void LD_B_D8();

    //8bit load bindings (C)
    void LD_C_B();
    //void LD_C_C();
    void LD_C_D();
    void LD_C_E();
    void LD_C_H();
    void LD_C_L();
    void LD_C_HL_();
    void LD_C_A();
    void LD_C_D8();

    //8bit load bindings (D)
    void LD_D_B();
    void LD_D_C();
    //void LD_D_D();
    void LD_D_E();
    void LD_D_H();
    void LD_D_L();
    void LD_D_HL_();
    void LD_D_A();
    void LD_D_D8();

    //8bit load bindings (E)
    void LD_E_B();
    void LD_E_C();
    void LD_E_D();
    //void LD_E_E();
    void LD_E_H();
    void LD_E_L();
    void LD_E_HL_();
    void LD_E_A();
    void LD_E_D8();

    //8bit load bindings (H)
    void LD_H_B();
    void LD_H_C();
    void LD_H_D();
    void LD_H_E();
    //void LD_H_H();
    void LD_H_L();
    void LD_H_HL_();
    void LD_H_A();
    void LD_H_D8();

    //8bit load bindings (L)
    void LD_L_B();
    void LD_L_C();
    void LD_L_D();
    void LD_L_E();
    void LD_L_H();
    //void LD_L_L();
    void LD_L_HL_();
    void LD_L_A();
    void LD_L_D8();

    void LD_HL_B_();
    void LD_HL_C_();
    void LD_HL_D_();
    void LD_HL_E_();
    void LD_HL_H_();
    void LD_HL_L_();
    void LD_HL_A_();
    void LD_HL_D8_();

    void LD_BC_A_();
    void LD_DE_A_();
    void LD_A_BC_();
    void LD_A_DE_();

    void LD_HLp_A_();
    void LD_HLm_A_();
    void LD_A_HLp_();
    void LD_A_HLm_();

    //instruction behaviour implementations

    void XOR(uint8_t operand);

    void INC(uint8_t &operand);
    void INC(uint8_t &hi, uint8_t &lo);
    void DEC(uint8_t &operand);
    void DEC(uint8_t &hi, uint8_t &lo);

    //Read and write HL

    void WritePair(uint16_t val, uint8_t &hi, uint8_t &lo);
    uint16_t ReadPair(uint8_t hi, uint8_t lo);

    //Increment/Decrement pair

    void IncrementPair(uint8_t &hi, uint8_t &lo);
    void DecrementPair(uint8_t &hi, uint8_t &lo);

    //Addressing modes

    uint8_t Imm8();
    uint16_t Imm16();
    uint8_t Ptr8();
    uint16_t Ptr16();
};

#endif // DMGCPU_H
