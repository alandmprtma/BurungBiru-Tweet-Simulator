#include "Teman.h"

void daftarteman(boolean login, Account akunlogin, AccountList* listakun, Graf teman)
{
    ListGraf l;
    CreateListGraf(&l);
    if (login)
    {
        int idAkun;
        int i = 0;
        boolean found = false;
        while(i < listakun->count && found == false)
        {
            if(WordEqual(*listakun->accounts[i].username, *akunlogin.username))
            {
                idAkun = i;
                found = true;
            }
            i++; 
        }
        getOne(teman,idAkun,&l);
        if (isEmptylistGraf(l))
        {
            printf("%s belum mempunyai teman\n", akunlogin.username->TabWord);
        }
        else{
            printf("%s memiliki %d teman\n", akunlogin.username->TabWord, listEffGraf(l));
            printf("Daftar teman %s\n", akunlogin.username->TabWord);
            int i;
            for (i = 0; i < CAPACITYGRAF; i++)
            {
                if (ELMTLISTGRAF(l,i) == 1)
                {
                    printf("| %s\n", listakun->accounts[i].username->TabWord);
                }
            }
        }
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void hapusteman(boolean login, Account akunlogin, AccountList* listakun, Graf* teman)
{
    Word YA = {"YA", 2};
    Word TIDAK = {"TIDAK", 5};
    ListGraf l;
    CreateListGraf(&l);
    if (login){
        int idAkun;
        int i = 0;
        boolean found = false;
        while(i < listakun->count && found == false)
        {
            if(WordEqual(*listakun->accounts[i].username, *akunlogin.username))
            {
                idAkun = i;
                found = true;
            }
            i++; 
        }
        getOne(*teman,idAkun,&l);
        printf("Masukkan nama pengguna:\n");
        STARTSENTENCE();
        ADVSENTENCE();
        Word defriend = currentWord;
        found = false;
        int idTeman;
        i = 0;
        while(i < CAPACITYGRAF && !found)
        {
            if (ELMTLISTGRAF(l,i) == 1 && WordEqual(*listakun->accounts[i].username, currentWord))
            {
                idTeman = i;
                found = true;
            }
            i++;
        }
        if(found)
        {
            printf("Apakah anda yakin ingin menghapus ");
            printWord(defriend);
            printf(" dari daftar teman anda?(YA/TIDAK)\n");
            STARTWORD();
            ADVWORD();
            Word cmd = currentWord;
            if (WordEqual(YA, cmd))
            {
                printWord(defriend);
                printf(" berhasil dihapus dari daftar teman Anda.\n");
                ELMTGRAF(*teman, idAkun, idTeman) = 0;
                ELMTGRAF(*teman, idTeman, idAkun) = 0;

            }
            else if (WordEqual(TIDAK,cmd))
            {
                printf("Penghapusan teman dibatalkan.\n");
            }
            else{
                printf("Perintah tidak sesuai!\n\n");
            }
        }
        else
        {
            printWord(defriend);
            printf(" bukan teman Anda.\n");
        }
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n"); 
    }
}
