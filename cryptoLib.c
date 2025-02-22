#include "cryptoLib.h"
#include <stdio.h>
#include <stdlib.h>

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

unsigned long long gcd_simple(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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

unsigned int Exponent(long long x, long long e, long long p) {
    unsigned int result = 1;
    x = x % p;

    // process exponent bit by bit
    while (e > 0) {
        if (e & 1) result = (unsigned int)((result * x) % p);
        e >>= 1; //shift right
        x = (x * x) % p;
    }
    return result;
}

unsigned int RandomOdd32Bit(void) {
    unsigned int num = 0;
    //set msb and lsb
    num |= (1U << 31) | 1U;
    //fill middle bits with random numbers
    for (int i = 1; i < 31; i++) {
        int bit = rand() & 1;
        if (bit) num |= (1U << i);
    }
    return num;
}

int check_primility(unsigned long long n) {
    if ( n < 2 ) return 0;
    if ( n == 2 || n == 3) return 1;
    if ((n & 1ULL) == 0) return 0; //even numbers

    for (int round = 0; round < 20; round++) {
        unsigned long long a = 2 + rand() % (n-3); // [2,n-2]

        if (gcd_simple((int)a, (int)n) != 1) return 0;

        unsigned long long p = n - 1;

        if (Exponent(a,p,n) != 1) return 0;

        p /= 2;
        int witnessPassed = 0;
        // while p is even check a^p mod n
        while ((p & 1ULL) == 0 && p > 0) {
            unsigned int x = Exponent(a,p,n);
            if (x == 1) { p /= 2; continue; }
            else if (x == n - 1) {
                witnessPassed = 1;
                break;
            } else { return 0;}
        }
        if (!witnessPassed) return 0;
    }
    // if all pased then n is prime
    return 1;
}

unsigned long long Generate_long_prime(unsigned int *guessCount) {
    unsigned long long candidate;
    *guessCount = 0;
    do {
        candidate = RandomOdd32Bit();
        (*guessCount)++;
    } while (!check_primility(candidate));
    return candidate;
}