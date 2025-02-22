#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../cryptoLib.h"

int main (void) {
    srand((unsigned int)time(NULL)); //seed the random num generator

    unsigned int guesses = 0;
    unsigned long long prime = Generate_long_prime(&guesses);

    printf("Generated 32-bit prime: %llu\n", prime);
    printf("Number of guesses: %u\n", guesses);

    return 0;
}