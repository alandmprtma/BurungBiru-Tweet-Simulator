#include "utas.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
               
boolean lanjut(Word input){
    Word ya = {"YA",2};
    Word tidak = {"TIDAK",5};
    if (WordEqual(input,ya)){
        return true;
    }else if (WordEqual(input, tidak)){
        return false;
    }else{
        printf("Masukan Tidak Valid !\n");
        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
        STARTWORD();
        lanjut(currentWord);
    }
}
void copyWordToString(char* destination,Word input){
    int i;
    for (i=0;i<input.Length;i++){
        (destination[i]) = input.TabWord[i];
    }
    (destination[i]) = '\0';
}

void cetakUtas(int idUtas, ListKicau kList, Account account, AccountList *listAccount, Graf teman)
{
    boolean isFound = false;
    Kicau kicauan;
    Word privat = {"Privat", 6};
    for (int i = 0; (i < kList.nEff) && (!isFound); i++)
    {
        if (kList.kicau[i].utasKicau != NULL)
        {
            if (kList.kicau[i].utasKicau->IDUtas == idUtas)
            {
                isFound = true;
                kicauan = kList.kicau[i];
            }
        }
    }
    if (!isFound)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else
    {
        int i;
        for (i = 0; !WordEqual(account.username[0], listAccount->accounts[i].username[0]); i++)
            ;
        int idUser = i;
        for (i = 0; !WordEqual(kicauan.author, listAccount->accounts[i].username[0]); i++)
            ;
        int idTeman = i;

        if (WordEqual(listAccount->accounts[idTeman].jenisAkun[0], privat) && ELMTGRAF(teman, idUser, idTeman) == 0)
        {
            printf("Akun yang membuat utas ini adalah akun privat!\nIkuti dahulu akun ini untuk melihat utasnya!\n");
        }
        else
        {
            printf("| ID = %d\n", kicauan.id);
            printf("| %s\n", kicauan.author.TabWord);
            printf("| ");
            TulisDATETIME(kicauan.datetime);
            printf("\n");
            printf("| %s\n", kicauan.text);
            kSambungAdd kSam;
            kSam = kicauan.utasKicau->content;
            i = 0;
            while (kSam != NULL)
            {
                printf("   | INDEX = %d\n", i + 1);
                printf("   | %s\n", kSam->author.TabWord);
                printf("   | ");
                TulisDATETIME(kSam->datetime);
                printf("\n");
                printf("   | %s\n\n", kSam->text);
                kSam = kSam->next;
                i++;
            }
        }
    }
}

kSambungAdd createKicauanSambung(Word tex, Account account)
{
    kSambungAdd kicauSam = (kSambungAdd)malloc(sizeof(KicauSambung));
    if (kicauSam != NULL)
    {
        kicauSam->next = NULL;
        copyWordToString((kicauSam->text), tex);
        CopyWordTo(&kicauSam->author, account.username[0]);
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        DATETIME local;
        CreateDATETIME(&local, tm_struct->tm_mday, tm_struct->tm_mon + 1, tm_struct->tm_year + 1900, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);
        kicauSam->datetime = local;
    }
    return kicauSam;
}

void sambungUtas(int idUtas, int index, ListKicau *kList, Account account)
{
    boolean isFound = false;
    Kicau *kicauan;
    for (int i = 0; (i < kList->nEff) && (!isFound); i++)
    {
        if (kList->kicau[i].utasKicau != NULL)
        {
            if (kList->kicau[i].utasKicau->IDUtas == idUtas)
            {
                isFound = true;
                kicauan = &kList->kicau[i];
            }
        }
    }
    if (!isFound)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else
    {
        if (!WordEqual(kicauan->author, account.username[0]))
        {
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
        else
        {
            int i = 1;
            kSambungAdd kSam = kicauan->utasKicau->content;
            if (kSam!=NULL){
                while (kSam->next != NULL)
                {
                    i++;
                    kSam = kSam->next;
                }

                if (index < 1)
                {
                    printf("Index terlalu rendah!\n");
                }
                else if (index > i + 1)
                {
                    printf("Index terlalu tinggi!\n");
                }
                else
                {
                    STARTSENTENCE();
                    printf("Masukkan kicauan:\n");
                    STARTSENTENCE();
                    kSam = kicauan->utasKicau->content;
                    kSambungAdd newKSam = createKicauanSambung(currentWord, account);
                    if (index == 1)
                    {
                        newKSam->next = kSam;
                        kicauan->utasKicau->content = newKSam;
                    }
                    else
                    {
                        for (int j = 2; j < index; j++)
                        {
                            kSam = kSam->next;
                        }
                        if ((kSam->next) == NULL)
                        {
                            kSam->next = newKSam;
                        }
                        else
                        {
                            newKSam->next = kSam->next;
                            kSam->next = newKSam;
                        }
                    }
                    printf("Utas berhasil disambung !\n");
                }
            }else{
                if (index>1){
                    printf("Index terlalu tinggi!\n");
                }else{
                    STARTSENTENCE();
                    printf("Masukkan kicauan:\n");
                    STARTSENTENCE();
                    kSam = kicauan->utasKicau->content;
                    kSambungAdd newKSam = createKicauanSambung(currentWord, account);
                    kicauan->utasKicau->content = newKSam;
                    printf("Utas berhasil disambung !\n");
                }
            }
        }
    }
}

void hapusUtas(int idUtas, int index, ListKicau *kList, Account account)
{
    boolean isFound = false;
    Kicau *kicauan;
    for (int i = 0; (i < kList->nEff) && (!isFound); i++)
    {
        if (kList->kicau[i].utasKicau != NULL)
        {
            if (kList->kicau[i].utasKicau->IDUtas == idUtas)
            {
                isFound = true;
                kicauan = &kList->kicau[i];
            }
        }
    }
    if (!isFound)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else
    {
        if (!WordEqual(kicauan->author, account.username[0]))
        {
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        }
        else
        {
            if (index == 0)
            {
                printf("Anda tidak bisa menghapus kicauan utama!\n");
            }
            else
            {
                kSambungAdd kSam = kicauan->utasKicau->content;
                kSambungAdd delKSam;
                if (index == 1)
                {
                    delKSam = kSam;
                    kSam = kSam->next;
                    kicauan->utasKicau->content = kSam;
                    free(delKSam);
                    printf("Kicauan sambungan berhasil dihapus!\n");
                }
                else
                {
                    for (int i = 2; i < index && kSam != NULL; i++)
                    {
                        kSam = kSam->next;
                    }
                    if (kSam == NULL)
                    {
                        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
                    }
                    else
                    {
                        delKSam = kSam->next;
                        kSam->next = delKSam->next;
                        free(delKSam);
                        printf("Kicauan sambungan berhasil dihapus!\n"); 
                    }
                }
            }
        }
    }
}

void createUtas(int id, ListKicau *kList, Account account, int *jumlahUtas)
{
    Word ya = {"YA", 2};
    Word tidak = {"TIDAK", 5};
    boolean isFound = false;
    int i;
    for (i = 0; (i < kList->nEff) && (!isFound); i++)
    {
        if (kList->kicau[i].id == id)
        {
            isFound = true;
        }
    }
    i -= 1;
    if (!isFound)
    {
        printf("Kicauan tidak ditemukan\n");
    }
    else
    {
        Kicau *kicau = &kList->kicau[i];
        if (!WordEqual(kicau->author, account.username[0]))
        {
            printf("Utas ini bukan milik anda!\n");
        }
        else
        {
            if (kicau->utasKicau != NULL)
            {
                printf("Kicauan ini telah digunakan utas lain!\n");
            }
            else
            {
                boolean isStop = false;
                STARTSENTENCE();
                printf("Utas berhasil dibuat!\n");
                printf("Masukkan kicauan: \n");
                STARTSENTENCE();
                kSambungAdd kSam = createKicauanSambung(currentWord, account);
                Utas* uts;
                uts = (Utas*)malloc(sizeof(Utas));
                uts->content = kSam;
                *jumlahUtas += 1;
                uts->IDUtas = *jumlahUtas;
                kicau->utasKicau = uts;
                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                STARTWORD();
                if (!lanjut(currentWord))
                {
                    isStop = true;
                }
                else
                {
                    isStop = false;
                }
                while (!isStop)
                {
                    STARTSENTENCE();
                    printf("Masukkan kicauan:\n");
                    STARTSENTENCE();
                    kSam->next = createKicauanSambung(currentWord, account);
                    kSam = kSam->next;
                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                    STARTWORD();
                    if (!lanjut(currentWord))
                    {
                        isStop = true;
                    }
                    else
                    {
                        isStop = false;
                    }
                }
                printf("Utas selesai!\n");
            }
        }
    }
}