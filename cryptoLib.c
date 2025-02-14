#include "cryptoLib.h"
#include <stdio.h>

void GCD(long long a, long long b, long long* gcd, long long* m, long long* n) {
    long long r0 = a, r1 = b;
    long long s0 = 1, s1 = 0;
    long long t0 = 0, t1 = 1;

    while (r1 != 0) {
        long long q = r0 / r1;
        
        long long r2 = r0 - q * r1;
        r0 = r1;
        r1 = r2;
        
        long long s2 = s0 - q * s1;
        s0 = s1;
        s1 = s2;
        
        long long t2 = t0 - q * t1;
        t0 = t1;
        t1 = t2;
    }
    
    *gcd = r0;
    *m = s0;
    *n = t0;
}

int inverse(long long a, long long n) {
    long long gcd, m, t;
    GCD(a, n, &gcd, &m, &t);

    if (gcd != 1) {
        return -1;
    }

    long long inv = m % n; //%n is to make code more robus, in cases if we get m > n
    if (inv < 0) {
        inv += n;
    }
    return (int)inv;
}

int solve_system_CRT(long long a, long long p, long long b, long long q) {

    long long bigN = p * q;
    long long inv_ap = inverse(q,p);
    long long inv_bq = inverse(p,q);

    long long multRes1 = a * q * inv_ap;
    long long multRes2 = b * p * inv_bq;

    return (multRes1 + multRes2) % bigN;
}