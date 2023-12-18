#ifndef Teman_H
#define Teman_H

#include "../../modules/adt.h"


void daftarteman(boolean login, Account akunlogin, AccountList* listakun, Graf teman);
/* Menampilkan daftar teman
    I.S. : login terdefinisi, akunlogin terdefinisi, listakun terdefinisi, teman terdefinisi
    F.S. : ditampilkan daftar teman
*/

void hapusteman(boolean login, Account akunlogin, AccountList* listakun, Graf* teman);
/* Menghapus teman
    I.S. : login terdefinisi, akunlogin terdefinisi, listakun terdefinisi, teman terdefinisi
    F.S. : teman dihapus
*/

#endif