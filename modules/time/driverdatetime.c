#include <stdio.h>
#include "datetime.h"

int main() {
    DATETIME D1, D2;
    int DD, MM, YY, hh, mm, ss;

    // Test BacaDATETIME
    printf("Masukkan DATETIME (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&D1);
    printf("DATETIME yang dimasukkan: ");
    TulisDATETIME(D1);
    printf("\n");

    // Test TulisDATETIME
    printf("DATETIME yang dimasukkan dalam format string: ");
    TulisDATETIME(D1);
    printf("\n");

    // Test DEQ
    printf("Masukkan DATETIME kedua untuk membandingkan (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&D2);
    printf("DEQ (Equal): %s\n", DEQ(D1, D2) ? "true" : "false");

    // Test DNEQ
    printf("DNEQ (Not Equal): %s\n", DNEQ(D1, D2) ? "true" : "false");

    // Test DLT
    printf("DLT (Less Than): %s\n", DLT(D1, D2) ? "true" : "false");

    // Test DGT
    printf("DGT (Greater Than): %s\n", DGT(D1, D2) ? "true" : "false");

    // Test DATETIMENextNDetik
    int N;
    printf("Masukkan jumlah detik yang ingin ditambahkan: ");
    scanf("%d", &N);
    D1 = DATETIMENextNDetik(D1, N);
    printf("DATETIME setelah ditambahkan %d detik: ", N);
    TulisDATETIME(D1);
    printf("\n");

    // Test DATETIMEPrevNDetik
    printf("Masukkan jumlah detik yang ingin dikurangkan: ");
    scanf("%d", &N);
    D1 = DATETIMEPrevNDetik(D1, N);
    printf("DATETIME setelah dikurangkan %d detik: ", N);
    TulisDATETIME(D1);
    printf("\n");

    // Test DATETIMEDurasi
    DATETIME D3;
    printf("Masukkan DATETIME kedua untuk menghitung durasi (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&D3);
    long int durasi = DATETIMEDurasi(D2, D3);
    printf("Durasi antara kedua DATETIME dalam detik: %ld detik\n", durasi);

    return 0;
}
