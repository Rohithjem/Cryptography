PROGRAM:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt plaintext using the one-time pad VigenÃ¨re cipher
void encryptVigenere(char *plaintext, int *key, int keyLength) {
    int len = strlen(plaintext);
    int i;

    // Encrypting the plaintext
    for (i = 0; i < len; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            // Encrypt lowercase letters
            plaintext[i] = ((plaintext[i] - 'a' + key[i % keyLength]) % 26) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            // Encrypt uppercase letters
            plaintext[i] = ((plaintext[i] - 'A' + key[i % keyLength]) % 26) + 'A';
        }
        // Ignore non-alphabetic characters
    }

    printf("Encrypted Text: %s\n", plaintext);
}

int main() {
    char plaintext[500],key[500];
    printf("Enter the plaintext:");
    scanf("%s",plaintext);
    printf("enter the key:");
    scanf("%d",&key);
    

    // Determine the length of the key
    int keyLength = sizeof(key) / sizeof(key[0]);

    printf("Original Plaintext: %s\n", plaintext);
    
    printf("\n");

    // Encrypt the plaintext using the one-time pad VigenÃ¨re cipher
    encryptVigenere(plaintext, key, keyLength);

    return 0;
}
OUTPUT:
Enter the plaintext:WEAREDISCOVEREDSAVEYOURSELF
enter the key:9 0 1 7 23 15 21 14 11 11 2 8 9
Original Plaintext: WEAREDISCOVEREDSAVEYOURSELF

Encrypted Text: FKHRLLCVYRCHREPV1BWBWURS3RF
