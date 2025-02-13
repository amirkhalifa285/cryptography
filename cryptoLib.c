#include "cryptoLib.h"
#include <stdio.h>

void GCD(int a, int b, int* gcd, int* m, int* n) {
    int r0 = a, r1 = b;
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;

    while (r1 != 0) {
        int q = r0 / r1;
        
        int r2 = r0 - q * r1;
        r0 = r1;
        r1 = r2;
        
        int s2 = s0 - q * s1;
        s0 = s1;
        s1 = s2;
        
        int t2 = t0 - q * t1;
        t0 = t1;
        t1 = t2;
    }
    
    *gcd = r0;
    *m = s0;
    *n = t0;
}