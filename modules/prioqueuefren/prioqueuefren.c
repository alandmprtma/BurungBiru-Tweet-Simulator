#include <stdio.h>
#include <stdlib.h>
#include "prioqueuefren.h"

boolean IsEmptyPrio (prioqueuefren Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return (HeadQ(Q) == Nil && TailQ(Q) == Nil);
}

boolean IsFullPrio (prioqueuefren Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (MaxElQ(Q) == NBElmtPrio(Q));
}

int NBElmtPrio (prioqueuefren Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
    if (IsEmptyPrio(Q)){
        return 0;
    }
    else {
        if ((TailQ(Q) - HeadQ(Q)) >= 0){
            return TailQ(Q) - HeadQ(Q) + 1;
        }
        else {
            return MaxElQ(Q) - (HeadQ(Q) - (TailQ(Q) + 1));
        }
    }

}

void MakeEmptyprio (prioqueuefren * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
    (*Q).T = (teman *) malloc((Max) * sizeof(teman));
    if ((*Q).T == NULL) {
        MaxElQ(*Q) = 0;
    }
    else {
        HeadQ(*Q) = Nil;
        TailQ(*Q) = Nil;
        MaxElQ(*Q) = Max;
    }
}

void DeAlokasiprio (prioqueuefren * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    HeadQ(*Q) = Nil;
    TailQ(*Q) = Nil;
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Enqueueprio (prioqueuefren * Q, teman t)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
{
    boolean found;
    int idx;
    int i, j;
    teman temp;

    // enqueue based on jumlah teman
    if (IsEmptyPrio(*Q)){
            HeadQ(*Q) = 0;
            TailQ(*Q) = 0;
            InfoHeadQ(*Q) = t;
    }
    else if (IsFullPrio(*Q)){
        printf("Queue is full\n");
    }
    else {
        TailQ(*Q) = TailQ(*Q) == MaxElQ(*Q) - 1 ? 0 : TailQ(*Q) + 1;
        InfoTailQ(*Q) = t;
        i = TailQ(*Q);
        j = (i == 0) ? MaxElQ(*Q) - 1 : i - 1;
        while (i != HeadQ(*Q) && ElmtQ(*Q, i).Jumlahteman > ElmtQ(*Q, j).Jumlahteman){
            temp = ElmtQ(*Q, i);
            ElmtQ(*Q, i) = ElmtQ(*Q, j);
            ElmtQ(*Q, j) = temp;
            i = j;
            j = (i == 0) ? MaxElQ(*Q) - 1 : i - 1;
        }
    }
}

void Dequeueprio (prioqueuefren * Q, teman * t)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    if (NBElmtPrio(*Q) == 1) {
        *t = InfoHeadQ(*Q);
        HeadQ(*Q) = Nil;
        TailQ(*Q) = Nil;
    }
    else {
        *t = InfoHeadQ(*Q);
        HeadQ(*Q) = (HeadQ(*Q) == MaxElQ(*Q) - 1) ? 0 : HeadQ(*Q) + 1;
    }   
}

void Enqueueuserprio(prioqueuefren *Q, int IDuser, prioqueuefren *Quser, prioqueuefren *Qsisa)
/*Menyimpan informasi permintaan teman yang dimiliki oleh suatu user atau pengguna
    Memisahkan Queue permintaan teman selain milik user dan yang dimiliki oleh user*/
{
    teman temp;
    MakeEmptyprio(Quser, 20);
    MakeEmptyprio(Qsisa, 100);
    while(!IsEmptyPrio(*Q))
    {
        Dequeueprio(Q, &temp);
        if(temp.IDpenerima == IDuser)
        {
            Enqueueprio(Quser,temp);
        }
        else{
            Enqueueprio(Qsisa, temp);
        }
    }    
}

void concatenationprio(prioqueuefren Quser, prioqueuefren Qsisa, prioqueuefren *Q)
/*Menggabungkan kedua Queue menjadi satu menggunakan Enqueue berdasarkan prioritas*/
{
    while (!IsEmptyPrio(Quser))
    {
        teman temp;
        Dequeueprio(&Quser, &temp);
        Enqueueprio(Q, temp);
    }
    while (!IsEmptyPrio(Qsisa))
    {
        teman temp;
        Dequeueprio(&Qsisa, &temp);
        Enqueueprio(Q, temp);
    }
}
