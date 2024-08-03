#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Remove the newline character from the paragraph
    paragraph[strcspn(paragraph, "\n")] = '\0';

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " ,.-");
    while (token != NULL) {
        toLowerCase(token);

        // Check if the word is already in the array
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the array
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], token);
            freq[wordCount]++;
            wordCount++;
        }

        token = strtok(NULL, " ,.-");
    }

    // Print the frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
