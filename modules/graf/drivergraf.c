#include "graf.h"
#include <stdio.h>

int main() {
    // Menguji konstruktor
    Graf myGraf;
    createEmptyGraf(&myGraf);

    // Membuat listgraf
    ListGraf myList;
    CreateListGraf(&myList);

    // Inisialisasi Graf dalam driver
    ELMTGRAF(myGraf, 0, 1) = 1;
    ELMTGRAF(myGraf, 1, 2) = 1;
    ELMTGRAF(myGraf, 2, 3) = 1;

    // Menampilkan Graf
    printf("Graf:\n");
    displayGraf(myGraf, 4);

    // Mengisi list dengan 1 jika ada hubungan
    IdxlistGraf rowIndex = 1;
    getOne(myGraf, rowIndex, &myList);

    // Display list dari graf
    printf("\nList untuk Row %d:\n", rowIndex);
    int i;
    for (i = 0; i < listEffGraf(myList); i++) {
        printf("%d ", ELMTLISTGRAF(myList, i));
    }
    printf("\n");

    return 0;
}