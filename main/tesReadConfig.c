#include <stdio.h>
#include <sys/stat.h>
#include "includeADT.h"

int main() {
    char path[] = "../cfg/AS";
     if (!isDirExist(path)){
        printf("Tidak ada folder yang dimaksud!\n");
    }else{
        printf("ada\n");
    }
    STARTWORD_FILE("../cfg/pengguna.config");
    while (currentChar != MARK) {
        for (int i=0;i<currentWord.Length;i++){
            printf("%c",currentWord.TabWord[i]);
        }
        printf("\n");
        ADVSENTENCE();
        
    }

    return 0;
}

