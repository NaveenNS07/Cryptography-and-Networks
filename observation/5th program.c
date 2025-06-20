#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void columnarTranspose(char *plaintext, char *key, char *ciphertext) {
    int ptLen = strlen(plaintext);
    int keyLen = strlen(key);

    int rows = ptLen / keyLen;
    if (ptLen % keyLen != 0) rows++;

    char matrix[rows][keyLen];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < keyLen; j++) {
            if (k < ptLen)
                matrix[i][j] = plaintext[k++];
            else
                matrix[i][j] = 'X';  
        }
    }

    int order[keyLen];
    for (int i = 0; i < keyLen; i++) {
        order[i] = i;
    }

    for (int i = 0; i < keyLen - 1; i++) {
        for (int j = i + 1; j < keyLen; j++) {
            if (key[order[i]] > key[order[j]]) {
                int temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }
        }
    }

    k = 0;
    for (int i = 0; i < keyLen; i++) {
        int col = order[i];
        for (int j = 0; j < rows; j++) {
            ciphertext[k++] = matrix[j][col];
        }
    }
    ciphertext[k] = '\0';
}

int main() {
    char plaintext[100], key[20], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  

    printf("Enter the key (e.g., ZEBRAS): ");
    scanf("%s", key);

    columnarTranspose(plaintext, key, ciphertext);

    printf("Transposition Cipher Text: %s\n", ciphertext);

    return 0;
}
