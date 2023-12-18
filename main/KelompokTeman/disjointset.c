#include "disjointset.h"

/**** Konstruktor ****/
DisjointSet makeDisjointSet(int length)
/* Membuat dan menginisialisasi himpunan disjoint dengan panjang tertentu.
    I.S.: length - panjang himpunan disjoint yang ingin dibuat.
    F.S.: DisjointSet yang telah diinisialisasi.
*/
{
    DisjointSet s;
    CreateListGraf(&s);
    return s;
}

/**** Concatenation ****/
void UnionDisjointSet(DisjointSet *s, Graf g, int i, int j)
/* Menggabungkan dua himpunan disjoint.
    I.S.: s - DisjointSet yang ingin digabungkan.
          i - indeks elemen pertama yang ingin digabungkan.
          j - indeks elemen kedua yang ingin digabungkan.
    F.S.: s - DisjointSet yang telah digabungkan.
*/
{
    ListGraf l1, l2;
    CreateListGraf(&l1);
    CreateListGraf(&l2);
    getOne(g, i, &l1);
    getOne(g, j, &l2);
    int k;
    for(k = 0 ; k < CAPACITYGRAF; k++){
        if(ELMTLISTGRAF(l1, i) == 1 || ELMTLISTGRAF(l2,i) == 1){
            ELMTLISTGRAF(*s, i) = 1;
        }
    }
}

boolean similar(DisjointSet s1, DisjointSet s2){
/* Mengecek apakah dua himpunan disjoint memiliki elemen yang sama.
    I.S.: s1 - DisjointSet pertama yang ingin dicek.
          s2 - DisjointSet kedua yang ingin dicek.
    F.S.: true jika kedua DisjointSet memiliki elemen yang sama, false jika tidak.
*/
    boolean found = true;
    int i;
    for(i = 0 ; i < CAPACITYGRAF; i++){
        if(ELMTLISTGRAF(s1, i) != ELMTLISTGRAF(s2,i)){
            found = false;
        }
    }
    return found;
}

void findGroups(Graf m, int idUser, DisjointSet *s)
/* Mencari himpunan-himpunan disjoint dari suatu matriks graf.
    I.S.: m - matriks graf yang ingin dicari himpunan-himpunan disjointnya.
    F.S.: DisjointSet yang berisi himpunan-himpunan disjoint dari matriks graf.
*/
{
    CreateListGraf(s);
    getOne(m, idUser, s);
    boolean cek = false;
    while(!cek){
        DisjointSet tempinitial = *s;
        int i;
        for (i = 0; i < CAPACITYGRAF; i++){
            if (ELMTLISTGRAF(*s, i) == 1){
                UnionDisjointSet(s, m, idUser, i);
            }
        }
        DisjointSet tempfinal = *s;
        cek = similar(tempinitial, tempfinal);
    }
}