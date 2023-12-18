#ifndef Disjointset_H
#define Disjointset_H

#include "../../modules/adt.h"

typedef ListGraf DisjointSet;

/**** Konstruktor ****/
DisjointSet makeDisjointSet(int length);
/* Membuat dan menginisialisasi himpunan disjoint dengan panjang tertentu.
    I.S.: length - panjang himpunan disjoint yang ingin dibuat.
    F.S.: DisjointSet yang telah diinisialisasi.
*/

/**** Concatenation ****/
void UnionDisjointSet(DisjointSet *s, Graf g, int i, int j);
/* Menggabungkan dua himpunan disjoint.
    I.S.: s - DisjointSet yang ingin digabungkan.
          i - indeks elemen pertama yang ingin digabungkan.
          j - indeks elemen kedua yang ingin digabungkan.
    F.S.: s - DisjointSet yang telah digabungkan.
*/

boolean similar(DisjointSet s1, DisjointSet s2);
/* Mengecek apakah dua himpunan disjoint memiliki elemen yang sama.
    I.S.: s1 - DisjointSet pertama yang ingin dicek.
          s2 - DisjointSet kedua yang ingin dicek.
    F.S.: true jika kedua DisjointSet memiliki elemen yang sama, false jika tidak.
*/

void findGroups(Graf m, int idUser, DisjointSet *s);
/* Mencari himpunan-himpunan disjoint dari suatu matriks graf.
    I.S.: m - matriks graf yang ingin dicari himpunan-himpunan disjointnya.
    F.S.: DisjointSet yang berisi himpunan-himpunan disjoint dari matriks graf.
*/

#endif