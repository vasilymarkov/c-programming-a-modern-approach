#include <stdio.h>

#define SIZE 64

char *print_bits2(unsigned int val);

int main(void)
{
    struct float_str {
        unsigned int fraction: 23;
        unsigned int exponent: 8;
        unsigned int sign: 1;
    };
    union {
        struct float_str s;
        unsigned int n;
        float f;
    } u;

    printf("sizeof(float) = %d\n", (int) sizeof(float));
    printf("sizeof(unsigned int) = %d\n", (int) sizeof(unsigned int));

    printf("Enter a hexadecimal value: ");
    scanf("%x", &u.n);
    printf("Float value        %e\n",  u.f);
    printf("Value in binary    %s\n",  print_bits2(u.n));
    printf("Fraction in binary %s\n",  print_bits2(u.s.fraction));
    printf("Exponent in binary %s\n",  print_bits2(u.s.exponent));
    printf("Sign in binary     %s\n",  print_bits2(u.s.sign));

    return 0;
}

/* Prints bits of binary value */
/* Version 2 */
char *print_bits2(unsigned int val)
{
    int i, j, k, b[SIZE], n = sizeof(unsigned int) * 8;
    static char str[SIZE+SIZE/8];

    if (val > 0)
        for (i = 0; val > 0; i++) {
            b[i] = val & 0x1;
            val >>= 1;
        }
    else
        i = 1;

    while (i < n)
        b[i++] = 0;

    for (j = i - 1, i = 0, k = 1; j >= 0; ) {
        str[i++] = b[j--] + '0';
        if (!(k++ % 8))
            str[i++] = ' ';
    }
    str[--i] = '\0';

    return str;
}
