#include "CPU.h"
#include "instructions.h"
#include "MMU.h"

extern registers_t registers;

// 8-bit Loads 

// LD nn,n
// 0x06
void LD_B_n(uint16_t operand) { registers.b = (uint8_t)operand; }
// 0x0E
void LD_C_n(uint16_t operand) { registers.c = (uint8_t)operand; }
// 0x16
void LD_D_n(uint16_t operand) { registers.d = (uint8_t)operand; }
// 0x1E
void LD_E_n(uint16_t operand) { registers.e = (uint8_t)operand; }
// 0x26
void LD_H_n(uint16_t operand) { registers.h = (uint8_t)operand; }
// 0x2E
void LD_L_n(uint16_t operand) { registers.l = (uint8_t)operand; }

// LD r1,r2
// 0x7F
void LD_a_a(uint16_t operand) { registers.a = registers.a; }
// 0x78
void LD_a_b(uint16_t operand) { registers.a = registers.b; }
// 0x79
void LD_a_c(uint16_t operand) { registers.a = registers.c; }
// 0x7A
void LD_a_d(uint16_t operand) { registers.a = registers.d; }
// 0x7B
void LD_a_e(uint16_t operand) { registers.a = registers.e; }
// 0x7C
void LD_a_h(uint16_t operand) { registers.a = registers.h; }
// 0x7D
void LD_a_l(uint16_t operand) { registers.a = registers.l; }
// 0x7E
void LD_a_hl(uint16_t operand) { registers.a = readByte(*(uint16_t *)&registers.h); }
// 0x40
void LD_b_b(uint16_t operand) { registers.b = registers.b; }
// 0x41
void LD_b_c(uint16_t operand) { registers.b = registers.c; }
// 0x42
void LD_b_d(uint16_t operand) { registers.b = registers.d; }
// 0x43
void LD_b_e(uint16_t operand) { registers.b = registers.e; }
// 0x44
void LD_b_h(uint16_t operand) { registers.b = registers.h; }
// 0x45
void LD_b_l(uint16_t operand) { registers.b = registers.l; }
// 0x46
void LD_b_hl(uint16_t operand) { registers.b = readByte(*(uint16_t *)&registers.h); }
// 0x48
void LD_c_b(uint16_t operand) { registers.c = registers.b; }
// 0x49
void LD_c_c(uint16_t operand) { registers.c = registers.c; }
// 0x4A
void LD_c_d(uint16_t operand) { registers.c = registers.d; }
// 0x4B
void LD_c_e(uint16_t operand) { registers.c = registers.e; }
// 0x4C
void LD_c_h(uint16_t operand) { registers.c = registers.h; }
// 0x4D
void LD_c_l(uint16_t operand) { registers.c = registers.l; }
// 0x4E
void LD_c_hl(uint16_t operand) { registers.c = readByte(*(uint16_t *)&registers.h); }
// 0x50
void LD_d_b(uint16_t operand) { registers.d = registers.b; }
// 0x51
void LD_d_c(uint16_t operand) { registers.d = registers.c; }
// 0x52
void LD_d_d(uint16_t operand) { registers.d = registers.d; }
// 0x53
void LD_d_e(uint16_t operand) { registers.d = registers.e; }
// 0x54
void LD_d_h(uint16_t operand) { registers.d = registers.h; }
// 0x55
void LD_d_l(uint16_t operand) { registers.d = registers.l; }
// 0x56
void LD_d_hl(uint16_t operand) { registers.d = readByte(*(uint16_t *)&registers.h); }
// 0x58
void LD_e_b(uint16_t operand) { registers.e = registers.b; }
// 0x59
void LD_e_c(uint16_t operand) { registers.e = registers.c; }
// 0x5A
void LD_e_d(uint16_t operand) { registers.e = registers.d; }
// 0x5B
void LD_e_e(uint16_t operand) { registers.e = registers.e; }
// 0x5C
void LD_e_h(uint16_t operand) { registers.e = registers.h; }
// 0x5D
void LD_e_l(uint16_t operand) { registers.e = registers.l; }
// 0x5E
void LD_e_hl(uint16_t operand) { registers.e = readByte(*(uint16_t *)&registers.h); }
// 0x60
void LD_h_b(uint16_t operand) { registers.h = registers.b; }
// 0x61
void LD_h_c(uint16_t operand) { registers.h = registers.c; }
// 0x62
void LD_h_d(uint16_t operand) { registers.h = registers.d; }
// 0x63
void LD_h_e(uint16_t operand) { registers.h = registers.e; }
// 0x64
void LD_h_h(uint16_t operand) { registers.h = registers.h; }
// 0x65
void LD_h_l(uint16_t operand) { registers.h = registers.l; }
// 0x66
void LD_h_hl(uint16_t operand) { registers.h = readByte(*(uint16_t *)&registers.h); }
// 0x68
void LD_l_b(uint16_t operand) { registers.l = registers.b; }
// 0x69
void LD_l_c(uint16_t operand) { registers.l = registers.c; }
// 0x6A
void LD_l_d(uint16_t operand) { registers.l = registers.d; }
// 0x6B
void LD_l_e(uint16_t operand) { registers.l = registers.e; }
// 0x6C
void LD_l_h(uint16_t operand) { registers.l = registers.h; }
// 0x6D
void LD_l_l(uint16_t operand) { registers.l = registers.l; }
// 0x6E
void LD_l_hl(uint16_t operand) { registers.l = readByte(*(uint16_t *)&registers.h); }
// 0x70
void LD_hl_b(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.b); }
// 0x71
void LD_hl_c(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.c); }
// 0x72
void LD_hl_d(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.d); }
// 0x73
void LD_hl_e(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.e); }
// 0x74
void LD_hl_h(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.h); }
// 0x75
void LD_hl_l(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.l); }
// 0x36
void LD_hl_n(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, (uint8_t)(operand & 0xFF)); }

// LD A,n
// 0x0A
void LD_a_bc(uint16_t operand) { registers.a = readByte(*(uint16_t *)&registers.b); }
// 0x1A
void LD_a_de(uint16_t operand) { registers.a = readByte(*(uint16_t *)&registers.d); }
// 0xFA
void LD_a_nn(uint16_t operand) { registers.a = readByte(operand); }
// 0x3E
void LD_a_n(uint16_t operand) { registers.a = operand; }

// LD n,A
//0x02
void LD_bc_a(uint16_t operand) { writeByte(*(uint16_t *)&registers.b, registers.a); }
//0x12
void LD_de_a(uint16_t operand) { writeByte(*(uint16_t *)&registers.d, registers.a); }
//0x77
void LD_hl_a(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.a); }
//0xEA
void LD_nn_a(uint16_t operand) { writeByte(operand, registers.a); }

// LD A,(C)
// 0xF2
void LD_a_c_offset(uint16_t operand) { registers.a = readByte(0xFF00 + registers.c); }

// LD (C),A
// 0xE2
void LD_c_offset_a(uint16_t operand) { writeByte(0xFF00 + registers.c, registers.a); }

// LDD A,(HL)
// 0x3A
void LDD_a_hl(uint16_t operand) { registers.a = readByte(*(uint16_t *)&registers.h); (*(uint16_t *)&registers.h)--; }

// LDD (HL),A
// 0x32
void LDD_hl_a(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.a); (*(uint16_t *)&registers.h)--; }

// LDI A,(HL)
// 0x2A
void LDI_a_hl(uint16_t operand) { registers.a = readByte(*(uint16_t *)&registers.h); (*(uint16_t *)&registers.h)++; }

// LDI (HL),A
// 0x22
void LDI_hl_a(uint16_t operand) { writeByte(*(uint16_t *)&registers.h, registers.a); (*(uint16_t *)&registers.h)++; }

// LDH (n),A
// 0xE0
void LDH_n_a(uint16_t operand) { writeByte(0xFF00 + operand, registers.a); }

// LDH A,(n)
// 0xF0
void LDH_a_n(uint16_t operand) { registers.a = readByte(0xFF00 + operand); }

// 16-bit Loads

// LD BC,nn
// 0x01
void LD_bc_nn(uint16_t operand) { *(uint16_t *)&registers.b = operand; }

// LD DE,nn
// 0x11
void LD_de_nn(uint16_t operand) { *(uint16_t *)&registers.d = operand; }

// LD HL,nn
// 0x21
void LD_hl_nn(uint16_t operand) { *(uint16_t *)&registers.h = operand; }

// LD SP,nn
// 0x31
void LD_sp_nn(uint16_t operand) { registers.sp = operand; }

// LD SP,hl
// 0xF9
void LD_sp_hl(uint16_t operand) { registers.sp = *(uint16_t *)&registers.h; }

// LDHL SP,n
// 0xF8
void LDHL_sp_n(uint16_t operand) { 
    uint32_t value;

    value = registers.sp + (int8_t)operand;
    *(uint16_t *)&registers.h = (uint16_t)value;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.sp & 0x0F) + (operand & 0x0F)) & 0xF0) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (value & 0xFFFF0000) 
        registers.flag |= C_FLAG;
}

// LD (nn),SP
// 0x08
void LD_sp_n(uint16_t operand) { writeWord(operand ,registers.sp); }

// PUSH AF
// 0xF5
void PUSH_af(uint16_t operand) { registers.sp -= 2; writeWord(registers.sp, *(uint16_t *)&registers.a); }

// PUSH BC
// 0xC5
void PUSH_bc(uint16_t operand) { registers.sp -= 2; writeWord(registers.sp, *(uint16_t *)&registers.b); }

// PUSH DE
// 0xD5
void PUSH_de(uint16_t operand) { registers.sp -= 2; writeWord(registers.sp, *(uint16_t *)&registers.d); }

// PUSH hl
// 0xE5
void PUSH_hl(uint16_t operand) { registers.sp -= 2; writeWord(registers.sp, *(uint16_t *)&registers.h); }

// POP AF
// 0xF1
void POP_af(uint16_t operand) { *(uint16_t *)&registers.a = readWord(registers.sp); registers.sp -= 2; }

// POP BC
// 0xC1
void POP_bc(uint16_t operand) { *(uint16_t *)&registers.b = readWord(registers.sp); registers.sp -= 2; }

// POP DE
// 0xD1
void POP_de(uint16_t operand) { *(uint16_t *)&registers.d = readWord(registers.sp); registers.sp -= 2; }

// POP hl
// 0xE1
void POP_hl(uint16_t operand) { *(uint16_t *)&registers.h = readWord(registers.sp); registers.sp -= 2; }


// 8-bit ALU
