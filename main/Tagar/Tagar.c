#include "Tagar.h"

void wordToStr(char destination[MAXChar],Word input){
    int i;
    for (i=0;i<input.Length;i++){
        (destination[i]) = input.TabWord[i];
    }
    destination[i] = '\0';
}

boolean compareWithoutHash(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 == '#' && *str2 != '#' && *(str1 + 1) == *str2) {
            str1++; // Lewati karakter '#'
        } else if (*str2 == '#' && *str1 != '#' && *str1 == *(str2 + 1)) {
            str2++; // Lewati karakter '#'
        } else if (*str1 != *str2) {
            return false;
        }

        str1++;
        str2++;
    }

    return *str1 == *str2; // Pastikan keduanya berakhir pada saat yang sama
}

char toLowerz(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch + ('a' - 'A');
    }
    return ch;
}

void toLowerCaze(const char *source, char *destination) {
    while (*source) {
        *destination = toLowerz(*source);
        source++;
        destination++;
    }
    *destination = '\0';  // Menambahkan null terminator pada akhir string
}

void KicauanTagar(ListKicau list, Word tags) {
    char tag[MAXChar];
    wordToStr(tag, tags);
    char dst1[MAXChar];
    char dst2[MAXChar];
    
    int found = 0;
    
    for (int i = list.nEff - 1; i >= 0; i--) {
        toLowerCaze(tag, dst1);
        toLowerCaze(list.kicau[i].tagar, dst2);
        if (compareWithoutHash(dst1, dst2)) {
            BaseDisplay(list.kicau[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Tidak ditemukan kicauan dengan tagar #%s!\n\n", tag);
    }
}