#include <stdio.h>
#include "liststatik.h"

/*
NIM     : 13522124
Nama    : Aland Mulia Pratama
Topik   : PraPraktikum ADT List
Tanggal : 6 September 2023
*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */
{
    for (int i = IDX_MIN; i <= CAPACITY-1; i++) {
        ELMTSTAT(*l, i) = MARKSTAT;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthStatik(ListStatik l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  
{
    int jumlah = 0;
    for (int i = IDX_MIN; i <= CAPACITY-1;i++) {
        if (ELMTSTAT(l, i) != MARKSTAT) {
            jumlah++;
        }
    }
    return jumlah;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxStatik(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
    return IDX_MIN;
}
IdxType getLastIdxStatik(ListStatik l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
    return(listLengthStatik(l)-1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidStatik(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return(i < CAPACITY && i >= IDX_MIN);
}
boolean isIdxEffStatik(ListStatik l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */
{
    return(i >= IDX_MIN && listLengthStatik(l) > i);
}
/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyStatik(ListStatik l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
    return(listLengthStatik(l) == IDX_MIN);
}
boolean isFullStatik(ListStatik l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
    return(listLengthStatik(l) == CAPACITY);
}
/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStatik(ListStatik *l)
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
{
    int n;
    CreateListStatik(l);
    scanf("%d", &n);
    while ((n < IDX_MIN || n > CAPACITY )) {
        scanf("%d", &n);
    }
    if (n!=0){
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        ELMTSTAT(*l, i) = x;
    }
    }   
}
void printListStatik(ListStatik l)
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
{
    printf("[");
    for (int i = 0; i <=listLengthStatik(l)-1; i++) {
        if (i==listLengthStatik(l)-1) {
            printf("%d", ELMTSTAT(l,i));
        } else {
            printf("%d,", ELMTSTAT(l,i));
        }
    } 
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusListStatik(ListStatik l1, ListStatik l2, boolean plus)
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */
{
    ListStatik lnew;
    CreateListStatik(&lnew);
    int i;
    if (plus) {
        for (i=0;i<=listLengthStatik(l1)-1;i++) {
            ELMTSTAT(lnew,i) = ELMTSTAT(l1,i) + ELMTSTAT(l2,i);
        }
    } else {
        for (i=0;i<=listLengthStatik(l1)-1;i++) {
            ELMTSTAT(lnew,i) = ELMTSTAT(l1,i) - ELMTSTAT(l2,i);
        }
    }
    return lnew;
}
/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqualStatik(ListStatik l1, ListStatik l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */
{
    if (listLengthStatik(l1) == listLengthStatik(l2)) {
        for (int i = IDX_MIN; i <= listLengthStatik(l1)-1;i++) {
            if (ELMTSTAT(l1,i)!=ELMTSTAT(l2,i)) {
                return 0;
            } else if (i == listLengthStatik(l1)-1) {
                return 1;
            }
        }
    } else {
        return 0;
    }
}
/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfStatik(ListStatik l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
{
    for (int i=0;i<=listLengthStatik(l)-1;i++) {
        if (ELMTSTAT(l,i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}
/* ********** NILAI EKSTREM ********** */
void extremeValuesStatik(ListStatik l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */
{
    *max = -420, *min = 4200;

    for (int i = 0;i <=listLengthStatik(l)-1;i++) {
        if (ELMTSTAT(l,i) > *max) {
            *max = ELMTSTAT(l,i);
        }
        if (ELMTSTAT(l,i) < *min) {
            *min = ELMTSTAT(l,i);
        }
    }
}
/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstStatik(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
{
    int temp1 = ELMTSTAT(*l,0);
    for (int i = 0; i <= listLengthStatik(*l)-1;i++) {
        int temp = ELMTSTAT(*l,i+1);
        ELMTSTAT(*l,i+1) = temp1 ;
        temp1 = temp;
    }
    ELMTSTAT(*l,0) = val;
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtStatik(ListStatik *l, ElType val, IdxType idx)
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
{
    int temp1 = ELMTSTAT(*l, idx);
    for (int i = idx; i <= listLengthStatik(*l)-1;i++) {
        int temp = ELMTSTAT(*l,i+1);
        ELMTSTAT(*l,i+1) = temp1 ;
        temp1 = temp;
    }
    ELMTSTAT(*l,idx) = val;

}
/* *** Menambahkan elemen terakhir *** */
void insertLastStatik(ListStatik *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
    ELMTSTAT(*l, listLengthStatik(*l)) = val;
}
/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstStatik(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMTSTAT(*l,0);
    int temp1 = ELMTSTAT(*l,1);
    for (int i = 1;i <=listLengthStatik(*l)-1;i++) {
        int temp = ELMTSTAT(*l,i+1);
        ELMTSTAT(*l,i-1) = temp1 ;
        temp1 = temp;
    }
    ELMTSTAT(*l,listLengthStatik(*l)-1) = MARKSTAT;
}
/* *** Menghapus elemen pada index tertentu *** */

void deleteAtStatik(ListStatik *l, ElType *val, IdxType idx)
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
{
    *val = ELMTSTAT(*l,idx);
    int temp1 = ELMTSTAT(*l,idx+1);
    for (int i = idx+1;i <=listLengthStatik(*l)-1;i++) {
        int temp = ELMTSTAT(*l,i+1);
        ELMTSTAT(*l,i-1) = temp1 ;
        temp1 = temp;
    }
    
    ELMTSTAT(*l,listLengthStatik(*l)-1) = MARKSTAT;
}
void deleteLastStatik(ListStatik *l, ElType *val)
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMTSTAT(*l,listLengthStatik(*l)-1);
    ELMTSTAT(*l,listLengthStatik(*l)-1) = MARKSTAT;
}
/* ********** SORTING ********** */
void sortListStatik(ListStatik *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int temp;
    int a = listLengthStatik(*l)-1;
    if (asc) {
        while (a>=1) {
        for (int i=0; i<a;i++) {
            if (ELMTSTAT(*l,i) > ELMTSTAT(*l,i+1)) {
                temp = ELMTSTAT(*l,i); 
                ELMTSTAT(*l,i) = ELMTSTAT(*l,i+1);
                ELMTSTAT(*l,i+1) = temp;
            }
        }
        a-=1;
        }
    } else  {
        while (a>=0) {for (int i=0; i<a;i++) {
            if (ELMTSTAT(*l,i) < ELMTSTAT(*l,i+1)) {
                temp = ELMTSTAT(*l,i); 
                ELMTSTAT(*l,i) = ELMTSTAT(*l,i+1);
                ELMTSTAT(*l,i+1) = temp;
            }
    }
        a-=1;}
    }
}