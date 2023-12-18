/* ********** Definisi Graf dengan representasi matriks adjency ********** */

#ifndef GRAF_H
#define GRAF_H

#include "../boolean.h"

/*Ukuran Maksimum sesuai jumlah user*/
#define ROW_GRAF 20
#define COL_GRAF 20
#define MARKGRAF 0

#define CAPACITYGRAF 20
#define MARKLISTGRAF -9999

typedef int IdxGraf; /* Index baris, kolom */
typedef int ElGraf;
typedef int EllistGraf;
typedef int IdxlistGraf;

typedef struct
{
   ElGraf mem[ROW_GRAF][COL_GRAF];
} Graf;

typedef struct {
   EllistGraf content[CAPACITYGRAF]; /* memori tempat penyimpan elemen (container) */
} ListGraf;


#define ELMTLISTGRAF(l, i) (l).content[(i)]
#define ELMTGRAF(G, i, j) (G).mem[(i)][(j)]

void createEmptyGraf(Graf *g);
/*mengisi nilai dari tiap Graf dengan MARKGRAF*/

void CreateListGraf(ListGraf *l);
/*mengisi nilai dari tiap Graf dengan MARKLISTGRAF*/

int listEffGraf(ListGraf l);
/*Kalau bukan MARK tambah 1*/

boolean isEmptylistGraf(ListGraf l);
/*listEffGraf == 0*/

void getOne(Graf g, IdxGraf rowID, ListGraf *l);
/*Mengisi list dengan 1 jika ada hubungan*/

void displayGraf(Graf g, int count);
/*Menampilkan graf*/

void printListGraf(ListGraf l);
/*Menampilkan list*/

#endif