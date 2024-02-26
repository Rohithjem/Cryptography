#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to decrypt the ciphertext
void decrypt(char *ciphertext, char *key) {
    int i, j;

    // Traverse the ciphertext
    for (i = 0; ciphertext[i] != '\0'; i++) {
        // Check if the character is an uppercase letter
        if (isupper(ciphertext[i])) {
            // Find the corresponding character in the key and replace
            for (j = 0; j < 26; j++) {
                if (key[j] == ciphertext[i]) {
                    ciphertext[i] = 'A' + j;
                    break;
                }
            }
        }
        // Check if the character is a lowercase letter
        else if (islower(ciphertext[i])) {
            // Find the corresponding character in the key and replace
            for (j = 0; j < 26; j++) {
                if (tolower(key[j]) == ciphertext[i]) {
                    ciphertext[i] = tolower('A' + j);
                    break;
                }
            }
        }
    }

    // Print the decrypted text
    printf("Decrypted Text: %s\n", ciphertext);
}

int main() {
    char ciphertext[500];
    printf("Enter the ciphertext message:");
    scanf("%s",ciphertext);
    // Enter your ciphertext here
    char key[] = "BCDEFGHIJKLMNOPQRSTUVWXYZA"; // Enter your substitution key here

    // Decrypt the ciphertext using the provided key
    decrypt(ciphertext, key);

    return 0;
}
OUTPUT:
Enter the ciphertext message:rffy,iffj,effb
Decrypted Text: qeex,heei,deea
OUTPUT:
Enter the ciphertext message:the
Decrypted Text: sgd
OUTPUT:
Enter the ciphertext message:the,deer,is,nice
Decrypted Text: sgd,cddq,hr,mhbd
