#include "fyb.h"

void DisplayFYB(ListKicau list) {
    SortByLikes(&list);
    int displayCount = list.nEff < 8 ? list.nEff : 8;
    printf("Berikut %d kicauan dengan like tertinggi di FYB\n", displayCount);

    for (int i = 0; i < displayCount; i++) {
        printf("\nKicauan %d:\n", i + 1);
        BaseDisplay(list.kicau[i]);
    }
}

void SortByLikes(ListKicau *list) {
    if (list->nEff == 0) {
        printf("Tidak ada kicauan nih, yuk mulai berkicau!\n");
    }
    else{
        for (int i = 0; i < list->nEff - 1; i++) {
            for (int j = 0; j < list->nEff - i - 1; j++) {
                if (list->kicau[j].like < list->kicau[j + 1].like ||
                    (list->kicau[j].like == list->kicau[j + 1].like &&
                    CompareDateTime(list->kicau[j].datetime, list->kicau[j + 1].datetime) < 0)) {
                    Kicau temp = list->kicau[j];
                    list->kicau[j] = list->kicau[j + 1];
                    list->kicau[j + 1] = temp;
                }
            }
        }
    }
}