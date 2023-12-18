#include "wordmachine.h"
#include <stdio.h>

int main() {
    /* KAMUS */
    int i;

    /* ALGORITMA */
    STARTWORD();

    while (!EndWord) {
        printf("\"");
        for (i = 0; i < currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        printf("\"");
        printf("\n");
        ADVWORD();
    }
}