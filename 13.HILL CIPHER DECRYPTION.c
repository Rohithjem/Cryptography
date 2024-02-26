PROGRAM:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 10

// Function to convert a character to its corresponding numerical value (A=0, B=1, ..., Z=25)
int charToNum(char ch) {
    return toupper(ch) - 'A';
}

// Function to convert a numerical value to its corresponding character (0=A, 1=B, ..., 25=Z)
char numToChar(int num) {
    return num + 'A';
}

// Function to calculate the determinant of a 2x2 matrix
int determinant(int a, int b, int c, int d) {
    return a * d - b * c;
}

// Function to calculate the modular multiplicative inverse of a number 'a' modulo 'm'
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to encrypt plaintext using Hill cipher
void encrypt(char *plaintext, int key[][MAX_SIZE], int keySize) {
    int len = strlen(plaintext);
    int ptMatrix[MAX_SIZE][1], ctMatrix[MAX_SIZE][1];

    // Convert plaintext to numerical values
    for (int i = 0; i < len; i++)
        ptMatrix[i][0] = charToNum(plaintext[i]);

    // Pad plaintext if necessary
    while (len % keySize != 0) {
        ptMatrix[len][0] = charToNum('X');
        len++;
    }

    // Encrypt in blocks of keySize
    for (int i = 0; i < len; i += keySize) {
        for (int j = 0; j < keySize; j++) {
            ctMatrix[j][0] = 0;
            for (int k = 0; k < keySize; k++)
                ctMatrix[j][0] += key[j][k] * ptMatrix[i + k][0];
            ctMatrix[j][0] %= 26;
        }
        // Print the encrypted block
        for (int j = 0; j < keySize; j++)
            printf("%c", numToChar(ctMatrix[j][0]));
    }
}

// Function to decrypt ciphertext using Hill cipher
void decrypt(char *ciphertext, int key[][MAX_SIZE], int keySize) {
    int len = strlen(ciphertext);
    int ctMatrix[MAX_SIZE][1], ptMatrix[MAX_SIZE][1];
    int det = determinant(key[0][0], key[0][1], key[1][0], key[1][1]);
    int detInv = modInverse(det, 26);

    // Find the adjugate matrix
    int adj[2][2] = {{key[1][1], -key[0][1]}, {-key[1][0], key[0][0]}};

    // Calculate the inverse of key matrix
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            key[i][j] = adj[i][j] * detInv;
            while (key[i][j] < 0)
                key[i][j] += 26;
            key[i][j] %= 26;
        }
    }

    // Decrypt in blocks of keySize
    for (int i = 0; i < len; i += keySize) {
        for (int j = 0; j < keySize; j++) {
            ctMatrix[j][0] = charToNum(ciphertext[i + j]);
        }
        for (int j = 0; j < keySize; j++) {
            ptMatrix[j][0] = 0;
            for (int k = 0; k < keySize; k++)
                ptMatrix[j][0] += key[j][k] * ctMatrix[k][0];
            ptMatrix[j][0] %= 26;
        }
        // Print the decrypted block
        for (int j = 0; j < keySize; j++)
            printf("%c", numToChar(ptMatrix[j][0]));
    }
}

int main() {
    int key[MAX_SIZE][MAX_SIZE];
    int keySize;

    printf("Enter the size of the key matrix: ");
    scanf("%d", &keySize);

    printf("Enter the key matrix (in row-major order):\n");
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            scanf("%d", &key[i][j]);
        }
    }

    char plaintext[MAX_SIZE * MAX_SIZE];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Encryption result: ");
    encrypt(plaintext, key, keySize);
    printf("\n");

    char ciphertext[MAX_SIZE * MAX_SIZE];
    printf("Enter the ciphertext: ");
    scanf("%s", ciphertext);

    printf("Decryption result: ");
    decrypt(ciphertext, key, keySize);
    printf("\n");

    return 0;
}
OUTPUT:
Enter the size of the key matrix: 2
Enter the key matrix (in row-major order):
9
4
5
7
Enter the plaintext: rohith
Encryption result: BBRNRO
Enter the ciphertext: bbrnro
Decryption result: ROHITH
