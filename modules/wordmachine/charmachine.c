/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pita = stdin;
       ADV();
}

void STARTFILE(char filename[]) {
/*Mesin siap dioperasikan. Pita pada file disiapkan untuk dibaca mesin kata.*/
       pita = fopen(filename, "r");
       ADV();
}

void ADV()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retval = fscanf(pita, "%c", &currentChar);
       EOP = (currentChar == MARK);
       // if (EOP)
       // {
       //        fclose(pita);
       // }
}

void END()
/*Mesin dinonaktifkan dan Pita yang dibaca di dealokasi.*/
{
       fclose(pita);
}

boolean containsSpace(const char *str) {
    while (*str) {
       if (*str == ' ') {
              return true;  // Mengandung spasi
       }
       str++;
    }
    return false;  // Tidak mengandung spasi
}