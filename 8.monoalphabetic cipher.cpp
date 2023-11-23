#include <stdio.h>
#include <string.h>
#include <ctype.h>
void generateCipherAlphabet(char *keyword, char *cipherAlphabet) {
    strcpy(cipherAlphabet, keyword);
    for (int i = 0; i < strlen(keyword); ++i) {
        keyword[i] = toupper(keyword[i]);
    }

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (strchr(keyword, ch) == NULL) {
            strcat(cipherAlphabet, &ch);
        }
    }
}
void encrypt(char *plainText, char *cipherAlphabet, char *cipherText) {
    for (int i = 0; plainText[i]; ++i) {
        if (isalpha(plainText[i])) {
            char originalChar = toupper(plainText[i]);
            char encryptedChar;

            if (isupper(plainText[i])) {
                encryptedChar = cipherAlphabet[originalChar - 'A'];
            } else {
                encryptedChar = tolower(cipherAlphabet[originalChar - 'A']);
            }

            cipherText[i] = encryptedChar;
        } else {
            cipherText[i] = plainText[i];
        }
    }
}

int main() {
    char keyword[] = "CIPHER";
    char plainAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipherAlphabet[27];
    char plainText[1000];
    char cipherText[1000];

    generateCipherAlphabet(keyword, cipherAlphabet);
    printf("Enter the plaintext message: ");
    fgets(plainText, sizeof(plainText), stdin);
    encrypt(plainText, cipherAlphabet, cipherText);

    printf("Encrypted message: %s\n", cipherText);

    return 0;
}

