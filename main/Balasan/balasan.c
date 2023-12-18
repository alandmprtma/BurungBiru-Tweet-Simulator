#include "../../modules/adt.h"
#include "../includeADT.h"

void CreateBalasan(Account akunLogin, ListKicau *listKicauan, Kicau *k) {
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    DATETIME local;
    CreateDATETIME(&local, tm_struct->tm_mday, tm_struct->tm_mon + 1, tm_struct->tm_year + 1900, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);

    //baca text kicauan
    int el = 0;
    printf("Masukkan balasan:\n");
    START();
    while (currentChar=='\n' || currentChar=='\r')
    {
        ADV();
    }
    
    while (currentChar!=';')
    {
        k->text[el] = currentChar;
        el++;
        ADV();
    }
    k->text[el] = '\0';
    ADV();
    k->datetime = local;
    k->author = akunLogin.username[0];
    k->jumlahBalasan = 0;
    k->balasan = Nil_BALASAN;
}

int hitungKicauanDenganBalasan(ListKicau listKicauan) {
    int n = listLengthKicauan(listKicauan);
    int count = 0;
    for (int i = 0; i < n; i++) {
        listKicauan.kicau[i].jumlahBalasan > 0 ? count++ : count;
    }
    return count;
}

void PrintBalasan(Balasan kontol, int indent) {
    printf("\n| ID = %d\n", kontol.id);

    printf("| ");
    int i;
    for (i = 0; i < kontol.author.Length; i++) 
    {
        printf("%c", kontol.author.TabWord[i]);
    }
    printf("\n");

    printf("| ");
    TulisDATETIME(kontol.datetime);
    printf("\n");

    int j = 0;
    printf("| ");
    while (kontol.text[j] != '\0')
    {
        printf("%c", kontol.text[j]);
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

void Balas(ListKicau *listKicauan, Account akunLogin, int idkicau, int idbalasan) {
    printf("IDKicau: %d\n", idkicau);
    printf("IDBalasan: %d\n", idbalasan);

    if (idkicau == IDX_UNDEF_KICAUAN) {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
    } else if (idkicau >= listKicauan->nEff) {
        printf("IDKicau tidak valid!\n");
    } else {
        TreeBalasan tree = listKicauan->kicau[idkicau].balasan;
        if (treeExists(tree, idbalasan)) {
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        } else {
            // Jika IDBalasan tidak valid
            if (idbalasan < 1 || idbalasan > listKicauan->kicau[idkicau].jumlahBalasan) {
                printf("IDBalasan tidak valid!\n");
            } else {

                Kicau kontol;
                CreateBalasan(akunLogin, listKicauan, &kontol);
                listKicauan->kicau[idkicau].jumlahBalasan += 1;
                int id = listKicauan->kicau[idkicau].jumlahBalasan;

                Balasan submittedBalasan;
                submittedBalasan.id = idbalasan;
                submittedBalasan.author = kontol.author;
                submittedBalasan.datetime = kontol.datetime;
                CopyString(submittedBalasan.text, kontol.text);
                if(idbalasan == 351) {
                    insertTreeBalasan(tree, idkicau, submittedBalasan);
                } else {
                    insertTreeBalasan(tree, idbalasan, submittedBalasan);
                }
                insertTreeBalasan(tree, idbalasan, submittedBalasan);

                printf("\nSelamat! Balasan telah diterbitkan!\n\nDetil balasan:");
                PrintBalasan(submittedBalasan, 1);
                printf("\n");
            }
        }
    }
}


void DisplayBalasan(ListKicau listKicauan, int idkicau) {

    if (idkicau == IDX_UNDEF_KICAUAN) {
        printf("Wah, tidak terdapat kicauan dengan ID tersebut!\n");
    } else if (listKicauan.kicau[idkicau].jumlahBalasan == 0) {
        printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
    } else {
        TreeBalasan tree = listKicauan.kicau[idkicau].balasan;
        PrintTreeBalasan(tree, 0);
    }
}

void HapusBalasan(ListKicau *listKicauan) {
    ADVWORD();
    int IDUtas = WordToInt(currentWord);
    printf("IDUtas: %d\n", IDUtas);

    ADVWORD();
    int IDBalasan = WordToInt(currentWord);
    printf("IDBalasan: %d\n", IDBalasan);

    int indexKicauan = idxOfKicauan(IDUtas, *listKicauan);
    if (indexKicauan == IDX_UNDEF_KICAUAN) {
        printf("Wah, tidak terdapat balasan yang ingin Anda hapus!\n");
    } else {
        TreeBalasan tree = listKicauan->kicau[indexKicauan].balasan;
        if (!treeExists(tree, IDBalasan)) {
            printf("Wah, tidak terdapat balasan yang ingin Anda hapus!\n");
        } else {
            deleteTreeBalasan(&tree, IDBalasan);
            listKicauan->kicau[indexKicauan].jumlahBalasan += -1;

            printf("Balasan berhasil dihapus! Semoga bukan balasan yang penting, yah!\n");
        }
    }
}
