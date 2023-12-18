/* File : queue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */

#ifndef PRIOQUEUEFREN_H
#define PRIOQUEUEFREN_H

#include "../boolean.h"

#define Nil -1

typedef struct
{
    /* data */
    int IDpengirim;
    int IDpenerima;
    int Jumlahteman;
}teman;

typedef int addressPrioqueue; /*indeks tabel*/

typedef struct {
    teman *T;
    addressPrioqueue HEADQ;
    addressPrioqueue TAILQ;
    int MaxElQ;
}prioqueuefren;
/* Definisi PrioQueueFren kosong: HEAD=Nil; TAIL=Nil. */


/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueChar, maka akses elemen : */
#define HeadQ(Q)     (Q).HEADQ
#define TailQ(Q)     (Q).TAILQ
#define InfoHeadQ(Q) (Q).T[(Q).HEADQ]
#define InfoTailQ(Q) (Q).T[(Q).TAILQ]
#define MaxElQ(Q)    (Q).MaxElQ
#define ElmtQ(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyPrio (prioqueuefren Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */


boolean IsFullPrio (prioqueuefren Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBElmtPrio (prioqueuefren Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyprio (prioqueuefren * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiprio (prioqueuefren * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueueprio (prioqueuefren * Q, teman t);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */

void Dequeueprio (prioqueuefren * Q, teman * t);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void Enqueueuserprio(prioqueuefren*Q, int IDuser,prioqueuefren * Quser, prioqueuefren *Qsisa);
/*Menyimpan informasi permintaan teman yang dimiliki oleh suatu user atau pengguna*/

void concatenationprio(prioqueuefren Quser, prioqueuefren Qsisa, prioqueuefren *Q);
/*Menggabungkan kedua Queue menjadi satu menggunakan Enqueue berdasarkan prioritas*/

#endif