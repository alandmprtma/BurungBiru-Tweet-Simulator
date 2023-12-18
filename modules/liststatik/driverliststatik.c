#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l1, l2, hasil;
    ElType max, min, val;
    int idx;

    // Tes CreateListStatik
    CreateListStatik(&l1);
    printf("List l1 setelah CreateListStatik: ");
    printListStatik(l1);
    printf("\n");

    // Tes readListStatik
    printf("Masukkan elemen-elemen untuk List l1: ");
    readListStatik(&l1);
    printf("List l1 setelah readListStatik: ");
    printListStatik(l1);
    printf("\n");

    // Tes listLengthStatik
    printf("Banyaknya elemen dalam List l1: %d\n", listLengthStatik(l1));

    // Tes getFirstIdxStatik dan getLastIdxStatik
    printf("Indeks pertama List l1: %d\n", getFirstIdxStatik(l1));
    printf("Indeks terakhir List l1: %d\n", getLastIdxStatik(l1));

    // Tes isIdxValidStatik dan isIdxEffStatik
    idx = 2;
    printf("Apakah indeks %d valid untuk List l1? %s\n", idx, isIdxValidStatik(l1, idx) ? "true" : "false");
    printf("Apakah indeks %d efektif untuk List l1? %s\n", idx, isIdxEffStatik(l1, idx) ? "true" : "false");

    // Tes isEmptyStatik dan isFullStatik
    printf("Apakah List l1 kosong? %s\n", isEmptyStatik(l1) ? "true" : "false");
    printf("Apakah List l1 penuh? %s\n", isFullStatik(l1) ? "true" : "false");

    // Tes printListStatik
    printf("List l1: ");
    printListStatik(l1);
    printf("\n");

    // Tes plusMinusListStatik
    printf("Masukkan elemen-elemen untuk List l2: ");
    readListStatik(&l2);
    printf("List l2: ");
    printListStatik(l2);
    printf("\n");

    hasil = plusMinusListStatik(l1, l2, 1);
    printf("Hasil penjumlahan List l1 dan l2: ");
    printListStatik(hasil);
    printf("\n");

    hasil = plusMinusListStatik(l1, l2, 0);
    printf("Hasil pengurangan List l1 dan l2: ");
    printListStatik(hasil);
    printf("\n");

    // Tes isListEqualStatik
    printf("Apakah List l1 sama dengan List l2? %s\n", isListEqualStatik(l1, l2) ? "true" : "false");

    // Tes indexOfStatik
    printf("Masukkan nilai yang akan dicari di List l1: ");
    scanf("%d", &val);
    idx = indexOfStatik(l1, val);
    if (idx != IDX_UNDEF) {
        printf("Nilai %d ditemukan pada indeks %d di List l1\n", val, idx);
    } else {
        printf("Nilai %d tidak ditemukan di List l1\n", val);
    }

    // Tes extremeValuesStatik
    extremeValuesStatik(l1, &max, &min);
    printf("Nilai terbesar di List l1: %d\n", max);
    printf("Nilai terkecil di List l1: %d\n", min);

    // Test insertFirstStatik
    printf("Masukkan nilai yang akan ditambahkan di awal List l1: ");
    scanf("%d", &val);
    insertFirstStatik(&l1, val);
    printf("List l1 setelah ditambahkan di awal: ");
    printListStatik(l1);
    printf("\n");

    // Test insertAtStatik
    printf("Masukkan nilai yang akan ditambahkan: ");
    scanf("%d", &val);
    printf("Masukkan indeks tempat penyisipan: ");
    scanf("%d", &idx);
    insertAtStatik(&l1, val, idx);
    printf("List l1 setelah ditambahkan pada indeks %d: ", idx);
    printListStatik(l1);
    printf("\n");

    // Test insertLastStatik
    printf("Masukkan nilai yang akan ditambahkan di akhir List l1: ");
    scanf("%d", &val);
    insertLastStatik(&l1, val);
    printf("List l1 setelah ditambahkan di akhir: ");
    printListStatik(l1);
    printf("\n");

    // Test deleteFirstStatik
    deleteFirstStatik(&l1, &val);
    printf("Elemen pertama List l1 yang dihapus: %d\n", val);
    printf("List l1 setelah elemen pertama dihapus: ");
    printListStatik(l1);
    printf("\n");

    // Test deleteAtStatik
    printf("Masukkan indeks elemen yang akan dihapus: ");
    scanf("%d", &idx);
    deleteAtStatik(&l1, &val, idx);
    printf("Elemen pada indeks %d List l1 yang dihapus: %d\n", idx, val);
    printf("List l1 setelah elemen pada indeks %d dihapus: ", idx);
    printListStatik(l1);
    printf("\n");

    // Test deleteLastStatik
    deleteLastStatik(&l1, &val);
    printf("Elemen terakhir List l1 yang dihapus: %d\n", val);
    printf("List l1 setelah elemen terakhir dihapus: ");
    printListStatik(l1);
    printf("\n");

    // Test sortListStatik
    printf("Sortir List l1 secara ascending...\n");
    sortListStatik(&l1, 1);
    printf("List l1 setelah diurutkan: ");
    printListStatik(l1);
    printf("\n");

    printf("Sortir List l1 secara descending...\n");
    sortListStatik(&l1, 0);
    printf("List l1 setelah diurutkan: ");
    printListStatik(l1);
    printf("\n");

    return 0;
}
