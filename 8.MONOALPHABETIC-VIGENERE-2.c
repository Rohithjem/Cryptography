#include <stdio.h>
#include <string.h>

int main() {
    char keyword[] = "CIPHER";
    char plaintext[100], ciphertext[100];
    int i, j, k, len_keyword, len_plaintext;

    // Get input from user
    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);
    len_plaintext = strlen(plaintext);

    // Remove newline character from input
    if (plaintext[len_plaintext - 1] == '\n') {
        plaintext[len_plaintext - 1] = '\0';
        len_plaintext--;
    }

    // Generate cipher sequence from keyword
    len_keyword = strlen(keyword);
    char cipher_seq[26];
    for (i = 0; i < len_keyword; i++) {
        cipher_seq[i] = keyword[i];
    }
    for (j = 0, k = i; j < 26; j++) {
        if (strchr(keyword, 'A' + j) == NULL) {
            cipher_seq[k++] = 'A' + j;
        }
    }

    // Encrypt plaintext using cipher sequence
    for (i = 0; i < len_plaintext; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = cipher_seq[plaintext[i] - 'A'];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';

    // Print encrypted text
    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
OUTPUT:
Enter plaintext: MONOALPHABETIC
Encrypted text: KMLMCJNBCIETDP
