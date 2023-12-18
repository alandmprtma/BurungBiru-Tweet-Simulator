#include <stdio.h>
#include "datetime.h"

int main() {
    DATETIME dt1, dt2;
    int durasi;

    // Create a DATETIME instance
    CreateDATETIME(&dt1, 15, 11, 2023, 10, 30, 0);
    printf("Created DATETIME: ");
    TulisDATETIME(dt1);
    printf("\n");

    // Read a DATETIME from input
    printf("Enter a DATETIME (DD MM YYYY hh mm ss): ");
    BacaDATETIME(&dt2);
    printf("You entered: ");
    TulisDATETIME(dt2);
    printf("\n");

    // Compare two DATETIMEs
    if (DEQ(dt1, dt2)) {
        printf("The two DATETIMEs are equal.\n");
    } else {
        printf("The two DATETIMEs are not equal.\n");
    }

    // Add seconds to a DATETIME
    DATETIME dt1_plus_30s = DATETIMENextNDetik(dt1, 30);
    printf("DATETIME after adding 30 seconds: ");
    TulisDATETIME(dt1_plus_30s);
    printf("\n");

    // Subtract seconds from a DATETIME
    DATETIME dt2_minus_60s = DATETIMEPrevNDetik(dt2, 60);
    printf("DATETIME after subtracting 60 seconds: ");
    TulisDATETIME(dt2_minus_60s);
    printf("\n");

    // Calculate duration between two DATETIMEs
    durasi = DATETIMEDurasi(dt1, dt2);
    printf("Duration between the two DATETIMEs in seconds: %d\n", durasi);

    return 0;
}
