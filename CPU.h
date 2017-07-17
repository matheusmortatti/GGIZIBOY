#include <stdint.h>

#define C 4
#define H 5
#define N 6
#define Z 7

typedef struct registers {
    uint8_t a, f;
    uint8_t b, c;
    uint8_t d, e;
    uint8_t h, l;
    uint16_t pc, sp;
    uint8_t flag;
} registers_t;

typedef uint8_t instruction_t;