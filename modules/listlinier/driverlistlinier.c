#include <stdio.h>
#include "listlinier.h"

int main() {
    List l1, l2, l3;
    CreateList(&l1);
    CreateList(&l2);

    // Mengisi List 1
    insertLast(&l1, 1);
    insertLast(&l1, 2);
    insertLast(&l1, 3);

    // Mengisi List 2
    insertLast(&l2, 4);
    insertLast(&l2, 5);
    insertLast(&l2, 6);

    // Menampilkan isi List 1
    printf("List 1: ");
    displayList(l1);
    printf("\n");

    // Menampilkan isi List 2
    printf("List 2: ");
    displayList(l2);
    printf("\n");

    // Menampilkan panjang List 1 dan List 2
    printf("Panjang List 1: %d\n", length(l1));
    printf("Panjang List 2: %d\n", length(l2));

    // Menggabungkan List 1 dan List 2
    l3 = concat(l1, l2);

    // Menampilkan isi List 3 (hasil penggabungan)
    printf("List 3 (Hasil Penggabungan List 1 dan List 2): ");
    displayList(l3);
    printf("\n");

    // Menampilkan panjang List 3 (hasil penggabungan)
    printf("Panjang List 3: %d\n", length(l3));

    // Dealokasi memori
    return 0;
}
