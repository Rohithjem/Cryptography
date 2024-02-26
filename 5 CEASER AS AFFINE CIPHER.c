#include <stdio.h>

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

char encrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        if (islower(ch)) {
            return 'a' + ((a * (ch - 'a') + b) % 26);
        } else {
            return 'A' + ((a * (ch - 'A') + b) % 26);
        }
    } else {
        return ch;
    }
}

char decrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        int a_inv = modInverse(a, 26);
        if (islower(ch)) {
            return 'a' + (a_inv * (26 + ch - 'a' - b)) % 26;
        } else {
            return 'A' + (a_inv * (26 + ch - 'A' - b)) % 26;
        }
    } else {
        return ch;
    }
}

int main() {
    char message[100];
    int a, b;

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    while (gcd(a, 26) != 1) {
        printf("The value of 'a' must be coprime with 26. Enter again: ");
        scanf("%d", &a);
    }

    printf("Enter the key 'b': ");
    scanf("%d", &b);

    for (int i = 0; message[i] != '\0'; ++i) {
        message[i] = encrypt(message[i], a, b);
    }

    printf("Encrypted message: %s\n", message);

    printf("Decrypting message...\n");

    for (int i = 0; message[i] != '\0'; ++i) {
        message[i] = decrypt(message[i], a, b);
    }

    printf("Decrypted message: %s\n", message);

    return 0;
}
OUTPUT:
Enter message to encrypt: affinecipher
Enter the key 'a' (must be coprime with 26): 5
Enter the key 'b': 8
Encrypted message: ihhwvcswfrcp

Decrypting message...
Decrypted message: affinecipher
