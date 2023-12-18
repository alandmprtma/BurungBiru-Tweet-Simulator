#include "PermintaanPertemanan.h"


void tambahteman(boolean login, Account akunlogin, AccountList* listakun, Graf Teman, prioqueuefren* Q){
    prioqueuefren quser, qsisa;
    if(login)
    {
        int idAkun;
        int i = 0;
        boolean found = false;
        ListGraf l;
        CreateListGraf(&l);
        while(i < listakun->count && found == false)
        {
            if(WordEqual(*listakun->accounts[i].username, *akunlogin.username))
            {
                idAkun = i;
                found = true;
            }
            i++; 
        }
        getOne(Teman,idAkun,&l);
        Enqueueuserprio(Q, idAkun, &quser, &qsisa);
        if(IsEmptyPrio(quser))
        {
            printf("Masukkan nama pengguna:\n");
            STARTSENTENCE();
            ADVSENTENCE();
            Word user = currentWord;
            int idTeman;
            i = 0;
            found = false;
            while(i < listakun->count && found == false)
            {
                if(WordEqual(*listakun->accounts[i].username, user))
                {
                    idTeman = i;
                    found = true;
                }
                i++; 
            }
            if (WordEqual(user, *akunlogin.username)){
                printf("Anda tidak dapat mengirim permintaan pertemanan kepada diri sendiri.\n");
            }
            else if (l.content[idTeman] == 1){
                printf("Anda sudah berteman dengan ");
                printWord(user);
                printf(".\n");
            }
            else
            {
                int i = HeadQ(*Q);
                boolean cek = true;
                while (i != TailQ(*Q)+1 && cek){
                    teman temp = ElmtQ(*Q,i);
                    if (temp.IDpengirim == idAkun && temp.IDpengirim == idTeman)
                    {
                        cek = false;
                    }
                    i = (i + 1) % MaxElQ(*Q);
                }
                if(found && cek){
                    teman temp;
                    temp.IDpengirim = idAkun;
                    temp.IDpenerima = idTeman;
                    temp.Jumlahteman = listEffGraf(l);
                    Enqueueprio(&qsisa, temp);
                    printf("Permintaan pertemanan kepada ");
                    printWord(user);
                    printf(" telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n");
                }
                else if (found && !cek){
                    printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                    printWord(user);
                    printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
                }
                else{
                    printf("Pengguna bernama ");
                    printWord(user);
                    printf(" tidak ditemukan.\n");
                }
            }
        }
        else{
            printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n");
        }
        concatenationprio(quser, qsisa, Q);
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void daftarpermintaanteman(boolean login, Account akunlogin, AccountList* listakun, prioqueuefren *Q)
{
    prioqueuefren quser, qsisa;
    if(login){
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
        Enqueueuserprio(Q, idAkun, &quser, &qsisa);
        PrintPrioQueue(quser, listakun);
        concatenationprio(quser, qsisa, Q);
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void setujuipermintaanteman(boolean login, Account akunlogin, AccountList* listakun, Graf* Teman, prioqueuefren* Q){
    Word YA = {"YA", 2};
    Word TIDAK = {"TIDAK", 5};
    prioqueuefren quser, qsisa;
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
        Enqueueuserprio(Q, idAkun, &quser, &qsisa);
        if(IsEmptyPrio(quser)){
            printf("Tidak ada permintaan pertemanan untuk Anda.\n\n");
        }
        else{
            int idteman;
            PrintTopPrioQueueChar(quser, idAkun, listakun, &idteman);
            if(IsEmptyPrio(qsisa)){
            }
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");
            STARTWORD();
            ADVWORD();
            Word cmd = currentWord;
            teman temp;
            if(WordEqual(cmd, YA)){
                Dequeueprio(&quser, &temp);
                ELMTGRAF(*Teman, idAkun, idteman) = 1;
                ELMTGRAF(*Teman, idteman, idAkun) = 1;
                printf("Permintaan pertemanan dari ");
                printWord(*listakun->accounts[idteman].username);
                printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
                printWord(*listakun->accounts[idteman].username);
                printf(".\n\n");
                concatenationprio(quser, qsisa, Q);
            }
            else if(WordEqual(cmd, TIDAK)){
                Dequeueprio(&quser, &temp);
                printf("Permintaan pertemanan dari ");
                printWord(*listakun->accounts[idteman].username);
                printf(" telah ditolak.\n\n");
                concatenationprio(quser, qsisa, Q);
            }
            else{
                printf("Perintah tidak sesuai!\n\n");
            }
        }
    }
    else{
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}