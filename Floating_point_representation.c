#include <stdio.h>
#include <stdint.h>

// IEEE 754
void print_float_bits(float f) {
    union {
        float f;
        uint32_t u;
    } v;

    v.f = f;

    uint32_t sign     = (v.u >> 31) & 0x1;
    uint32_t exponent = (v.u >> 23) & 0xFF;     // 8 bits
    uint32_t mantissa =  v.u        & 0x7FFFFF; // 23 bits

    printf("Input float: %f\n", f);

    printf("Sign bit     : %u\n", sign);
    printf("Exponent bits: %08X (decimal %u)\n", exponent, exponent);

    // E = E' - 127
    int32_t real_exp = (int32_t)exponent - 127;
    printf("Actual exponent E = E' - 127 = %d\n", real_exp);

    // Mantissa binar
    char mantissa_str[32];
    mantissa_str[0] = '1';
    mantissa_str[1] = '.';

    for (int i = 22; i >= 0; i--) {
        mantissa_str[24 - i] = ((mantissa >> i) & 1) ? '1' : '0';
    }
    mantissa_str[25] = '\0'; // "1." + 23 bits = 25 chars

    printf("Mantissa bits: %s\n", mantissa_str);

    printf("\nIEEE-754 Value = %s%s * 2^(%d)\n",
           sign ? "-" : "+", mantissa_str, real_exp);
}

int main() {
    float x = 0.00123f;   // Input
    print_float_bits(x);
    return 0;
}
