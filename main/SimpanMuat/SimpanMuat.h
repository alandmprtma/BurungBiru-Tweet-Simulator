#ifndef SimpanMuat_H
#define SimpanMuat_H

#include "../includeADT.h"

#define MAXChar 281
void concatStr(char *path,char folder[]);
boolean isDirExist(char path[]);
void loadUtas(char filename[],ListKicau* kList, int* jumlahUtas, AccountList akunList);
void loadTweetCnfg(char filename[],ListKicau* kList);
void ReadUser_FILE(char filename[], AccountList *list, Graf *Teman, prioqueuefren *Q);
// /* void ReadDraf_FILE(char filename[], AccountList *list, Stack *S); */
// /*Membaca file Draf dari Draf.config kedalam program
//     I.S. Stack terdefinisi dan AccountList sudah diakuisisi dari user.config
//     F.S. Stack terisi dengan drafkicauan dari Draf.Config
//     */
void ReadDraf_FILE(char filename[], AccountList *list, Stack *S);
void readUtas(char filename[], ListKicau* kList, int* jumlahUtas, AccountList akunList);
void muat(char folderName[],AccountList *listakun, Graf *Teman, prioqueuefren *Q,ListKicau * kList, Stack* draf, int* jumlahUtas);
void wordToString(char destination[MAXChar],Word input);

void SaveUser_FILE(char filename[], AccountList *list, Graf Teman, prioqueuefren Q);
void saveUtas(char filename[],ListKicau* kList, int jumlahUtas, AccountList akunList);
void saveTweet(char filename[],ListKicau* kList);
void SaveDraf_FILE(char filename[], AccountList *list, Stack S[]);
/*Menyimpan file Draf dari program kedalam Draf.config
    I.S. Stack terdefinisi dan AccountList sudah diakuisisi dari user.config
    F.S. Stack terisi dengan drafkicauan dari Draf.Config
    */
void concatStrings(const char *str1, const char *str2, char *result);
char* copyString(const char* str);
#endif