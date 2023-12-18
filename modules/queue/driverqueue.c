#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    ElType val;
    int option;

    do {
        printf("Menu:\n");
        printf("1. Buat Antrian\n");
        printf("2. Masukkan Data\n");
        printf("3. Keluarkan Data\n");
        printf("4. Tampilkan Antrian\n");
        printf("0. Keluar\n");

        printf("Pilih opsi: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                CreateQueue(&q);
                printf("Antrian dibuat.\n");
                break;
            case 2:
                if (isFullQ(q)) {
                    printf("Antrian penuh. Tidak dapat memasukkan data lagi.\n");
                } else {
                    printf("Masukkan nilai untuk dimasukkan: ");
                    scanf("%d", &val);
                    enqueue(&q, val);
                    printf("%d dimasukkan ke dalam antrian.\n", val);
                }
                break;
            case 3:
                if (isEmptyQ(q)) {
                    printf("Antrian kosong. Tidak dapat mengeluarkan data.\n");
                } else {
                    dequeue(&q, &val);
                    printf("%d dikeluarkan dari antrian.\n", val);
                }
                break;
            case 4:
                printf("Isi Antrian: ");
                displayQueue(q);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Opsi tidak valid. Harap pilih lagi.\n");
                break;
        }

    } while (option != 0);

    return 0;
}