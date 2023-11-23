#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

void encryptPlayfair(char matrix[SIZE][SIZE], char *plainText, char *cipherText) {
    int i, j, row1, col1, row2, col2;

    for (i = 0; plainText[i] != '\0'; i += 2) {
        
        findPosition(matrix, plainText[i], &row1, &col1);
        findPosition(matrix, plainText[i + 1], &row2, &col2);
        if (row1 == row2) {
            cipherText[i] = matrix[row1][(col1 + 1) % SIZE];
            cipherText[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            cipherText[i] = matrix[(row1 + 1) % SIZE][col1];
            cipherText[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            cipherText[i] = matrix[row1][col2];
            cipherText[i + 1] = matrix[row2][col1];
        }
    }

    cipherText[i] = '\0';
}

int main() {
    char matrix[SIZE][SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    char plainText[] = "Must see you over Cadogan";
    char cipherText[1000];

    for (int i = 0; plainText[i]; ++i) {
        plainText[i] = toupper(plainText[i]);
    }

    encryptPlayfair(matrix, plainText, cipherText);

 
    printf("Encrypted message: %s\n", cipherText);

    return 0;
}

