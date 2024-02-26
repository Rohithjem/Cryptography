#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

// Function to print the Playfair matrix
void printPlayfairMatrix(char matrix[SIZE][SIZE]) {
    printf("Playfair Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to encrypt the plaintext using Playfair cipher
void encryptPlayfair(char plaintext[], char matrix[SIZE][SIZE]) {
    int i, j;
    char ch1, ch2;
    int row1, col1, row2, col2;
    int len = strlen(plaintext);
    char encryptedText[1000];
    int index = 0;

    // Adjust the plaintext if the same letter is repeated consecutively
    for (i = 0; i < len - 1; i++) {
        if (plaintext[i] == plaintext[i + 1]) {
            for (j = len; j > i + 1; j--) {
                plaintext[j] = plaintext[j - 1];
            }
            plaintext[i + 1] = 'X'; // Insert 'X' between consecutive repeated letters
            len++;
        }
    }

    // Encrypt the plaintext using the Playfair matrix
    for (i = 0; i < len; i += 2) {
        ch1 = toupper(plaintext[i]);
        ch2 = toupper(plaintext[i + 1]);

        // Find the positions of characters in the matrix
        for (j = 0; j < SIZE; j++) {
            if (strchr(matrix[j], ch1) != NULL) {
                row1 = j;
                col1 = strchr(matrix[j], ch1) - matrix[j];
            }
            if (strchr(matrix[j], ch2) != NULL) {
                row2 = j;
                col2 = strchr(matrix[j], ch2) - matrix[j];
            }
        }

        // Encrypt the characters based on their positions
        if (row1 == row2) {
            encryptedText[index++] = matrix[row1][(col1 + 1) % SIZE];
            encryptedText[index++] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText[index++] = matrix[(row1 + 1) % SIZE][col1];
            encryptedText[index++] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText[index++] = matrix[row1][col2];
            encryptedText[index++] = matrix[row2][col1];
        }
    }
    encryptedText[index] = '\0';

    printf("Encrypted Text: %s\n", encryptedText);
}

int main() {
    char matrix[SIZE][SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    char plaintext[1000];
    char keyword[100];

    // Get plaintext and keyword from the user
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline
    printf("Enter keyword: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove trailing newline

    // Encrypt the plaintext using the Playfair cipher
    encryptPlayfair(plaintext, matrix);

    return 0;
}
OUTPUT:
Enter plaintext: Must see you over Cadogan West. Coming at once.
Enter keyword: NETWORK
Encrypted Text: UZTBTTRZRZWQNPNWLGGDETQALOTALDBTBDUHFPLQTHTWQSGD
