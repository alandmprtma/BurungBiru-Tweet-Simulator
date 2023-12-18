#ifndef utas_H
#define utas_H

#include "../includeADT.h"

boolean lanjut(Word input);
void cetakUtas(int idUtas, ListKicau kList, Account account, AccountList *listAccount, Graf teman);
void copyWordToString(char*destination,Word input);
kSambungAdd createKicauanSambung(Word tex, Account account);
void sambungUtas(int idUtas, int index, ListKicau *kList, Account account);
void hapusUtas(int idUtas, int index, ListKicau *kList, Account account);
void createUtas(int id, ListKicau *kList, Account account, int *jumlahUtas);

#endif