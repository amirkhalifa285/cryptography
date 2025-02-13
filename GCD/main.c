#include <stdio.h>
#include "../cryptoLib.h"

int main() {
    int a, b, gcd, m, n;

    // Test case 1
    a = 7469;
    b = 2464;
    GCD(a, b, &gcd, &m, &n);
    printf("Test 1: GCD(%d, %d)\n", a, b);
    printf("gcd = %d, m = %d, n = %d\n", gcd, m, n);
    printf("Verification: %d*%d + %d*%d = %d\n\n", a, m, b, n, a*m + b*n);

    // Test case 2
    a = 4001;
    b = 2689;
    GCD(a, b, &gcd, &m, &n);
    printf("Test 2: GCD(%d, %d)\n", a, b);
    printf("gcd = %d, m = %d, n = %d\n", gcd, m, n);
    printf("Verification: %d*%d + %d*%d = %d\n", a, m, b, n, a*m + b*n);

    return 0;
}