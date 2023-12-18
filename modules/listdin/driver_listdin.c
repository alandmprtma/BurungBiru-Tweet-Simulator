#include <stdio.h>
#include "listdin.h"

int main() {
    /* KAMUS */
    int NMax, NExtra;
    ListDin l1, l2, sortedL1, sortedL2;
    ElType maxL1, minL1, maxL2, minL2, temp;
    IdxType i;

    /* ALGORITMA */
    printf("Masukkan jumlah maksimal elemen ListDin: ");
    scanf("%d", &NMax);

    CreateListDin(&l1, NMax);
    CreateListDin(&l2, NMax);

    printf("Masukkan ListDin pertama:\n");
    readListDin(&l1);

    printf("\n");
    printf("ListDin pertama: ");printListDin(l1);printf("\n");

    if (!isEmptyDin(l1)){
        extremeValuesDin(l1, &maxL1, &minL1);
        printf("Range ListDin pertama: (%d - %d)\n", minL1, maxL1);
        printf("Jumlah semua elemen pada ListDin pertama: %d\n", sumListDin(l1));
        printf("Frequency table ListDin pertama: \n");
        for (i = 0; i <= getLastIdxDin(l1); i++) {
            if (i == indexOfDin(l1, ELMT(l1, i))) {
                printf("%d : %d\n", ELMT(l1, i), countValDin(l1, ELMT(l1, i)));
            }
        }
        if (isEmptyDin(l1)) {
            printf("ListDin pertama kosong!\n");
        }
        if (isFullDin(l1)) {
            printf("ListDin pertama penuh!\n");
        }
        copyListDin(l1, &sortedL1);
        sortDin(&sortedL1, true);
        printf("ListDin pertama sorted: ");printList(sortedL1);printf("\n");
    } else {
        printf("ListDin pertama kosong!\n");
    }
    printf("\n");

    compressListDin(&l1);

    printf("Masukkan ListDin kedua:\n");
    readListDin(&l2);

    printf("\n");
    printf("ListDin kedua: ");printListDin(l2);printf("\n");

    if (!isEmpty(l2)){
        extremeValuesDin(l2, &maxL2, &minL2);
        printf("Range ListDin kedua: (%d - %d)\n", minL2, maxL2);
        printf("Jumlah semua elemen pada ListDin kedua: %d\n", sumListDin(l2));
        printf("Frequency table ListDin kedua: \n");
        for (i = 0; i <= getLastIdxDin(l2); i++) {
            if (i == indexOfDin(l2, ELMT(l2, i))) {
                printf("%d : %d\n", ELMT(l2, i), countValDin(l2, ELMT(l2, i)));
            }
        }
        if (isEmptyDin(l2)) {
            printf("ListDin kedua kosong!\n");
        }
        if (isFullDin(l2)) {
            printf("ListDin kedua penuh!\n");
        }
        copyListDin(l2, &sortedL2);
        sortDin(&sortedL2, true);
        printf("ListDin kedua sorted: ");printListDin(sortedL2);printf("\n");
    } else {
        printf("ListDin kedua kosong!\n");
    }
    printf("\n");
    
    compressListDin(&l2);

    if (listLengthDin(l1) == listLengthDin(l2)) {
        printf("ListDin pertama + ListDin kedua = ");printList(plusMinusListDin(l1, l2, true));printf("\n");
        printf("ListDin pertama - ListDin kedua = ");printList(plusMinusListDin(l1, l2, false));printf("\n");
    }
    if (isListEqualDin(l1, l2)) {
        printf("ListDin pertama = ListDin kedua\n");
    }

    expandListDin(&l1, listLengthDin(l2));

    NExtra = listLengthDin(l2);

    for (i = 0; i < NExtra; i++) {
        deleteLastDin(&l2, &temp);
        insertLastDin(&l1, temp);
    }

    sortDin(&l1, true);

    printf("Concat kedua ListDin secara terurut: ");printListDin(l1);printf("\n");

    dealocateList(&l1);
    dealocateList(&l2);
}