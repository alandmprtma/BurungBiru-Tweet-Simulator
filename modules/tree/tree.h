/* File : tree.h */
/* Definisi N-Ary Tree */

#ifndef TREEBALASAN_H
#define TREEBALASAN_H

#include <stdio.h>
#include <stdlib.h>

#include "../adt.h"

#define MAXCharBalas 281
#define IDX_UNDEF_KICAUAN -999

typedef struct {
   int id;
//    int idKicau;
   char text[MAXCharBalas];
   Word author;
   DATETIME datetime;
} Balasan;

/* Selektor */
#define ROOT_BALASAN(t) (t)->T
#define SUBADDRESS_BALASAN(t) (t)->SubTree
#define SUBTREE_BALASAN(t,n) (t)->SubTree[n]
#define TREECOUNT_BALASAN(t) (t)->Count
#define TREECAPACITY_BALASAN(t) (t)->Capacity

#define Nil_BALASAN NULL
#define INITIAL_BALASAN 5

typedef Balasan InfotypeBalasan;
typedef struct TNodeBalasan *AddressBalasan;
typedef struct TNodeBalasan
{
	InfotypeBalasan T;
	AddressBalasan *SubTree; // Tree* Subtree (array of pointers to Tree)
	int Count;
	int Capacity;
} NodeBalasan;

// Tree == Address == [0..n] of pointers to TNode

/* Definisi Pohon N-Ary */
/* pohon kosong t = Nil */

typedef AddressBalasan TreeBalasan;

AddressBalasan NewTreeNodeBalasan(InfotypeBalasan root);
/* Mengalokasikan sebuah Address t, bernilai Nil jika tidak berhasil */
/* Mengirimkan Address hasil alokasi sebuah elemen bernilai root
   Jika alokasi berhasil, maka Address tidak Nil dan menghasilkan t
   ROOT(t) = val, SUBADDRESS(t) terdefinisi dengan ukuran INITIAL,
   COUNT(t) = 0, dan TREECAPACITY(t) = INITIAL 
   Jika alokasi gagal, maka mengirimkan Nil */

TreeBalasan NewTreeBalasan(InfotypeBalasan root, TreeBalasan child);
/* Jika alokasi berhasil, menghasilkan sebuah pohon dari root dan child;
   dan count bertambah satu jika child bukan Nil */
/* Jika alokasi gagal, menghasilkan pohon kosong (Nil) */

void CreateTreeBalasan(InfotypeBalasan root, TreeBalasan child, TreeBalasan *t);
/* I.S. : Sembarang
   F.S. : Menghasilkan sebuah pohon t
   		  Jika alokasi berhasil, menghasilkan sebuah pohon dari root dan child;
   		  dan count bertambah satu jika child bukan Nil
   		  Jika alokasi gagal, menghasilkan pohon kosong (Nil) */

void ConnectChildBalasan(TreeBalasan child, TreeBalasan *t);
/* I.S. : t dan child terdefinisi
   F.S. : t terhubung dengan child dan count bertambah satu jika child bukan Nil */

void ConnectParentBalasan(TreeBalasan parent, TreeBalasan *t);
/* I.S. : t dan parent terdefinisi
   F.S. : t menjadi child dari parent, ROOT(t) menjadi ROOT(parent) */

void DeallocateTreeBalasan(AddressBalasan t);
/* I.S. : t terdefinisi
   F.S. : t dikembalikan ke sistem
   Melakukan dealokasi/pengembalian Address t */

boolean HasNoChildBalasan(TreeBalasan t);
/* Mengirimkan true jika t tidak memiliki child */

boolean HasOneChildBalasan(TreeBalasan t);
/* Mengirimkan true jika t hanya memiliki 1 child */

/***** Display Tree *****/
// void PrintTreeBalasan(TreeBalasan t);
/* I.S. : t terdefinisi
   F.S. : Semua simpul t sudah dicetak secara preorder: root dan child(ren)
   		  Setiap pohon ditandai dengan tanda kurung buka dan tanda kurung tutup ()
   		  Pohon kosong ditandai dengan () */

void ExpandCapacityBalasan(TreeBalasan *t);
/* Proses: Memperbesar dua kali lipat TREECAPACITY t */
/* I.S. : t terdefinisi */
/* F.S. : Ukuran SubTree menjadi dua kali lipat ukuran semula */

void insertTreeBalasan(TreeBalasan t, int parentID, InfotypeBalasan child);

void insertTreeRecursionBalasan(TreeBalasan t, int parentID, TreeBalasan child, boolean* f);

void deleteTreeBalasan(TreeBalasan* t, int parentID);

void deleteTreeRecursionBalasan(TreeBalasan* t, int parentID, boolean* f);

boolean treeExists(TreeBalasan t, int parentID);

void searchTreeRecursion(TreeBalasan t, int parentID, boolean *f);

#endif