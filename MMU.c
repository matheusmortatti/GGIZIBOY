#include <stdio.h>
#include <stdint.h>

#include "MMU.h"

#define CARTRIDGE_OFFSET 0x0
#define VRAM_OFFSET 0x8000
#define SRAM_OFFSET 0xA000
#define WRAM_OFFSET 0xC000
#define OAM_OFFSET 0xFE00
#define IO_OFFSET 0xFF00
#define HRAM_OFFSET 0xFF80

//0000-3FFF   16KB ROM Bank 00     (in cartridge, fixed at bank 00)
//4000-7FFF   16KB ROM Bank 01..NN (in cartridge, switchable bank number)
//8000-9FFF   8KB Video RAM (VRAM) (switchable bank 0-1 in CGB Mode)
//A000-BFFF   8KB External RAM     (in cartridge, switchable bank, if any)
//C000-CFFF   4KB Work RAM Bank 0 (WRAM)
//D000-DFFF   4KB Work RAM Bank 1 (WRAM)  (switchable bank 1-7 in CGB Mode)
//E000-FDFF   Same as C000-DDFF (ECHO)    (typically not used)
//FE00-FE9F   Sprite Attribute Table (OAM)
//FEA0-FEFF   Not Usable
//FF00-FF7F   I/O Ports
//FF80-FFFE   High RAM (HRAM)
//FFFF        Interrupt Enable Register

MMU_t mmu;

uint8_t readByte(uint16_t address) {
    if (address <= 0x7FFF) {
        return mmu.cartridge[address - CARTRIDGE_OFFSET];
    } else if (address <= 0x9FFF) {
        return mmu.vram[address - VRAM_OFFSET];
    } else if (address <= 0xBFFF) {
        return mmu.sram[address - SRAM_OFFSET];
    } else if (address <= 0xDFFF) {
        return mmu.wram[address - WRAM_OFFSET];
    } else if (0xFE00 <= address && address <= 0xFE9F) {
        return mmu.oam[address - OAM_OFFSET];
    } else if (0xFF00 <= address && address <= 0xFF7F) {
        return mmu.io[address - IO_OFFSET];
    } else if (0xFF80 <= address && address <= 0xFFFE) {
        return mmu.hram[address - HRAM_OFFSET];
    } else {
        perror("Invalid address\n");
        return 0;
    }
}

uint16_t readWord(uint16_t address) {
    // IMPORTANT: Z80 is little endian!!!
    return (uint16_t)(readByte(address + 1) | readByte(address));
}

void writeByte(uint16_t address, uint8_t data) {
    if (address <= 0x7FFF) {
        mmu.cartridge[address - CARTRIDGE_OFFSET] = data;
    } else if (address <= 0x9FFF) {
        mmu.vram[address - VRAM_OFFSET] = data;
    } else if (address <= 0xBFFF) {
        mmu.sram[address - SRAM_OFFSET] = data;
    } else if (address <= 0xDFFF) {
        mmu.wram[address - WRAM_OFFSET] = data;
    } else if (0xFE00 <= address && address <= 0xFE9F) {
        mmu.oam[address - OAM_OFFSET] = data;
    } else if (0xFF00 <= address && address <= 0xFF7F) {
        mmu.io[address - IO_OFFSET] = data;
    } else if (0xFF80 <= address && address <= 0xFFFE) {
        mmu.hram[address - HRAM_OFFSET] = data;
    } else {
        perror("Invalid address\n");
    }
}

void writeWord(uint16_t address, uint16_t data) {
    writeByte(address + 1, (uint8_t)(data >> 8));
    writeByte(address, (uint8_t)(data & 0xFF));
}