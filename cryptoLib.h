#ifndef CRYPTOLIB_H
#define CRYPTOLIB_H

void GCD(long long a, long long b, long long* gcd, long long* m, long long* n);

int inverse(long long a, long long n);

int solve_system_CRT(long long a, long long p, long long b, long long q);

#endif