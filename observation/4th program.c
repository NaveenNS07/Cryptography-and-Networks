#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateKey(char *plaintext, char *keyword, char *key) {
    int ptLen = strlen(plaintext);
    int keyLen = strlen(keyword);
    for (int i = 0; i < ptLen; i++) {
        key[i] = keyword[i % keyLen];
    }
    key[ptLen] = '\0';
}

void encryptVigenere(char *plaintext, char *key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            char p = tolower(plaintext[i]) - 'a';
            char k = tolower(key[i]) - 'a';
            ciphertext[i] = ((p + k) % 26) + base;
        } else {
            ciphertext[i] = plaintext[i];  
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100], keyword[100], key[100], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the keyword: ");
    scanf("%s", keyword);

    generateKey(plaintext, keyword, key);
    encryptVigenere(plaintext, key, ciphertext);

    printf("Vigenère Cipher Text: %s\n", ciphertext);

    return 0;
}
