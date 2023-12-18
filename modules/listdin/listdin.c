#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
{
      BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
      CAPACITYDIN(*l) = capacity;
      NEFF(*l) = 0;
}

void dealocateList(ListDin *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
      free(BUFFER(*l));
      CAPACITYDIN(*l) = 0;
      NEFF(*l) = 0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLengthDin(ListDin l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
      return NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdxDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
{
      return IDX_MIN;
}

IdxType getLastIdxDin(ListDin l)
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
{
      return (IdxType) listLengthDin(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidDin(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
{
      return (i >= 0 && i < (IdxType) CAPACITYDIN(l));
}

boolean isIdxEffDin(ListDin l, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
{
      return ((i >= IDX_MIN) && (i <= getLastIdxDin(l)));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyDin(ListDin l)
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
{
      return (NEFF(l) == 0);
}

/* *** Test list penuh *** */
boolean isFullDin(ListDin l)
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
{
      return (NEFF(l) == CAPACITYDIN(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDin(ListDin *l)
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
{
      int i, N;

      scanf("%d", &N);
      while (N<0 || N>CAPACITYDIN(*l))
      {
            scanf("%d", &N);
      }
      for (i = 0; i < (IdxType) N; i++) 
      {
            scanf("%d", &ELMTDIN(*l, i));
      }
      NEFF(*l) = N;
}

void printListDin(ListDin l)
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
{
      printf("[");
      for (int i = 0; i <=listLengthDin(l)-1; i++) {
            if (i==listLengthDin(l)-1) {
                  printf("%d", ELMTDIN(l,i));
            } else {
                  printf("%d,", ELMTDIN(l,i));
            }
      } 
      printf("]");
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus)
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
{
      ListDin lnew;
      CreateListDin(&lnew,CAPACITYDIN(l1));
      NEFF(lnew) = NEFF(l1);
      int i;
      if (plus) {
            for (i=0;i<=listLengthDin(l1)-1;i++) {
                  ELMTDIN(lnew,i) = ELMTDIN(l1,i) + ELMTDIN(l2,i);
            }
      } else {
            for (i=0;i<=listLengthDin(l1)-1;i++) {
                  ELMTDIN(lnew,i) = ELMTDIN(l1,i) - ELMTDIN(l2,i);
            }
      }
      return lnew;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualDin(ListDin l1, ListDin l2)
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
{
    if (NEFF(l1) == NEFF(l2)) {
        for (int i = 0; i < NEFF(l1); i++) {
           if (ELMTDIN(l1, i) != ELMTDIN(l2, i)) {
             return 0;
           } 
        } return 1;
    } return 0;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOfDin(ListDin l, ElType val)
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
{
      for (int i=0;i<=listLengthDin(l)-1;i++) 
      {
            if (ELMTDIN(l,i) == val) 
            {
                  return i;
            }
      }
      return IDX_UNDEF;
}

/* ********** NILAI EKSTREM ********** */
void extremeValuesDin(ListDin l, ElType *max, ElType *min)
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
{
    *max = -420, *min = 4200;

    for (int i = 0;i <=listLengthDin(l)-1;i++) {
        if (ELMTDIN(l,i) > *max) {
            *max = ELMTDIN(l,i);
        }
        if (ELMTDIN(l,i) < *min) {
            *min = ELMTDIN(l,i);
        }
    }
}

/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
{
      CreateListDin(lOut, CAPACITYDIN(lIn));
      NEFF(*lOut) = NEFF(lIn);
      for (int i = IDX_MIN; i <= listLengthDin(lIn)-1;i++)
      {
            ELMTDIN(*lOut,i) = ELMTDIN(lIn,i);
      }    
} 

ElType sumListDin(ListDin l)
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
{
      if (isEmptyDin(l))
      {
            return (ElType) 0;
      }
      else
      {
            ElType sum = 0;
            for (int i = IDX_MIN; i <= listLengthDin(l)-1; i++)
            {
                  sum = sum + ELMTDIN(l,i);
            }
            return sum;
      }
}

int countValDin(ListDin l, ElType val)
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
{
      if (isEmptyDin(l))
      {
            return 0;
      }
      else
      {
            int sum = 0;
            for (int i = IDX_MIN; i <= listLengthDin(l)-1; i++)
            {
                  if (ELMTDIN(l,i) == val)
                  {
                        sum++;
                  }
            }
            return sum;
      }
}

/* ********** SORTING ********** */
void sortDin(ListDin *l, boolean asc)
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
{
    int temp;
    int a = listLengthDin(*l)-1;
    if (asc) {
        while (a>=1) {
        for (int i=0; i<a;i++) {
            if (ELMTDIN(*l,i) > ELMTDIN(*l,i+1)) {
                temp = ELMTDIN(*l,i); 
                ELMTDIN(*l,i) = ELMTDIN(*l,i+1);
                ELMTDIN(*l,i+1) = temp;
            }
        }
        a-=1;
        }
    } else  {
        while (a>=0) {for (int i=0; i<a;i++) {
            if (ELMTDIN(*l,i) < ELMTDIN(*l,i+1)) {
                temp = ELMTDIN(*l,i); 
                ELMTDIN(*l,i) = ELMTDIN(*l,i+1);
                ELMTDIN(*l,i+1) = temp;
            }
    }
        a-=1;}
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastDin(ListDin *l, ElType val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
{
      ELMTDIN(*l, NEFF(*l)) = val;
      NEFF(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastDin(ListDin *l, ElType *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
      *val = ELMTDIN(*l,NEFF(*l)-1);
      NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDin(ListDin *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
      int prevCapacity, prevNeff;
      IdxType i;
      ListDin temp;

      copyListDin(*l, &temp);
      prevCapacity = CAPACITYDIN(*l);
      prevNeff = NEFF(*l);

      dealocateList(l);

      CreateListDin(l, prevCapacity + num);
      NEFF(*l) = prevNeff;
      for (i = 0; i <= getLastIdxDin(*l); i++) 
      {
            ELMTDIN(*l, i) = ELMTDIN(temp, i);
      }
}

void shrinkListDin(ListDin *l, int num)
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
{
      int prevCapacity, prevNeff;
      IdxType i;
      ListDin temp;

      copyListDin(*l, &temp);
      prevCapacity = CAPACITYDIN(*l);
      prevNeff = NEFF(*l);

      dealocateList(l);

      CreateListDin(l, prevCapacity - num);
      NEFF(*l) = prevNeff;

      for (i = 0; i <= getLastIdxDin(*l); i++) 
      {
            ELMTDIN(*l, i) = ELMTDIN(temp, i);
      }
}

void compressListDin(ListDin *l)
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
{
      int prevNeff;
      IdxType i;
      ListDin temp;

      copyListDin(*l, &temp);
      prevNeff = NEFF(*l);

      dealocateList(l);

      CreateListDin(l, prevNeff);
      NEFF(*l) = prevNeff;

      for (i = 0; i <= getLastIdxDin(*l); i++)
      {
            ELMTDIN(*l, i) = ELMTDIN(temp, i);
      }
}