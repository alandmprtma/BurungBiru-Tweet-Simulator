#include "SimpanMuat.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char folderName[] = "contoh";
    char path[] = "../../cfg/";
    char *folder= (char *)malloc(strlen(path) + strlen(folderName) + 1);
    strcpy(folder,path);
    strcat(folder,folderName);
    if (!isDirExist(folder)){
        printf("Tidak ada folder yang dimaksud!\n");
    }else{
        for (int i=0;i<5;i++){
            if (i==0){ // User config
                // ReadUser_FILE(concatStr(folder,"pengguna.config"),list,Teman, Q);
            }
            else if (i==1){ // Tweet config

            } 
            else if (i==2){ // Draft config

            }
            else if (i==3){ // Utas config

            }
            else if (i==4){ //Reply config

            }
            printf("Ada\n");
        }
    }
    return 0;
}