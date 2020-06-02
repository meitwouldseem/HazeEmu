#include "DMGCPU.h"
#include "Bus.h"

#include <iostream>

DMGCPU::DMGCPU()
{
    using a = DMGCPU;
    lookup_1 =
    {
        {"NOP",&a::NOP,1}          ,{"LD_BC",&a::LD_BC,1}     ,{"LD(BC)A",&a::LD_BC_A_,1}  ,{"INC_BC",&a::INC_BC,1}   ,{"INC_B",&a::INC_B,1}     ,{"DEC_B",&a::DEC_B,1}     ,{"LD_B_D8",&a::LD_B_D8,1}   ,{"NOP",&a::NOP,1}         ,{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"LD_A(BC)",&a::LD_A_BC_,1},{"DEC_BC",&a::DEC_BC,1},{"INC_C",&a::INC_C,1},{"DEC_C",&a::DEC_C,1},{"LD_C_D8",&a::LD_C_D8,1},{"NOP",&a::NOP,1},//0
        {"NOP",&a::NOP,1}          ,{"LD_DE",&a::LD_DE,1}     ,{"LD(DE)A",&a::LD_DE_A_,1}  ,{"INC_DE",&a::INC_DE,1}   ,{"INC_D",&a::INC_D,1}     ,{"DEC_D",&a::DEC_D,1}     ,{"LD_D_D8",&a::LD_D_D8,1}   ,{"RLA",&a::RLA,1}         ,{"JR_D8",&a::JR_D8,1},{"NOP",&a::NOP,1},{"LD_A(DE)",&a::LD_A_DE_,1},{"DEC_DE",&a::DEC_DE,1},{"INC_E",&a::INC_E,1},{"DEC_E",&a::DEC_E,1},{"LD_E_D8",&a::LD_E_D8,1},{"NOP",&a::NOP,1},//1
        {"JR_NZ_D8",&a::JR_NZ_D8,1},{"LD_HL",&a::LD_HL,1}     ,{"LD(HL+)A",&a::LD_HLp_A_,1},{"INC_HL",&a::INC_HL,1}   ,{"INC_H",&a::INC_H,1}     ,{"DEC_H",&a::DEC_H,1}     ,{"LD_H_D8",&a::LD_H_D8,1}   ,{"NOP",&a::NOP,1}         ,{"JR_Z_D8",&a::JR_Z_D8,1},{"NOP",&a::NOP,1},{"LD_A(HL+)",&a::LD_A_HLp_,1},{"DEC_HL",&a::DEC_HL,1},{"INC_L",&a::INC_L,1},{"DEC_L",&a::DEC_L,1},{"LD_L_D8",&a::LD_L_D8,1},{"NOP",&a::NOP,1},//2
        {"NOP",&a::NOP,1}          ,{"LD_SP",&a::LD_SP,1}     ,{"LD(HL-)A",&a::LD_HLm_A_,1},{"INC_SP",&a::INC_SP,1}   ,{"INC(HL)",&a::INC_HL_,1} ,{"DEC(HL)",&a::DEC_HL_,1} ,{"LD(HL)D8",&a::LD_HL_D8_,1},{"NOP",&a::NOP,1}         ,{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"LD_A(HL-)",&a::LD_A_HLm_,1},{"DEC_SP",&a::DEC_SP,1},{"INC_A",&a::INC_A,1},{"DEC_A",&a::DEC_A,1},{"LD_A_D8",&a::LD_A_D8,1},{"NOP",&a::NOP,1},//3
        {"LD_B_B",&a::NOP,1}       ,{"LD_B_C",&a::LD_B_C,1}   ,{"LD_B_D",&a::LD_B_D,1}     ,{"LD_B_E",&a::LD_B_E,1}   ,{"LD_B_H",&a::LD_B_H,1}   ,{"LD_B_L",&a::LD_B_L,1}   ,{"LD_B(HL)",&a::LD_B_HL_,1} ,{"LD_B_A",&a::LD_B_A,1}   ,{"LD_C_B",&a::LD_C_B,1},{"LD_C_C",&a::NOP,1}   ,{"LD_C_D",&a::LD_C_D,1},{"LD_C_E",&a::LD_C_E,1},{"LD_C_H",&a::LD_C_H,1},{"LD_C_L",&a::LD_C_L,1},{"LD_C(HL)",&a::LD_C_HL_,1},{"LD_C_A",&a::LD_C_A,1},//4
        {"LD_D_B",&a::LD_D_B,1}    ,{"LD_D_C",&a::LD_D_C,1}   ,{"LD_D_D",&a::NOP,1}        ,{"LD_D_E",&a::LD_D_E,1}   ,{"LD_D_H",&a::LD_D_H,1}   ,{"LD_D_L",&a::LD_D_L,1}   ,{"LD_D(HL)",&a::LD_D_HL_,1} ,{"LD_D_A",&a::LD_D_A,1}   ,{"LD_E_B",&a::LD_E_B,1},{"LD_E_C",&a::LD_E_C,1},{"LD_E_D",&a::LD_E_D,1},{"LD_E_E",&a::NOP,1}   ,{"LD_E_H",&a::LD_E_H,1},{"LD_E_L",&a::LD_E_L,1},{"LD_E(HL)",&a::LD_E_HL_,1},{"LD_E_A",&a::LD_E_A,1},//5
        {"LD_H_B",&a::LD_H_B,1}    ,{"LD_H_C",&a::LD_H_C,1}   ,{"LD_H_D",&a::LD_H_D,1}     ,{"LD_H_E",&a::LD_H_E,1}   ,{"LD_H_H",&a::NOP,1}      ,{"LD_H_L",&a::LD_H_L,1}   ,{"LD_H(HL)",&a::LD_H_HL_,1} ,{"LD_H_A",&a::LD_H_A,1}   ,{"LD_L_B",&a::LD_L_B,1},{"LD_L_C",&a::LD_L_C,1},{"LD_L_D",&a::LD_L_D,1},{"LD_L_E",&a::LD_L_E,1},{"LD_L_H",&a::LD_L_H,1},{"LD_L_L",&a::NOP,1}   ,{"LD_L(HL)",&a::LD_L_HL_,1},{"LD_L_A",&a::LD_L_A,1},//6
        {"LD(HL)B",&a::LD_HL_B_,1} ,{"LD(HL)C",&a::LD_HL_C_,1},{"LD(HL)D",&a::LD_HL_D_,1}  ,{"LD(HL)E",&a::LD_HL_E_,1},{"LD(HL)H",&a::LD_HL_H_,1},{"LD(HL)L",&a::LD_HL_L_,1},{"HALT",&a::HALT,1}         ,{"LD(HL)A",&a::LD_HL_A_,1},{"LD_A_B",&a::LD_A_B,1},{"LD_A_C",&a::LD_A_C,1},{"LD_A_D",&a::LD_A_D,1},{"LD_A_E",&a::LD_A_E,1},{"LD_A_H",&a::LD_A_H,1},{"LD_A_L",&a::LD_A_L,1},{"LD_A(HL)",&a::LD_A_HL_,1},{"LD_A_A",&a::NOP,1},//7
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"ADD(HL)",&a::ADD_HL_,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//8
        {"SUB_B",&a::SUB_B,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//9
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"XOR_B",&a::XOR_B,1},{"XOR_C",&a::XOR_C,1},{"XOR_D",&a::XOR_D,1},{"XOR_E",&a::XOR_E,1},{"XOR_H",&a::XOR_H,1},{"XOR_L",&a::XOR_L,1},{"XOR(HL)",&a::XOR_HL_,1},{"XOR_A",&a::XOR_A,1},//A
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"CP(HL)",&a::CP_HL_,1},{"NOP",&a::NOP,1},//B
        {"NOP",&a::NOP,1},{"POP_BC",&a::POP_BC,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"PUSH_BC",&a::PUSH_BC,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"RET",&a::RET,1},{"NOP",&a::NOP,1},{"CB",&a::NOP,1},{"NOP",&a::NOP,1},{"CALL_D16",&a::CALL_D16,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//C
        {"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},//D
        {"LDH(D8)A",&a::LD_D8_A,1},{"NOP",&a::NOP,1},{"LD(C)A",&a::LD_C_A_,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"LD(D16)A",&a::LD_D16_A,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"XOR_D8",&a::XOR_D8,1},{"NOP",&a::NOP,1},//E
        {"LDH_A(D8)",&a::LD_A_D8_,1},{"NOP",&a::NOP,1},{"LD_A(C)",&a::LD_A_C_,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"NOP",&a::NOP,1},{"CP_D8",&a::CP_D8,1},{"NOP",&a::NOP,1}//F
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
    //we are going to go until a HALT is raised
    try
    {
        while(true)
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
    cout << "HL: " << hex << +ReadPair(H, L) << dec << " (" << +ReadPair(H, L) << ")" << endl;
    cout << "SP: " << hex << +SP << dec << " (" << +SP << ")" << endl;
    cout << "PC: " << hex << +PC << dec << " (" << +PC << ")" << endl;
    cout << "Flags:  z=" << z << " n=" << n << " h=" << h << " c=" << c << endl;
}

//Instruction set bindings

void DMGCPU::NOP() {return;}

void DMGCPU::HALT() {throw "HALT";}

void DMGCPU::LD_SP() {SP = Imm16();}
void DMGCPU::LD_HL() {WritePair(Imm16(), H, L);}
void DMGCPU::LD_DE() {WritePair(Imm16(), D, E);}
void DMGCPU::LD_BC() {WritePair(Imm16(), B, C);}

//8bit xor bindings
void DMGCPU::XOR_B() {XOR(B);}
void DMGCPU::XOR_C() {XOR(C);}
void DMGCPU::XOR_D() {XOR(D);}
void DMGCPU::XOR_E() {XOR(E);}
void DMGCPU::XOR_H() {XOR(H);}
void DMGCPU::XOR_L() {XOR(L);}
void DMGCPU::XOR_HL_() {XOR(ReadBus(ReadPair(H, L)));}
void DMGCPU::XOR_A() {XOR(A);}
void DMGCPU::XOR_D8() {XOR(Imm8());}

//8bit add bindings
void DMGCPU::ADD_HL_() {ADD(ReadBus(ReadPair(H, L)));}

//8but subtract bindings
void DMGCPU::SUB_B() {SUB(B);}

//Compare bindings
void DMGCPU::CP_HL_() {CP(ReadBus(ReadPair(H, L)));}
void DMGCPU::CP_D8() {CP(Imm8());}

//16bit increment bindings
void DMGCPU::INC_BC() {IncrementPair(B, C);}
void DMGCPU::INC_DE() {IncrementPair(D, E);}
void DMGCPU::INC_HL() {IncrementPair(H, L);}
void DMGCPU::INC_SP() {SP++;}

//8bit increment bindings
void DMGCPU::INC_B() {INC(B);}
void DMGCPU::INC_C() {INC(C);}
void DMGCPU::INC_D() {INC(D);}
void DMGCPU::INC_E() {INC(E);}
void DMGCPU::INC_H() {INC(H);}
void DMGCPU::INC_L() {INC(L);}
void DMGCPU::INC_HL_() {INC(GetRef(ReadPair(H, L)));}
void DMGCPU::INC_A() {INC(A);}

//16bit decrement bindings
void DMGCPU::DEC_BC() {DecrementPair(B, C);}
void DMGCPU::DEC_DE() {DecrementPair(D, E);}
void DMGCPU::DEC_HL() {DecrementPair(H, L);}
void DMGCPU::DEC_SP() {SP--;}

//8bit decrement bindings
void DMGCPU::DEC_B() {DEC(B);}
void DMGCPU::DEC_C() {DEC(C);}
void DMGCPU::DEC_D() {DEC(D);}
void DMGCPU::DEC_E() {DEC(E);}
void DMGCPU::DEC_H() {DEC(H);}
void DMGCPU::DEC_L() {DEC(L);}
void DMGCPU::DEC_HL_() {DEC(GetRef(ReadPair(H, L)));}
void DMGCPU::DEC_A() {DEC(A);}

//8bit load bindings (A)
void DMGCPU::LD_A_B() {A=B;}
void DMGCPU::LD_A_C() {A=C;}
void DMGCPU::LD_A_D() {A=D;}
void DMGCPU::LD_A_E() {A=E;}
void DMGCPU::LD_A_H() {A=H;}
void DMGCPU::LD_A_L() {A=L;}
void DMGCPU::LD_A_HL_() {A=ReadBus(ReadPair(H, L));}
//void DMGCPU::LD_A_A() {return;}
void DMGCPU::LD_A_D8() {A=Imm8();}

//8bit load bindings (B)
//void DMGCPU::LD_B_B() {return;}
void DMGCPU::LD_B_C() {B=C;}
void DMGCPU::LD_B_D() {B=D;}
void DMGCPU::LD_B_E() {B=E;}
void DMGCPU::LD_B_H() {B=H;}
void DMGCPU::LD_B_L() {B=L;}
void DMGCPU::LD_B_HL_() {B=ReadBus(ReadPair(H, L));}
void DMGCPU::LD_B_A() {B=A;}
void DMGCPU::LD_B_D8() {B=Imm8();}

//8bit load bindings (C)
void DMGCPU::LD_C_B() {C=B;}
//void DMGCPU::LD_C_C() {return;}
void DMGCPU::LD_C_D() {C=D;}
void DMGCPU::LD_C_E() {C=E;}
void DMGCPU::LD_C_H() {C=H;}
void DMGCPU::LD_C_L() {C=L;}
void DMGCPU::LD_C_HL_() {C=ReadBus(ReadPair(H, L));}
void DMGCPU::LD_C_A() {C=A;}
void DMGCPU::LD_C_D8() {C=Imm8();}

//8bit load bindings (D)
void DMGCPU::LD_D_B() {D=B;}
void DMGCPU::LD_D_C() {D=C;}
//void DMGCPU::LD_D_D() {return;}
void DMGCPU::LD_D_E() {D=E;}
void DMGCPU::LD_D_H() {D=H;}
void DMGCPU::LD_D_L() {D=L;}
void DMGCPU::LD_D_HL_() {D=ReadBus(ReadPair(H, L));}
void DMGCPU::LD_D_A() {D=A;}
void DMGCPU::LD_D_D8() {D=Imm8();}

//8bit load bindings (E)
void DMGCPU::LD_E_B() {E=B;}
void DMGCPU::LD_E_C() {E=C;}
void DMGCPU::LD_E_D() {E=D;}
//void DMGCPU::LD_E_E() {return;}
void DMGCPU::LD_E_H() {E=H;}
void DMGCPU::LD_E_L() {E=L;}
void DMGCPU::LD_E_HL_() {E=ReadBus(ReadPair(H, L));}
void DMGCPU::LD_E_A() {E=A;}
void DMGCPU::LD_E_D8() {E=Imm8();}

//8bit load bindings (H)
void DMGCPU::LD_H_B() {H=B;}
void DMGCPU::LD_H_C() {H=C;}
void DMGCPU::LD_H_D() {H=D;}
void DMGCPU::LD_H_E() {H=E;}
//void DMGCPU::LD_H_H() {return;}
void DMGCPU::LD_H_L() {H=L;}
void DMGCPU::LD_H_HL_() {H=ReadBus(ReadPair(H, L));}
void DMGCPU::LD_H_A() {H=A;}
void DMGCPU::LD_H_D8() {H=Imm8();}

//8bit load bindings (L)
void DMGCPU::LD_L_B() {L=B;}
void DMGCPU::LD_L_C() {L=C;}
void DMGCPU::LD_L_D() {L=D;}
void DMGCPU::LD_L_E() {L=E;}
void DMGCPU::LD_L_H() {L=H;}
//void DMGCPU::LD_L_L() {return;}
void DMGCPU::LD_L_HL_() {L=ReadBus(ReadPair(H, L));}
void DMGCPU::LD_L_A() {L=A;}
void DMGCPU::LD_L_D8() {L=Imm8();}

void DMGCPU::LD_HL_B_() {WriteBus(ReadPair(H, L), B);}
void DMGCPU::LD_HL_C_() {WriteBus(ReadPair(H, L), C);}
void DMGCPU::LD_HL_D_() {WriteBus(ReadPair(H, L), D);}
void DMGCPU::LD_HL_E_() {WriteBus(ReadPair(H, L), E);}
void DMGCPU::LD_HL_H_() {WriteBus(ReadPair(H, L), H);}
void DMGCPU::LD_HL_L_() {WriteBus(ReadPair(H, L), L);}
void DMGCPU::LD_HL_A_() {WriteBus(ReadPair(H, L), A);}
void DMGCPU::LD_HL_D8_() {WriteBus(ReadPair(H, L), Imm8());}

void DMGCPU::LD_C_A_() {WriteBus(0xFF00+C, Imm8());}
void DMGCPU::LD_A_C_() {A=ReadBus(0xFF00+C);}

void DMGCPU::LD_BC_A_() {WriteBus(ReadPair(B, C), A);}
void DMGCPU::LD_DE_A_() {WriteBus(ReadPair(D, E), A);}
void DMGCPU::LD_A_BC_() {A=ReadBus(ReadPair(B, C));}
void DMGCPU::LD_A_DE_() {A=ReadBus(ReadPair(D, E));}

void DMGCPU::LD_D16_A() {WriteBus(Imm16(), A);}

void DMGCPU::LD_D8_A() {WriteBus(0xFF00+Imm8(), A);}
void DMGCPU::LD_A_D8_() {A=ReadBus(0xFF00+Imm8());}

void DMGCPU::LD_HLp_A_() {WriteBus(ReadPair(H, L), A); IncrementPair(H, L);}
void DMGCPU::LD_HLm_A_() {WriteBus(ReadPair(H, L), A); DecrementPair(H, L);}
void DMGCPU::LD_A_HLp_() {A=ReadBus(ReadPair(H, L)); IncrementPair(H, L);}
void DMGCPU::LD_A_HLm_() {A=ReadBus(ReadPair(H, L)); DecrementPair(H, L);}

//bit rotate bindings

void DMGCPU::RLA() {RL(A);}

//jump bindings

void DMGCPU::JR_D8() {JR(Imm8(), true);}

void DMGCPU::JR_NZ_D8() {JR(Imm8(), !z);}
void DMGCPU::JR_Z_D8() {JR(Imm8(), z);}

//call/return bindings

void DMGCPU::CALL_D16() {PUSH(PC); PC=Imm16();}

void DMGCPU::RET() {PC=POP();}

//push bindings

void DMGCPU::PUSH_BC() {PUSH(B, C);}

//pop bindings

void DMGCPU::POP_BC() {POP(B, C);}

//helper functions

void DMGCPU::WritePair(uint16_t val, uint8_t &hi, uint8_t &lo)
{
    hi = val >> 8;
    lo = val;
}

uint16_t DMGCPU::ReadPair(uint8_t hi, uint8_t lo)
{
    return (hi << 8) | lo;
}

void DMGCPU::IncrementPair(uint8_t &hi, uint8_t &lo)
{
    lo++;
    if (lo == 0x00)
        hi++;
}

void DMGCPU::DecrementPair(uint8_t &hi, uint8_t &lo)
{
    lo--;
    if (lo == 0xFF)
        hi--;
}

//XOR operations always write to the ACC (A) so this function need not return a value
void DMGCPU::XOR(uint8_t operand)
{
    A = A ^ operand;
    z = (A==0x00);
    n = h = c = false;
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

void DMGCPU::ADD(uint8_t operand)
{
    uint8_t Acpy = A;
    A += operand;
    z = (A==0x00);
    n = false;
    c = (A < Acpy);
}

void DMGCPU::SUB(uint8_t operand)
{
    c = (A < operand);
    A -= operand;
    z = (A==0x00);
    n = true;
}

void DMGCPU::CP(uint8_t operand)
{
    c = (A < operand);
    z = (A==operand);
    n = true;
}

void DMGCPU::POP(uint8_t &hi, uint8_t &lo)
{
    lo = ReadBus(SP);
    SP++;
    hi = ReadBus(SP);
    SP++;
}

uint16_t DMGCPU::POP()
{
    uint8_t lo = ReadBus(SP);
    SP++;
    uint8_t hi = ReadBus(SP);
    SP++;
    return (hi << 8) | lo;
}

void DMGCPU::PUSH(uint8_t hi, uint8_t lo)
{
    SP--;
    WriteBus(SP, hi);
    SP--;
    WriteBus(SP, lo);
}

void DMGCPU::PUSH(uint16_t operand)
{
    PUSH(operand >> 8, operand);
}

void DMGCPU::RL(uint8_t &operand)
{
    uint8_t setcarry = operand;
    operand <<= 1;
    operand += c;
    c = ((setcarry & 0x80) == 0x80);
}

//Jump commands

void DMGCPU::JR(int8_t operand, bool condition)
{//Note the unsigned argument
    if (condition)
        PC += operand;
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
    //hi and lo need to be 16 bit integers to make space for the bit shift.
    //16 bit immediate data is read in reverse in all cases that I am aware of.

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
