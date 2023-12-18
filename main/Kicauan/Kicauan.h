#ifndef KICAUAN_H
#define KICAUAN_H

#include "../../modules/adt.h"
#include "../../modules/tree/tree.h"
#include "../Pengguna/Pengguna.h"
#include "../includeADT.h"
#include "../Balasan/balasan.h"

#define MAXChar 281

typedef struct kicausambung *kSambungAdd;
typedef struct kicausambung {
    int index;
    char text[MAXChar];
    DATETIME datetime;
    Word author;
    kSambungAdd next;
} KicauSambung;

typedef struct {
    int IDUtas;
    kSambungAdd content;
} Utas;
typedef struct {
    int id;
    int like;
    char text[MAXChar];
    Word author;
    DATETIME datetime;
    Utas* utasKicau;
    char tagar[MAXChar];
    int jumlahBalasan;
    TreeBalasan balasan;
} Kicau;

typedef struct {
    Kicau* kicau;
    int Cap;
    int nEff;
} ListKicau;

int GetAccountIndex(AccountList *list, Account account);
ListKicau CreateListKicau(ListKicau *list);
int CreateIDKicau(ListKicau *list);
void AddToKicauan(ListKicau *list, Kicau k);
void CreateKicau(Account akunLogin, ListKicau *list, Kicau *k);
void BaseDisplay (Kicau k);
void Kicauan(Account akunLogin, ListKicau list);
void SukaKicau (Account akunLogin, Word id, ListKicau *listkicau, Kicau *k, AccountList* listakun, Graf teman);
boolean isIdInKicauan (int id, ListKicau *list);
void UbahKicau (Account akunLogin, Word id, ListKicau *list);
void ReadKicau_FILE(char filename[], ListKicau *kList);
int idxOfKicauan(int id, ListKicau listKicau);
int listLengthKicauan(ListKicau list);

#endif