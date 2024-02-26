#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

void print_hex(const unsigned char *buffer, size_t length) {
    for (size_t i = 0; i < length; ++i)
        printf("%02X", buffer[i]);
    printf("\n");
}

int main() {
    DES_cblock key1, key2, key3;
    DES_key_schedule ks1, ks2, ks3;
    DES_cblock iv = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    unsigned char plaintext[8] = "12345678";
    unsigned char ciphertext[8];
    
    // Set your 3DES keys here
    // For demonstration purposes, we'll use three identical keys
    memset(key1, 0x01, 8);
    memset(key2, 0x01, 8);
    memset(key3, 0x01, 8);

    DES_set_key(&key1, &ks1);
    DES_set_key(&key2, &ks2);
    DES_set_key(&key3, &ks3);

    // Encryption
    DES_ede3_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &ks1, &ks2, &ks3, &iv, DES_ENCRYPT);

    printf("Ciphertext: ");
    print_hex(ciphertext, sizeof(ciphertext));

    return 0;
}
