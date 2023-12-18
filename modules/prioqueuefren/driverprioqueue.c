#include <stdio.h>
#include "prioqueuefren.h"

int main() {
    prioqueuefren Q, Quser, Qsisa;
    teman t;

    // Inisialisasi PrioQueueFren
    MakeEmptyprio(&Q, 5);
    MakeEmptyprio(&Quser, 5);
    MakeEmptyprio(&Qsisa, 5);

    // Menambahkan elemen ke dalam PrioQueueFren
    t.IDpenerima = 1;
    t.Jumlahteman = 5;
    Enqueueprio(&Q, t);

    t.IDpenerima = 2;
    t.Jumlahteman = 3;
    Enqueueprio(&Q, t);

    t.IDpenerima = 3;
    t.Jumlahteman = 7;
    Enqueueprio(&Q, t);

    t.IDpenerima = 4;
    t.Jumlahteman = 2;
    Enqueueprio(&Q, t);

    // Menampilkan elemen-elemen dalam PrioQueueFren
    printf("Isi PrioQueueFren:\n");
    while (!IsEmptyPrio(Q)) {
        Dequeueprio(&Q, &t);
        printf("ID Penerima: %d, Jumlah Teman: %d\n", t.IDpenerima, t.Jumlahteman);
    }

    // Menyimpan informasi permintaan teman yang dimiliki oleh suatu user
    Enqueueuserprio(Q, 2, &Quser, &Qsisa);

    // Menampilkan elemen-elemen dalam PrioQueueFren milik user
    printf("\nIsi PrioQueueFren User:\n");
    while (!IsEmptyPrio(Quser)) {
        Dequeueprio(&Quser, &t);
        printf("ID Penerima: %d, Jumlah Teman: %d\n", t.IDpenerima, t.Jumlahteman);
    }

    // Menampilkan elemen-elemen dalam PrioQueueFren sisanya
    printf("\nIsi PrioQueueFren Sisa:\n");
    while (!IsEmptyPrio(Qsisa)) {
        Dequeueprio(&Qsisa, &t);
        printf("ID Penerima: %d, Jumlah Teman: %d\n", t.IDpenerima, t.Jumlahteman);
    }

    // Menggabungkan dua PrioQueueFren
    concatenationprio(Quser, Qsisa, &Q);

    // Menampilkan elemen-elemen dalam PrioQueueFren setelah digabungkan
    printf("\nIsi PrioQueueFren Setelah Penggabungan:\n");
    while (!IsEmptyPrio(Q)) {
        Dequeueprio(&Q, &t);
        printf("ID Penerima: %d, Jumlah Teman: %d\n", t.IDpenerima, t.Jumlahteman);
    }

    // Dealokasi memori
    DeAlokasiprio(&Q);
    DeAlokasiprio(&Quser);
    DeAlokasiprio(&Qsisa);

    return 0;
}
