#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

void GCD(long long a, long long b, long long* gcd, long long* m, long long* n);

unsigned long long gcd_simple(unsigned long long a, unsigned long long b);

int inverse(long long a, long long n);

int solve_system_CRT(long long a, long long p, long long b, long long q);

unsigned int Exponent(long long x, long long e, long long p); //multiply & square algorithm

unsigned int RandomOdd32Bit(void);

int check_primility(unsigned long long n);

unsigned long long Generate_long_prime(unsigned int *guessCount);

#endif