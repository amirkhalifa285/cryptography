#include <stdio.h>
#include "../cryptoLib.h"

int main() {
    // --- Test the inverse function with hardcoded example ---
    // Example: Find the modular inverse of 2 modulo 5.
    // We expect the inverse to be 3, since 2*3 = 6 ≡ 1 (mod 5)
    long long a = 2, n = 5;
    int inv = inverse(a, n);
    if (inv == -1) {
        printf("Inverse does not exist for %lld modulo %lld\n", a, n);
    } else {
        printf("The modular inverse of %lld modulo %lld is: %d\n", a, n, inv);
    }
    
    // --- Test the simultaneous congruence system with hardcoded example ---
    // Example: Solve the system:
    //    x ≡ 2 (mod 3)
    //    x ≡ 3 (mod 5)
    // The solution is unique modulo 15. Expected solution: x = 8 mod 15,
    // since 8 mod 3 = 2 and 8 mod 5 = 3.
    long long A = 2, p = 3, B = 3, q = 5;
    int x = solve_system_CRT(A, p, B, q);
    printf("\nThe solution of the system:\n");
    printf("    x ≡ %lld (mod %lld)\n    x ≡ %lld (mod %lld)\n", A, p, B, q);
    printf("is x = %d (mod %lld)\n", x, p * q);
    printf("Verification: x mod %lld = %lld,  x mod %lld = %lld\n", p, x % p, q, x % q);

    return 0;
}