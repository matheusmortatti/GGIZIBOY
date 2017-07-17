#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "CPU.h"
#include "instructions.h"

registers_t registers;

void instruction_fetch(instruction_t *instruction);
void instruction_decode(instruction_t instruction, uint8_t *opcode, uint16_t *operand);
void instruction_execute(uint8_t opcode, uint16_t operand);

void run(void) {
    instruction_t instruction;
    uint8_t opcode;
    uint16_t operand;

    while (1) {
        instruction_fetch(&instruction);
        instruction_decode(instruction, &opcode, &operand);
        instruction_execute(opcode, operand);
    }
}

void instruction_fetch(instruction_t *instruction) {
    // Read instruction from memory
    *instruction = readByte(registers.pc);

    // Increment PC
    registers.pc += 1;
}

void instruction_decode(instruction_t instruction, uint8_t *opcode, uint16_t *operand) {
    //TODO check instruction operand

    //TODO retrive operand from memory
}

void instruction_execute(uint8_t opcode, uint16_t operand) {
    
}