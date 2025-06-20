#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarEncrypt(char *plaintext, int key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ciphertext[i] = ((ch - base + key) % 26) + base;
        } else {
            ciphertext[i] = ch; 
        }
    }
    ciphertext[i] = '\0'; 
}

int main() {
    char plaintext[100], ciphertext[100];
    int key;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    printf("Enter the key (shift amount): ");
    scanf("%d", &key);

    key = key % 26;

    caesarEncrypt(plaintext, key, ciphertext);

    printf("Caesar Cipher Text: %s\n", ciphertext);

    return 0;
}
