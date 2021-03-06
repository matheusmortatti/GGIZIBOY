#include <stdint.h>

#define C_FLAG 0x10
#define H_FLAG 0x20
#define N_FLAG 0x40
#define Z_FLAG 0x80

#define C_FLAG_POS 4
#define H_FLAG_POS 5
#define N_FLAG_POS 6
#define Z_FLAG_POS 7

typedef struct registers {
    uint8_t a, f;
    uint8_t b, c;
    uint8_t d, e;
    uint8_t h, l;
    uint16_t pc, sp;
    uint8_t flag;
} registers_t;

typedef uint8_t instruction_t;