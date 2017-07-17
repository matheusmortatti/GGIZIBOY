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

// LD A,(C)
// 0xE2
void LD_c_offset_a(uint16_t operand) { writeByte(0xFF00 + registers.c, registers.a); }


