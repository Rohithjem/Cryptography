#include <stdio.h>
#include <string.h>

#define SIZE 5

void generate_keytable(char key[], char keytable[][SIZE]);
void decrypt(char keytable[][SIZE], char ciphertext[], char plaintext[]);

int main() {
    char key[] = "PTBOATSFORJFK";
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    
    char plaintext[100], keytable[SIZE][SIZE];
    
    // Generate keytable from key
    generate_keytable(key, keytable);
    
    // Decrypt ciphertext using keytable
    decrypt(keytable, ciphertext, plaintext);
    
    // Print decrypted text
    printf("Decrypted text: %s\n", plaintext);
    
    return 0;
}

void generate_keytable(char key[], char keytable[][SIZE]) {
    int i, j, k, len;
    char temp[26] = {0};
    
    // Remove duplicates from key
    len = strlen(key);
    for (i = 0, k = 0; i < len; i++) {
        if (key[i] == 'J') {
            key[i] = 'I';
        }
        if (temp[key[i] - 'A'] == 0) {
            temp[key[i] - 'A'] = 1;
            keytable[k / SIZE][k % SIZE] = key[i];
            k++;
        }
    }
    
    // Fill remaining cells with unused letters
    for (i = 0, j = k; i < 26; i++) {
        if (temp[i] == 0) {
            keytable[j / SIZE][j % SIZE] = i + 'A';
            j++;
        }
    }
}

void decrypt(char keytable[][SIZE], char ciphertext[], char plaintext[]) {
    int i, j, k, len;
    char a, b;
    
    // Remove spaces from ciphertext
    len = strlen(ciphertext);
    for (i = 0, k = 0; i < len; i++) {
        if (ciphertext[i] != ' ') {
            plaintext[k++] = ciphertext[i];
        }
    }
    plaintext[k] = '\0';
    
    // Decrypt pairs of letters
    for (i = 0; i < k; i += 2) {
        a = plaintext[i];
        b = plaintext[i + 1];
        
        // Find positions of letters in keytable
        int row1, col1, row2, col2;
        for (j = 0; j < SIZE; j++) {
            for (k = 0; k < SIZE; k++) {
                if (keytable[j][k] == a) {
                    row1 = j;
                    col1 = k;
                }
                if (keytable[j][k] == b) {
                    row2 = j;
                    col2 = k;
                }
            }
        }
        
        // Decrypt pair of letters
        if (row1 == row2) {
            plaintext[i] = keytable[row1][(col1 - 1 + SIZE) % SIZE];
            plaintext[i + 1] = keytable[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            plaintext[i] = keytable[(row1 - 1 + SIZE) % SIZE][col1];
            plaintext[i + 1] = keytable[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            plaintext[i] = keytable[row1][col2];
            plaintext[i + 1] = keytable[row2][col1];
        }
    }
}
OUTPUT:
Decrypted text: IYMCXYREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ
