#include <stdio.h>
#include <string.h>

#define SIZE 5
void findPosition(char matrix[SIZE][SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // I and J are usually treated as the same letter in Playfair

    for (*row = 0; *row < SIZE; ++(*row)) {
        for (*col = 0; *col < SIZE; ++(*col)) {
            if (matrix[*row][*col] == ch) {
                return;
            }
        }
    }
}
void decryptPlayfair(char matrix[SIZE][SIZE], char *cipherText, char *plainText) {
    int i, j, row1, col1, row2, col2;

    for (i = 0; cipherText[i] != '\0'; i += 2) {
        
        findPosition(matrix, cipherText[i], &row1, &col1);
        findPosition(matrix, cipherText[i + 1], &row2, &col2);

            if (row1 == row2) {
            plainText[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            plainText[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            plainText[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            plainText[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            plainText[i] = matrix[row1][col2];
            plainText[i + 1] = matrix[row2][col1];
        }
    }

    plainText[i] = '\0';
}

int main() {
     char key[] = "PT109";
    char matrix[SIZE][SIZE];
    char cipherText[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE";
    char plainText[1000];
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J is omitted
    strcat(key, alphabet);

    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = key[index++];
        }
    }
    decryptPlayfair(matrix, cipherText, plainText);
    printf("Decrypted message: %s\n", plainText);

    return 0;
}

