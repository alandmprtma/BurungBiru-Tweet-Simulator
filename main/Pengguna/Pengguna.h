#ifndef Pengguna_H
#define Pengguna_H

#include "../../modules/adt.h"
#define MAXChar 281
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_BIO_LENGTH 135
#define MAX_HP_LENGTH 100
#define MAX_WETON_LENGTH 50
#define MAX_JENIS_LENGTH 50
#define MARKACC '\0'

typedef struct {
    Word username[MAX_USERNAME_LENGTH];
    Word password[MAX_PASSWORD_LENGTH];
    Word bio[MAX_BIO_LENGTH];
    Word noHP[MAX_HP_LENGTH];
    Word weton[MAX_WETON_LENGTH];
    Word jenisAkun[MAX_JENIS_LENGTH];
    MatrixChar fotoprofil;
} Account;

#define Username(U) (U).username
#define Password(U) (U).password
#define Bio(U) (U).bio
#define NoHP(U) (U).noHP
#define Weton(U) (U).weton
#define JenisAkun(U) (U).jenisAkun
#define FotoProfil(U) (U).fotoprofil


#define MAX_ACCOUNTS 20
typedef struct {
    Account accounts[MAX_ACCOUNTS];
    int count;
} AccountList;

void inUser(Account *account, Word username);
// I.S. username terdefinisi

void outUser(Account *account);
// I.S. account terdefinisi
// F.S. username terdefinisi
//      username merupakan username dari account

boolean isOnline(Account *account);
// I.S. account terdefinisi
// F.S. mengembalikan true jika account sedang online
//      mengembalikan false jika account sedang offline

void CreateAccount(Account *account, Word username, Word password);
// I.S. username dan password terdefinisi
// F.S. account terisi
//      account merupakan akun yang terdaftar

void signup(AccountList *listakun);
// I.S. listakun terdefinisi
// F.S. listakun terisi
//      listakun merupakan list akun yang terdaftar

void signin(AccountList *list, Account *akunLogin);
// I.S. list terdefinisi
// F.S. akunLogin terisi
//      akunLogin merupakan akun yang sedang login

void fillAccount(AccountList *listakun);
// I.S. listakun terdefinisi
// F.S. listakun terisi
//      listakun merupakan list akun yang terdaftar

boolean isEmptyAccountList(AccountList *list);

void CreateAccountEmpty(Account *account);

void CreateAccountList(AccountList *list);

void AddAccountToList(AccountList *list, Account account);

void DisplayAccounts(AccountList *list);

boolean IsAccountListFull(AccountList *list);

boolean WordEqualAccount(Word a, Word b);

boolean IsEqualUsername(Word *word1, Word *word2);

boolean IsUsernameInAccountList(AccountList *list, Word username);

boolean cekPassword(AccountList *list, Word username, Word password);



void PrintPrioQueue (prioqueuefren Q, AccountList * listakun);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    | "nama user 1"
    | Jumlah teman: "sum"
...
    | "nama user n"
    | Jumlah teman: "sum"
#
*/

void PrintTopPrioQueueChar (prioqueuefren Q, int IDuser, AccountList * listakun, int * idteman);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
    | "nama user teratas"
    | Jumlah teman: "sum terbesar"

*/

void colorizedProfil(MatrixChar mc);



#endif
