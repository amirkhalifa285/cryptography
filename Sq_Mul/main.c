#include <stdio.h>
#include "../cryptoLib.h"

int main() {
    long long base = 3;
    long long exp = 97;
    long long mod = 101;

    unsigned int res = Exponent(base,exp,mod);
    printf("%lld^%lld mod %lld = %u\n",base,exp,mod,res);

    // Solving using CRT 
    long long x = 7, e = 26, p = 11, q = 13;
    long long modulus = p * q;

    unsigned int r1 = Exponent(x,e,p);
    unsigned int r2 = Exponent(x,e,q);

    int result = solve_system_CRT(r1, p, r2, q);

    printf("Given x = %lld, e = %lld, p = %lld, q = %lld\n", x, e, p, q);
    printf("Computed x^e mod p = %u, and x^e mod q = %u\n", r1, r2);
    printf("Result of CRT: x^e mod (p*q) = %d (mod %lld)\n", result, modulus);

    return 0;
}