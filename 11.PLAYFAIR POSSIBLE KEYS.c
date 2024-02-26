#include <stdio.h>

long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n = 25;
    long long possibleKeys = factorial(n);
    printf("The number of possible keys for the Playfair cipher is approximately 2^%lld\n", possibleKeys);
    return 0;
}
OUTPUT:
The number of possible keys for the Playfair cipher is approximately 2^7034535277573963776
