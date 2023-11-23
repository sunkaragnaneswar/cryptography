#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to count the frequency of each letter in the ciphertext
void countLetterFrequency(const char *ciphertext, int *frequency) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = tolower(ciphertext[i]);
        if (isalpha(c)) {
            frequency[c - 'a']++;
        }
    }
}

// Function to perform monoalphabetic substitution based on a key
void decryptWithKey(const char *ciphertext, const char *key) {
    printf("Plaintext with key '%s': ", key);
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = tolower(ciphertext[i]);
        if (isalpha(c)) {
            char decryptedChar = key[c - 'a'];
            if (isupper(ciphertext[i])) {
                decryptedChar = toupper(decryptedChar);
            }
            printf("%c", decryptedChar);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}

// Function to compare frequencies for qsort
int compareFrequencies(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// Function to perform a letter frequency attack
void letterFrequencyAttack(const char *ciphertext) {
    int frequency[ALPHABET_SIZE] = {0};

    // Count letter frequencies in the ciphertext
    countLetterFrequency(ciphertext, frequency);

    // Create a copy of frequencies for sorting
    int sortedFrequency[ALPHABET_SIZE];
    memcpy(sortedFrequency, frequency, sizeof(frequency));

    // Sort frequencies in descending order
    qsort(sortedFrequency, ALPHABET_SIZE, sizeof(int), compareFrequencies);

    // Generate possible keys based on the sorted frequencies
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char key[ALPHABET_SIZE + 1];
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            int index = (j + i) % ALPHABET_SIZE;
            key[j] = 'a' + index;
        }
        key[ALPHABET_SIZE] = '\0';

        // Decrypt the ciphertext with the current key
        decryptWithKey(ciphertext, key);
    }
}

int main() {
    const char *ciphertext = "Wklv lv d whvw phvvdjh.";
    
    printf("Ciphertext: %s\n", ciphertext);

    // Perform letter frequency attack
    letterFrequencyAttack(ciphertext);

    return 0;
}

