#include <stdio.h>

#define ALPHABET_SIZE 26

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

void decrypt(const char* ciphertext, int a, int b) {
    int a_inv = modInverse(a, ALPHABET_SIZE);

    printf("Attempting to decrypt using a = %d and b = %d...\n", a, b);

    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        char ch = ciphertext[i];
        char decrypted_ch;

        if (isalpha(ch)) {
            if (islower(ch)) {
                decrypted_ch = 'a' + (a_inv * (26 + ch - 'a' - b)) % 26;
            } else {
                decrypted_ch = 'A' + (a_inv * (26 + ch - 'A' - b)) % 26;
            }
        } else {
            decrypted_ch = ch;
        }

        printf("%c", decrypted_ch);
    }

    printf("\n");
}

int main() {
    const char* ciphertext = "BXUUJBBUBBUBZB";
    int a_guess, b_guess;

    // Define the most frequent letters of the ciphertext
    char most_frequent = 'B';
    char second_most_frequent = 'U';

    // Calculate the shift required to get from 'B' to 'A' (most frequent -> 'E')
    int shift_b = most_frequent - 'A';
    // Calculate the shift required to get from 'U' to 'E' (second most frequent -> 'T')
    int shift_u = second_most_frequent - 'E';

    // Find the value of 'a' by taking the inverse of the shift_b
    int a = modInverse(shift_b, ALPHABET_SIZE);

    // Calculate the value of 'b' using the found 'a' and shift_u
    int b = (a * shift_u) % ALPHABET_SIZE;

    // Print the found 'a' and 'b'
    printf("Found values: a = %d, b = %d\n", a, b);

    // Decrypt the ciphertext using the found 'a' and 'b'
    decrypt(ciphertext, a, b);

    return 0;
}
OUTPUT:
Found values: a = 1, b = 16
Attempting to decrypt using a = 1 and b = 16...
LHEETLLELLELJL
