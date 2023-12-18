#include <stdio.h>
#include "includeADT.h"

int main() {
    char fold[] = "../cf";
    if (!isDirExist(fold)){
        int check = mkdir(fold,0777);
        printf("creating folder!\n");
    }
    FILE *configFile = fopen("../cf/penugguna.config", "w");
    STARTWORD_FILE("../cfg/pengguna.config");
    while (currentChar != MARK) {
        if (EndWord){
            for (int i=0;i<currentWord.Length;i++){
                fprintf(configFile, "%c", currentWord.TabWord[i]);
            }
        }
        fprintf(configFile,"\n");
        ADVSENTENCENL();
        
    }
    // if (configFile == NULL) {
    //     perror("Unable to open config file.\n");
    //     return 1;
    // }

    // START();
    // while (currentChar != MARK) {
    //     fprintf(configFile, "%c", currentChar);
    //     ADV();
    // }

    fclose(configFile);

    return 0;
}