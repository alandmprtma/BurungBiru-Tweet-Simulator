#include "balasan.h"
#include "../Kicauan/Kicauan.h"

// int hitungkicauDenganBalasan(ListKicau *klist, Kicau *k) {
//     int n = klist->nEff;
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         k = ELMT_kicau(klist, i);
//         if (k->jumlahBalasan > 0) {
//             count += 1;
//         }
//     }
//     return count;
// }

void PrintBalasan(Balasan b, int indent) {
    // int id = k.id;
    // Word text = k.text;
    // Word author = k.author;
    // DATETIME datetime = k.datetime;
    
    // printf("\n");
    // printTab(indent);
    // printf("ID = %d\n", id);
    
    // printTab(indent);
    // printWordNewline(author);

    // printTab(indent);
    // TulisDATETIME(datetime);
    // printf("\n");

    // printTab(indent);
    // printWordNewline(text);
        // printf("\n| ID = %d\n", b.id);

    //print author (without length seperti di ADT)
    printf("| ");
    int i;
    for (i = 0; i < b.author.Length; i++) 
    {
        printf("%c", b.author.TabWord[i]);
    }
    printf("\n");

    //print time upload kicauan
    printf("| ");
    TulisDATETIME(b.datetime);
    printf("\n");

    //print text
    int j = 0;
    printf("| ");
    while (b.text[j] != '\0')
    {
        printf("%c", b.text[j]);
        j++;
    }
}

void PrintTreeBalasan(TreeBalasan t, int indent) {
 if (t != Nil_BALASAN) {
  int i = 0;

        if (ROOT_BALASAN(t).id != IDX_UNDEF) {
            PrintBalasan(ROOT_BALASAN(t), indent);
        }
  while (i < TREECOUNT_BALASAN(t)) {
   PrintTreeBalasan(SUBTREE_BALASAN(t, i), indent + 1);
   i += 1;
  }
 }
}

void Balas(Account akunLogin, ListKicau *klist, Kicau *k) {
    ADVWORD();
    int IDKicau = WordToInt(currentWord);
    printf("IDUtas: %d\n", IDKicau);

    ADVWORD();
    int IDBalasan = WordToInt(currentWord);
    printf("IDBalasan: %d\n", IDBalasan);

    if (!isIdInKicauan) {
        printf("Wah, tidak terdapat kicau yang ingin Anda balas!\n");
    } else {
        TreeBalasan tree = klist->kicau[IDKicau].tree;
        if (!treeExists(tree, IDBalasan)) {
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        } else {
            printf("Masukkan balasan: \n");
            Balasan b;
            CreateBalasan(&b, akunLogin);
            klist->kicau[IDKicau].jumlahBalasan += 1;
            int id = klist->kicau[IDKicau].jumlahBalasan;

            insertTreeBalasan(tree, IDBalasan, b);

            printf("Selamat! Balasan telah diterbitkan!\nDetil balasan:\n");
            PrintBalasan(b, 1);
        }
    }
}

void DisplayBalasan(ListKicau *klist, Kicau *k) {
    ADVWORD();
    int IDKicau = WordToInt(currentWord);

    if (!isIdInKicauan) {
        printf("Wah, tidak terdapat kicau dengan ID tersebut!\n");
    } else if (klist->kicau[IDKicau].jumlahBalasan == 0) {
        printf("Belum terdapat balasan apapun pada kicau tersebut. Yuk balas kicau tersebut!\n");
    } else {
        TreeBalasan tree = klist->kicau[IDKicau].tree;
        PrintTreeBalasan(tree, 0);
    }
}

void HapusBalasan(ListKicau *klist, Kicau *k) {
    ADVWORD();
    int IDKicau = WordToInt(currentWord);
    printf("IDUtas: %d\n", IDKicau);

    ADVWORD();
    int IDBalasan = WordToInt(currentWord);
    printf("IDBalasan: %d\n", IDBalasan);

    if (!isIdInKicauan) {
        printf("Wah, tidak terdapat balasan yang ingin Anda hapus!\n");
    } else {
        TreeBalasan tree = klist->kicau[IDKicau].tree;
        if (!treeExists(tree, IDBalasan)) {
            printf("Wah, tidak terdapat balasan yang ingin Anda hapus!\n");
        } else {
            deleteTreeBalasan(&tree, IDBalasan);
            klist->kicau[IDKicau].jumlahBalasan += -1;

            printf("Balasan berhasil dihapus! Semoga bukan balasan yang penting, yah!\n");
        }
    }
}

int main() {
    ListKicau kList;
    CreateListKicau(&kList);

    Account akunLogin;
    // Inisialisasi akunLogin sesuai kebutuhan

    Kicau k1, k2;
    CreateKicau(akunLogin, &kList, &k1);
    CreateKicau(akunLogin, &kList, &k2);

    // Tambahkan balasan pada k1
    Balasan b1, b2;
    CreateBalasan(&b1, akunLogin);
    CreateBalasan(&b2, akunLogin);

    // Misalkan IDKicau dan IDBalasan sesuai kebutuhan
    int IDKicau = 1;
    int IDBalasan = 1;

    TreeBalasan tree1 = k1.tree;
    insertTreeBalasan(tree1, IDBalasan, b1);
    insertTreeBalasan(tree1, IDBalasan + 1, b2);

    // Cetak balasan k1
    printf("Balasan pada kicau dengan ID %d:\n", IDKicau);
    PrintTreeBalasan(tree1, 0);

    // Balas pada k2
    printf("Balas pada kicau dengan ID %d:\n", IDKicau + 1);
    Balas(akunLogin, &kList, &k2);

    // Tampilkan semua balasan k2
    printf("Semua balasan pada kicau dengan ID %d:\n", IDKicau + 1);
    DisplayBalasan(&kList, &k2);

    // Hapus balasan pada k1
    printf("Hapus balasan pada kicau dengan ID %d:\n", IDKicau);
    HapusBalasan(&kList, &k1);

    // Cetak k1 setelah hapus balasan
    printf("Balasan pada kicau dengan ID %d setelah dihapus:\n", IDKicau);
    PrintTreeBalasan(tree1, 0);

    return 0;
}
