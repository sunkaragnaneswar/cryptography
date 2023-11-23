#include <stdio.h>
#include <stdlib.h>

void decrypt(char *ciphertext) {
    char key[256];
    for (int i = 0; i < 256; ++i) {
        key[i] = i;
    }
    char decryptionKey[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < sizeof(decryptionKey) - 1; ++i) {
        key[decryptionKey[i]] = i;
    }

    for (int i = 0; ciphertext[i]; ++i) {
        if (ciphertext[i] >= 0 && ciphertext[i] < 256) {
            putchar(key[ciphertext[i]]);
        } else {
            putchar(ciphertext[i]);
        }
    }
}

int main() {
   
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83"
                        "(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*"
                        ";4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;";

    decrypt(ciphertext);
    return 0;
}

