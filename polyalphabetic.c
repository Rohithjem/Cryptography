#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to perform polyalphabetic substitution encryption
void polyalphabeticEncrypt(char *plaintext, char *key) {
    int keyLen = strlen(key);
    int keyIndex = 0;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int shift = tolower(key[keyIndex]) - 'a'; // Calculate shift based on key
            plaintext[i] = ((ch - base + shift) % 26) + base;
            keyIndex = (keyIndex + 1) % keyLen; // Move to the next key character
        }
    }
}

// Function to perform polyalphabetic substitution decryption
void polyalphabeticDecrypt(char *ciphertext, char *key) {
    int keyLen = strlen(key);
    int keyIndex = 0;
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            int shift = tolower(key[keyIndex]) - 'a'; // Calculate shift based on key
            ciphertext[i] = ((ch - base - shift + 26) % 26) + base;
            keyIndex = (keyIndex + 1) % keyLen; // Move to the next key character
        }
    }
}

int main() {
    char plaintext[1000], ciphertext[1000], key[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    scanf("%s", key);

    // Encrypt the plaintext
    strcpy(ciphertext, plaintext); // Copy plaintext to ciphertext initially
    polyalphabeticEncrypt(ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    polyalphabeticDecrypt(ciphertext, key);
    printf("Decrypted text: %s\n", ciphertext);

    return 0;
}

OUTPUT:
Enter plaintext: rohith
Enter key: deceptive
Encrypted text: usjmia

Decrypted text: rohith
