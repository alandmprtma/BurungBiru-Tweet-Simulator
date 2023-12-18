#ifndef PermintaanPertemanan_H
#define PermintaanPertemanan_H

#include "../../modules/adt.h"

void tambahteman(boolean login, Account akunlogin, AccountList* listakun, Graf Teman, prioqueuefren* Q);
/* Menambahkan teman baru ke dalam list teman 
    I.S. : login terdefinisi, akunlogin terdefinisi, listakun terdefinisi, Teman terdefinisi, Q terdefinisi
    F.S. : ditambahkan teman baru ke dalam list teman 
*/

void daftarpermintaanteman(boolean login, Account akunlogin, AccountList* listakun, prioqueuefren *Q);
/* Menampilkan daftar permintaan pertemanan yang belum disetujui
    I.S. : login terdefinisi, akunlogin terdefinisi, listakun terdefinisi, Q terdefinisi
    F.S. : ditampilkan daftar permintaan pertemanan yang belum disetujui
*/

void setujuipermintaanteman(boolean login, Account akunlogin, AccountList* listakun, Graf* Teman, prioqueuefren* Q);
/* Menyetujui permintaan pertemanan
    I.S. : login terdefinisi, akunlogin terdefinisi, listakun terdefinisi, Teman terdefinisi, Q terdefinisi
    F.S. : permintaan pertemanan disetujui
*/


#endif