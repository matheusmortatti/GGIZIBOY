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

// ADD A,n

// ADD A,A
// 0x87
void ADD_a_a(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.a;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.a & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,B
// 0x80
void ADD_a_b(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.b;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.b & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,C
// 0x81
void ADD_a_c(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.c;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.c & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,D
// 0x82
void ADD_a_d(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.d;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.d & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,E
// 0x83
void ADD_a_e(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.e;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.e & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,H
// 0x84
void ADD_a_h(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.h;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.h & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,L
// 0x85
void ADD_a_l(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.l;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.l & 0x0F)) & 0x10)
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,(HL)
// 0x86
void ADD_a_hl(uint16_t operand) {
    uint32_t sum;
    uint8_t hl = readByte(*(uint16_t *)&registers.h);

    sum = registers.a + hl;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (hl & 0x0F)) & 0x10)
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADD A,#
// 0xC6
void ADD_a_imm(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + (uint8_t)operand;
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + ((uint8_t)operand & 0x0F)) & 0x10)
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,n

// ADC A,A
// 0x8F
void ADC_a_a(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.a + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.a & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,B
// 0x88
void ADC_a_b(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.b + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.b & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,C
// 0x89
void ADC_a_c(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.c + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.c & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,D
// 0x8A
void ADC_a_d(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.d + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.d & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,E
// 0x8B
void ADC_a_e(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.e + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.e & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,H
// 0x8C
void ADC_a_h(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.h + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.h & 0x0F)) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,L
// 0x8D
void ADC_a_l(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + registers.l + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (registers.l & 0x0F)) & 0x10)
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,(HL)
// 0x8E
void ADC_a_hl(uint16_t operand) {
    uint32_t sum;
    uint8_t hl = readByte(*(uint16_t *)&registers.h);

    sum = registers.a + hl + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + (hl & 0x0F)) & 0x10)
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// ADC A,#
// 0xCE
void ADC_a_imm(uint16_t operand) {
    uint32_t sum;

    sum = registers.a + (uint8_t)operand + ((registers.flag & C_FLAG) >> C_FLAG_POS);
    registers.a = (uint8_t)(sum & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + ((uint8_t)operand & 0x0F)) & 0x10)
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x100)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sum & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,A
// 0x97
void SUB_a_a(uint16_t operand) {
    registers.a = 0;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set flag Z
    registers.flag |= Z_FLAG;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set flag C
    registers.flag |= C_FLAG;
}

// SUB A,B
// 0x90
void SUB_a_b(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.b;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.b & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.b)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,C
// 0x91
void SUB_a_c(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.c;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.c & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.c)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,D
// 0x92
void SUB_a_d(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.d;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.d & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.d)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,E
// 0x93
void SUB_a_e(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.e;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.e & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.e)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,H
// 0x94
void SUB_a_h(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.h;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.h & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.h)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,L
// 0x95
void SUB_a_l(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.l;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.l & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.l)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,(HL)
// 0x96
void SUB_a_hl(uint16_t operand) {
    uint32_t sub;
    uint8_t hl = readByte(*(uint16_t *)&registers.h);

    sub = registers.a - hl;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (hl & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= hl)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,#
// 0xD6
void SUB_a_imm(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - (uint8_t)(operand & 0xFF);
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= ((uint8_t)(operand & 0xFF) & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= (uint8_t)(operand & 0xFF))
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,A
// 0x9F
void SBC_a_a(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.a + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,B
// 0x98
void SBC_a_b(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.b + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,C
// 0x99
void SBC_a_c(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.c + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,D
// 0x9A
void SBC_a_d(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.d + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,E
// 0x9B
void SBC_a_e(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.e + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,H
// 0x9C
void SBC_a_h(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.h + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SBC A,L
// 0x9D
void SBC_a_l(uint16_t operand) {
    uint32_t sub;
    uint8_t aux = registers.l + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - aux;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (aux & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= aux)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// SUB A,(HL)
// 0x9E
void SBC_a_hl(uint16_t operand) {
    uint32_t sub;
    uint8_t hl = readByte(*(uint16_t *)&registers.h) + ((registers.flag & C_FLAG) >> C_FLAG_POS);

    sub = registers.a - hl;
    registers.a = (uint8_t)(sub & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (hl & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= hl)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// AND A,A
// 0xA7
void AND_a_a(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.a == 0)
        registers.flag |= Z_FLAG;
}

// AND A,B
// 0xA0
void AND_a_b(uint16_t operand) {
    uint8_t and;

    and = registers.a & registers.b;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,C
// 0xA1
void AND_a_c(uint16_t operand) {
    uint8_t and;

    and = registers.a & registers.c;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,D
// 0xA2
void AND_a_d(uint16_t operand) {
    uint8_t and;

    and = registers.a & registers.d;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,E
// 0xA3
void AND_a_e(uint16_t operand) {
    uint8_t and;

    and = registers.a & registers.e;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,H
// 0xA4
void AND_a_h(uint16_t operand) {
    uint8_t and;

    and = registers.a & registers.h;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,L
// 0xA5
void AND_a_l(uint16_t operand) {
    uint8_t and;

    and = registers.a & registers.l;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,(hl)
// 0xA6
void AND_a_hl(uint16_t operand) {
    uint8_t and;
    uint8_t hl = readByte(*(uint8_t *)&registers.h);

    and = registers.a & hl;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// AND A,#
// 0xE6
void AND_a_imm(uint16_t operand) {
    uint8_t and;

    and = registers.a & (uint8_t)operand;
    registers.a = and;

    // Reset flags
    registers.flag = 0;

    // Set flag H
    registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (and == 0)
        registers.flag |= Z_FLAG;
}

// OR A,A
// 0xB7
void OR_a_a(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.a;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,B
// 0xB0
void OR_a_b(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.b;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,C
// 0xB1
void OR_a_c(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.c;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,D
// 0xB2
void OR_a_d(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.d;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,E
// 0xB3
void OR_a_e(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.e;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,H
// 0xB4
void OR_a_h(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.h;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,L
// 0xB5
void OR_a_l(uint16_t operand) {
    uint8_t or;

    or = registers.a | registers.l;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,(HL)
// 0xB6
void OR_a_hl(uint16_t operand) {
    uint8_t or = readByte(*(uint8_t *)&registers.h);

    or |= registers.a;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// OR A,#
// 0xF6
void OR_a_imm(uint16_t operand) {
    uint8_t or;

    or = registers.a | (uint8_t)operand;
    registers.a = or;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (or == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,A
// 0xAF
void XOR_a_a(uint16_t operand) {
    registers.a = 0;

    // Reset flags
    registers.flag = 0;

    // Set flag Z
    registers.flag |= Z_FLAG;
}

// XOR A,B
// 0xA8
void XOR_a_b(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ registers.b;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,C
// 0xA9
void XOR_a_c(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ registers.c;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,D
// 0xAA
void XOR_a_d(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ registers.d;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,E
// 0xAB
void XOR_a_e(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ registers.e;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,H
// 0xAC
void XOR_a_h(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ registers.h;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,L
// 0xAD
void XOR_a_l(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ registers.l;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,(HL)
// 0xAE
void XOR_a_hl(uint16_t operand) {
    uint8_t xor = readByte(*(uint8_t *)&registers.h);

    xor ^= registers.a;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}

// XOR A,#
// 0xEE
void XOR_a_imm(uint16_t operand) {
    uint8_t xor;

    xor = registers.a ^ (uint8_t)operand;
    registers.a = xor;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag Z
    if (xor == 0)
        registers.flag |= Z_FLAG;
}


// CP A,A
// 0xBF
void CP_a_a(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set flag Z
    registers.flag |= Z_FLAG;

    // Set flag C
    registers.flag |= C_FLAG;

    // Set flag H
    registers.flag |= H_FLAG;
}

// CP A,B
// 0xB8
void CP_a_b(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.b;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.b & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.b)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,C
// 0xB9
void CP_a_c(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.c;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.c & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.c)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,D
// 0xBA
void CP_a_d(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.d;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.d & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.d)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,E
// 0xBB
void CP_a_e(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.e;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.e & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.e)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,H
// 0xBC
void CP_a_h(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.h;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.h & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.h)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,L
// 0xBD
void CP_a_l(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - registers.l;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (registers.l & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= registers.l)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,(HL)
// 0xBE
void CP_a_hl(uint16_t operand) {
    uint32_t sub;
    uint8_t hl = readByte(*(uint16_t *)&registers.h);

    sub = registers.a - hl;

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (hl & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= hl)
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// CP A,#
// 0xFE
void CP_a_imm(uint16_t operand) {
    uint32_t sub;

    sub = registers.a - (uint8_t)(operand & 0xFF);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= ((uint8_t)(operand & 0xFF) & 0x0F))
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (registers.a >= (uint8_t)(operand & 0xFF))
        registers.flag |= C_FLAG;

    // Set or Reset flag Z
    if ((sub & 0xFF) == 0)
        registers.flag |= Z_FLAG;
}

// INC A
// 0x3C
void INC_a(uint16_t operand) {
    registers.a++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.a & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.a == 0)
        registers.flag |= Z_FLAG;
}

// INC B
// 0x04
void INC_b(uint16_t operand) {
    registers.b++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.b & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.b == 0)
        registers.flag |= Z_FLAG;
}

// INC C
// 0x0C
void INC_c(uint16_t operand) {
    registers.c++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.c & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.c == 0)
        registers.flag |= Z_FLAG;
}

// INC D
// 0x14
void INC_d(uint16_t operand) {
    registers.d++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.d & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.d == 0)
        registers.flag |= Z_FLAG;
}

// INC E
// 0x1C
void INC_e(uint16_t operand) {
    registers.e++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.e & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.e == 0)
        registers.flag |= Z_FLAG;
}

// INC H
// 0x24
void INC_h(uint16_t operand) {
    registers.h++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.h & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.h == 0)
        registers.flag |= Z_FLAG;
}

// INC L
// 0x2C
void INC_l(uint16_t operand) {
    registers.l++;

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.l & 0x0F) + 0x01) & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (registers.l == 0)
        registers.flag |= Z_FLAG;
}

// INC (HL)
// 0x34
void INC_hl_m(uint16_t operand) {
    uint8_t hl = readByte(*(uint16_t *)&registers.h);

    hl++;
    writeByte(*(uint16_t *)&registers.h, hl);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (hl & 0x10) 
        registers.flag |= H_FLAG;

    // Set or Reset flag Z
    if (hl == 0)
        registers.flag |= Z_FLAG;
}

// DEC A
// 0x3D
void DEC_a(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.a--;

    // Set or Reset flag Z
    if (registers.a == 0)
        registers.flag |= Z_FLAG;
}

// DEC B
// 0x05
void DEC_b(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.b & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.b--;

    // Set or Reset flag Z
    if (registers.b == 0)
        registers.flag |= Z_FLAG;
}

// DEC C
// 0x0D
void DEC_c(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.c & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.c--;

    // Set or Reset flag Z
    if (registers.c == 0)
        registers.flag |= Z_FLAG;
}

// DEC D
// 0x15
void DEC_d(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.d & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.d--;

    // Set or Reset flag Z
    if (registers.d == 0)
        registers.flag |= Z_FLAG;
}

// DEC E
// 0x1D
void DEC_e(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.e & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.e--;

    // Set or Reset flag Z
    if (registers.e == 0)
        registers.flag |= Z_FLAG;
}

// DEC H
// 0x25
void DEC_h(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.h & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.h--;

    // Set or Reset flag Z
    if (registers.h == 0)
        registers.flag |= Z_FLAG;
}

// DEC L
// 0x2D
void DEC_l(uint16_t operand) {
    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.l & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    registers.l--;

    // Set or Reset flag Z
    if (registers.l == 0)
        registers.flag |= Z_FLAG;
}

// DEC (hl)
// 0x35
void DEC_hl_m(uint16_t operand) {
    uint8_t hl = readByte(*(uint16_t *)&registers.h);

    // Reset flags
    registers.flag = 0;

    // Set flag N
    registers.flag |= N_FLAG;

    // Set or Reset flag H
    if ((registers.a & 0x0F) >= (0x01))
        registers.flag |= H_FLAG;

    hl--;
    writeByte(*(uint16_t *)&registers.h, hl);

    // Set or Reset flag Z
    if (registers.a == 0)
        registers.flag |= Z_FLAG;
}

// 16-bit ALU

// ADD HL,BC
// 0x09
void ADD_hl_bc(uint16_t operand) {
    uint32_t sum;

    sum = *(uint16_t *)&registers.h + *(uint16_t *)&registers.b;
    *(uint16_t *)&registers.h = (uint16_t)(sum & 0xFFFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((*(uint16_t *)&registers.h & 0x0FFF) + (*(uint16_t *)&registers.b & 0x0FFF)) & 0x1000) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x10000)
        registers.flag |= C_FLAG;
}

// ADD HL,DE
// 0x19
void ADD_hl_de(uint16_t operand) {
    uint32_t sum;

    sum = *(uint16_t *)&registers.h + *(uint16_t *)&registers.d;
    *(uint16_t *)&registers.h = (uint16_t)(sum & 0xFFFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((*(uint16_t *)&registers.h & 0x0FFF) + (*(uint16_t *)&registers.d & 0x0FFF)) & 0x1000) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x10000)
        registers.flag |= C_FLAG;
}

// ADD HL,HL
// 0x29
void ADD_hl_hl(uint16_t operand) {
    uint32_t sum;

    sum = *(uint16_t *)&registers.h + *(uint16_t *)&registers.h;
    *(uint16_t *)&registers.h = (uint16_t)(sum & 0xFFFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((*(uint16_t *)&registers.h & 0x0FFF) + (*(uint16_t *)&registers.h & 0x0FFF)) & 0x1000) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x10000)
        registers.flag |= C_FLAG;
}

// ADD HL,SP
// 0x19
void ADD_hl_sp(uint16_t operand) {
    uint32_t sum;

    sum = *(uint16_t *)&registers.h + registers.sp;
    *(uint16_t *)&registers.h = (uint16_t)(sum & 0xFFFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((*(uint16_t *)&registers.h & 0x0FFF) + (registers.sp & 0x0FFF)) & 0x1000) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x10000)
        registers.flag |= C_FLAG;
}

// ADD SP,#
// 0xE8
void ADD_sp_imm(uint16_t operand) {
    uint32_t sum;

    sum = registers.sp + (int8_t)(operand & 0x00FF);
    registers.sp = (uint16_t)(sum & 0xFFFF);

    // Reset flags
    registers.flag = 0;

    // Set or Reset flag H
    if (((registers.sp & 0x0F) + (operand & 0x0F)) & 0x1000) 
        registers.flag |= H_FLAG;

    // Set or Reset flag C
    if (sum & 0x10000)
        registers.flag |= C_FLAG;
}

// INC BC
// 0x03
void INC_bc(uint16_t operand) { (*(uint16_t *)&registers.b)++; }

// INC DE
// 0x13
void INC_de(uint16_t operand) { (*(uint16_t *)&registers.d)++; }

// INC HL
// 0x23
void INC_hl(uint16_t operand) { (*(uint16_t *)&registers.h)++; }

// INC SP
// 0x33
void INC_sp(uint16_t operand) { (registers.sp)++; }

// DEC BC
// 0x0B
void DEC_bc(uint16_t operand) { (*(uint16_t *)&registers.b)--; }

// DEC DE
// 0x1B
void DEC_de(uint16_t operand) { (*(uint16_t *)&registers.d)--; }

// DEC HL
// 0x2B
void DEC_hl(uint16_t operand) { (*(uint16_t *)&registers.h)--; }

// DEC SP
// 0x3B
void DEC_sp(uint16_t operand) { (registers.sp)--; }
