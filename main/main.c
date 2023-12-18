#include "./includeADT.h"
#include "../modules/adt.h"

void ReadDraf_FILE(char filename[], AccountList *list, Stack *S){
/*Membaca file Draf dari Draf.config kedalam program
    I.S. Stack terdefinisi dan AccountList sudah diakuisisi dari user.config
    F.S. Stack terisi dengan drafkicauan dari Draf.Config
    */
    int N;
    STARTWORD_FILE(filename);
    N = WordToInt(currentWord);
    int i;
    for(i = 0; i < N; i++)
    {
        ADVSENTENCE();
        Word user;
        int jumlah;
        int j;
        CopyWordTo(&user, currentWord);
        user.Length = user.Length - 2;
        int idAkun;
        int cok = 0;
        boolean found = false;
        while(cok < list->count && found == false)
        {
            if(WordEqual(*list->accounts[cok].username, user))
            {
                idAkun = cok;
                found = true;
            }
            cok++; 
        }
        jumlah = CharToInt(currentWord.TabWord[currentWord.Length-1]);
        for(j = 0; j < jumlah; j++)
        {
            drafkicau DrafKicau;
            DATETIME waktudraf;
            ADVSENTENCE();
            Word draf = currentWord;
            if (j == jumlah-1 && i == N-1){
                currentWord = emptyWord;
                ADV();
                int m;
                for(m = 0; m < 19; m++){
                    currentWord.TabWord[m] = currentChar;
                    currentWord.Length++;
                    ADV();
                }
            }
            else{
                ADVSENTENCE();
            }
            int k;
            Word dd;
            for(k = 0; k < 2; k++){
                dd.TabWord[k] = currentWord.TabWord[k];
            }
            dd.Length = 2;
            int DD = WordToInt(dd);
            Word mm;
            for(k = 3; k < 5; k++){
                mm.TabWord[k-3] = currentWord.TabWord[k];
            }
            mm.Length = 2;
            int MM = WordToInt(mm);
            Word yy;
            for(k = 6; k < 10; k++){
                yy.TabWord[k-6] = currentWord.TabWord[k];
            }
            yy.Length = 4;
            int YY = WordToInt(yy);
            Word hh;
            for(k = 11; k < 13; k++){
                hh.TabWord[k-11] = currentWord.TabWord[k];
            }
            hh.Length = 2;
            int HH = WordToInt(hh);
            Word m;
            for(k = 14; k < 16; k++){
                m.TabWord[k-14] = currentWord.TabWord[k];
            }
            m.Length = 2;
            int M = WordToInt(m);
            Word ss;
            for(k = 17; k < 19; k++){
                ss.TabWord[k-17] = currentWord.TabWord[k];
            }
            ss.Length = 2;
            int SS = WordToInt(ss);
            CreateDATETIME(&waktudraf, DD, MM, YY, HH, M, SS);
            DrafKicau.Draf = draf;
            DrafKicau.IDuser = idAkun;
            DrafKicau.waktu = waktudraf;
            Push(S, DrafKicau);
        }
    }
}
int main()
{

    // Utilities
    boolean login = false;
    boolean runProgram = true;

    // Array untuk menampung user saat ini
    AccountList akun;
    CreateAccountList(&akun);
    Graf teman;
    createEmptyGraf(&teman);
    prioqueuefren Q;
    MakeEmptyprio(&Q, 100);
    Stack draf;
    CreateEmptyStack(&draf);
    // ReadUser_FILE("../cfg/pengguna.config", &akun, &teman, &Q);
    // ReadDraf_FILE("../cfg/draf.config", &akun, &draf);

    Stack drafStack[20]; // Buat 20 stack untuk 20 pengguna
    // int userID = 0;                  // ID pengguna saat ini
    // CreateEmpty(&drafStack[userID]); // Inisialisasi stack untuk pengguna saat ini
    
    Account akunLogin;
    ListKicau kList;
    CreateListKicau(&kList);
    Kicau k;
    // ReadKicau_FILE("../cfg/kicauan.config", &kList);
    int idUtas = 0;
    // readUtas("../cfg/utas.config",&kList,&idUtas,akun);
    boolean isLogin = false;
    printf("           ____  __  __  ____  ____  ____  ____ /\\ \n");
    printf("    __    (  _ \\(  )(  )(  _ \\(  _ \\(_  _)(  _ \\)(    __    \n");
    printf("___( o)>   ) _ < )(__)(  )   / ) _ < _)(_  )   /\\/  <(o )___\n");
    printf("\\ <_. )   (____/(______)(_)\\_)(____/(____)(_)\\_)()   ( ._> /\n");
    printf(" `---'              Tempat Anda Mencibir              `---' \n\n");

    printf("Selamat datang di Burbir. Selamat berkicau!\n\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n\n");
    char path[MAXChar] = "../cfg/";
    printf("Silahkan masukan folder konfigurasi untuk dimuat:");
    STARTSENTENCE();
    char *fold = (char*)malloc(MAXChar*sizeof(char));
    char *path1 = (char*)malloc(MAXChar*sizeof(char));
    w2s(fold,currentWord);
    path1 = strcopy(path1,path);
    strconcat(path1,fold);
    strconcat(path1,"/");
    // char fold1[100];
    // strcopy(fold1,path);
    // printf("%s\n",fold1);
    // char folderName[] = "contoh";
    // char *folder= (char *)malloc(strlen(path) + strlen(folderName) + 1);
    // strcpy(folder,path);
    // strcat(folder,folderName);

    while (!isDirExist(path1)){
        printf("Tidak ada folder yang dimaksud!\n");
        free(path1);
        free(fold);
        STARTSENTENCE();
        printf("Masukkan config yang hendak dimuat:");
        STARTSENTENCE();
        char *fold = (char*)malloc(MAXChar*sizeof(char));
        char *path1 = (char*)malloc(MAXChar*sizeof(char));
        w2s(fold,currentWord);
        strcopy(path1,path);
        strconcat(path1,fold);
        strconcat(path1,"/");
    }

    for (int i=0;i<5;i++){
        if (i==0){ 
            char file[20] = "pengguna.config";
            char *folder = (char*)malloc(MAXChar*sizeof(char));
            strcpy(folder,path1);
            strcat(folder,file);
            ReadUser_FILE(folder,&akun,&teman,&Q);
            free(folder);
        }
        else if (i==1){ 
            char file[20] = "kicauan.config";
            char *folder = (char*)malloc(MAXChar*sizeof(char));
            strcpy(folder,path1);
            strcat(folder,file);
            ReadKicau_FILE(folder,&kList);
            free(folder);
        } 
        else if (i==2){ // Draft config
            char file[20] = "draf.config";
            char *folder = (char*)malloc(MAXChar*sizeof(char));
            strcpy(folder,path1);
            strcat(folder,file);
            ReadDraf_FILE(folder, &akun, &draf);
            int i;
            for (i = 0; i < 20; i++)
            {
                CreateEmptyStack(&drafStack[i]);
            }

            while (!IsEmptyStack(draf))
            {
                drafkicau temp;
                Pop(&draf, &temp);
                for (i = 0; i < 20; i++)
                {
                    if (temp.IDuser == i)
                    {
                        Push(&drafStack[i], temp);
                    }
                }
            }
            free(folder);
        }
        else if (i==3){ // Utas config
            char file[20] = "utas.config";
            char *folder = (char*)malloc(MAXChar*sizeof(char));
            strcpy(folder,path1);
            strcat(folder,file);
            readUtas(folder,&kList,&idUtas,akun);
            free(folder);
        }
        else if (i==4){ //Reply config

        }
        
    }
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    while (runProgram)
    {
        printf(">> ");
        STARTCOMMAND();
        Word tes = {"tes", 3};
        Word command = currentWord;
        Word tutup_program = {"TUTUP_PROGRAM", 13};
        Word daftar = {"DAFTAR", 6};
        Word masuk = {"MASUK", 5};
        Word keluar = {"KELUAR", 6};
        Word ganti_profil = {"GANTI_PROFIL", 12};
        Word jenis_akun = {"ATUR_JENIS_AKUN", 15};
        Word ubah_foto = {"UBAH_FOTO_PROFIL", 16};
        Word lihat_profil = {"LIHAT_PROFIL", 12};
        Word curr_user = {"USER", 4};
        Word daftar_teman = {"DAFTAR_TEMAN", 12};
        Word hapus_teman = {"HAPUS_TEMAN", 11};
        Word tambah_teman = {"TAMBAH_TEMAN", 12};
        Word daftar_permintaan_teman = {"DAFTAR_PERMINTAAN_PERTEMANAN", 28};
        Word setujui_pertemanan = {"SETUJUI_PERTEMANAN", 18};
        Word utas = {"UTAS", 4};
        Word kicau = {"KICAU", 5};
        Word suka_kicauan = {"SUKA_KICAUAN", 12};
        Word kicauan = {"KICAUAN", 7};
        Word cari_kicauan = {"CARI_KICAUAN", 12};
        Word ubah_kicauan = {"UBAH_KICAUAN", 12};
        Word hapus_balasan = {"HAPUS_BALASAN", 13};
        Word sambung_utas = {"SAMBUNG_UTAS", 12};
        Word hapus_utas = {"HAPUS_UTAS", 10};
        Word cetak_utas = {"CETAK_UTAS", 10};
        Word buat_draf = {"BUAT_DRAF", 9};
        Word lihat_draf = {"LIHAT_DRAF", 10};
        Word kelompok_teman = {"KELOMPOK_TEMAN", 14};
        Word fyb = {"FYB", 3};
        Word balas = {"BALAS",5};
        Word balasan = {"BALASAN",7};
        Word muat = {"MUAT",4};
        Word simpan = {"SIMPAN",6};

        if (WordEqual(command, tutup_program))
        {
            SaveUser_FILE("../cfg/pengguna.config", &akun, teman, Q);
            SaveDraf_FILE("../cfg/draf.config", &akun, drafStack);
            saveKicau_FILE("../cfg/kicauan.config", kList);
            printf("%d\n", idUtas);
            saveUtas("../cfg/utas.config",&kList,idUtas,akun);
            runProgram = false;
        }
        else if (WordEqual(command, daftar))
        {
            if (isLogin)
            {
                printf("Anda sedang login dengan akun %s, silahkan keluar dulu.\n", akunLogin.username->TabWord);
            }
            else if (IsAccountListFull(&akun))
            {
                printf("Batas jumlah pengguna sudah tercapai, tidak dapat menambahkan akun baru.\n");
            }
            else
            {
                signup(&akun);
                teman.mem[akun.count-1][akun.count-1] = 1;
            }
        }

        else if (WordEqual(command, masuk))
        {
            if (isLogin)
            {
                printf("Anda sudah login dengan akun %s\n", akunLogin.username->TabWord);
            }
            else
            {
                signin(&akun, &akunLogin);
                isLogin = true;
            }
        }

        else if (WordEqual(command, ganti_profil))
        {
            if (!isLogin)
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            else
            {
                edit_profile(&akun, akunLogin);
            }
        }

        else if (WordEqual(command, keluar))
        {
            if (!isLogin)
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            else
            {
                printf("Keluar dari akun dengan username %s\n", akunLogin.username->TabWord);
                outUser(&akunLogin);
                isLogin = false;
            }
        }

        else if (WordEqual(command, jenis_akun))
        {
            if (!isLogin)
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            else
            {
                ganti_jenis_akun(&akun, akunLogin);
            }
        }

        else if (WordEqual(command, ubah_foto))
        {
            if (!isLogin)
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            else
            {
                edit_foto(&akun, akunLogin);
            }
        }

        else if (WordEqual(command, curr_user))
        {
            DisplayAccounts(&akun);
        }
        else if (WordEqual(command, hapus_teman))
        {
            hapusteman(isLogin, akunLogin, &akun, &teman);
        }
        else if (WordEqual(command, tambah_teman))
        {
            tambahteman(isLogin, akunLogin, &akun, teman, &Q);
        }
        else if (WordEqual(command, daftar_teman))
        {
            daftarteman(isLogin, akunLogin, &akun, teman);
        }
        else if (WordEqual(command, daftar_permintaan_teman))
        {
            daftarpermintaanteman(isLogin, akunLogin, &akun, &Q);
        }
        else if (WordEqual(command, setujui_pertemanan))
        {
            setujuipermintaanteman(isLogin, akunLogin, &akun, &teman, &Q);
        }
        else if (wordCheck(command, 0, 11, lihat_profil) && command.Length > 12)
        {
            if (!isLogin)
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            else
            {
                show_profile(&akun, wordFromIndex(command, 13));
            }
        }
        else if (wordCheck(command, 0, 3, utas)) // utas
        {
            int i = 5;
            int id = 0;
            while (i < command.Length)
            {
                id *= 10;
                id += CharToInt(command.TabWord[i]);
                i++;
            }
            if (isLogin){
                createUtas(id, &kList, akunLogin, &idUtas);
            }else{
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (wordCheck(command, 0, 11, sambung_utas)) // sambung utas
        {
            int idUtas = 0;
            int index = 0;
            int i = 13;
            while (command.TabWord[i] != ' ')
            {
                idUtas *= 10;
                idUtas += CharToInt(command.TabWord[i]);
                i++;
            }
            i++;
            while (i<command.Length)
            {
                index *= 10;
                index += CharToInt(command.TabWord[i]);
                i++;
            }
            if (isLogin){
                sambungUtas(idUtas, index, &kList, akunLogin);
            }else{
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");

            }
        }
        else if (wordCheck(command, 0, 9, hapus_utas)) // hapus utas
        {
            int idUtas = 0;
            int index = 0;
            int i = 11;
            while (command.TabWord[i] != ' ')
            {
                idUtas *= 10;
                idUtas += CharToInt(command.TabWord[i]);
                i++;
            }
            i++;
            while (i<command.Length)
            {
                index *= 10;
                index += CharToInt(command.TabWord[i]);
                i++;
            }
            if (isLogin){
                hapusUtas(idUtas, index, &kList, akunLogin);
            }else{
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
            
        }
        else if (wordCheck(command, 0, 9, cetak_utas)) // cetak utas
        {
            int idUtas = 0;
            int i = 11;
            while (i<command.Length)
            {
                idUtas *= 10;
                idUtas += CharToInt(command.TabWord[i]);
                i++;
            }
            if (isLogin){
                cetakUtas(idUtas, kList, akunLogin, &akun, teman);
            }else{
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
            
        else if (WordEqual(command, buat_draf))
        {
            int idUser;
            int i = 0;
            boolean found = false;
            while (i < akun.count && found == false)
            {
                if (WordEqual(*akun.accounts[i].username, *akunLogin.username))
                {
                    idUser = i;
                    found = true;
                }
                i++;
            }
            if (isLogin)
            {
                drafkicau DrafUser;
                STARTSENTENCE();
                printf("Masukkan draf:\n");

                // Akuisisi dan simpan draf dalam stack
                STARTSENTENCE();
                CopyWordTo(&DrafUser.Draf, currentWord);
                time_t rawtime;
                struct tm *timeinfo;

                time(&rawtime);                 // Get the current time
                timeinfo = localtime(&rawtime); // Convert to local time

                // Access individual components
                int SS, M, HH, DD, MM, YY;
                getlocaltime(&SS, &M, &HH, &DD, &MM, &YY);
                DATETIME waktudraf;
                CreateDATETIME(&waktudraf, DD, MM, YY, HH, M, SS);
                DrafUser.waktu = waktudraf;
                DrafUser.IDuser = idUser;
                Push(&drafStack[idUser], DrafUser);

                printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
                ADVSENTENCE();

                while (1)
                {
                    STARTWORD();
                    if (WordEqual(currentWord, stringToWord("HAPUS", 5)))
                    {
                    // Pengguna ingin menghapus draf
                    if (!IsEmptyStack(drafStack[idUser]))
                    {
                        Pop(&drafStack[idUser], &DrafUser);
                        printf("Draf telah berhasil dihapus!\n");
                    }
                    else
                    {
                        printf("Tidak ada draf yang bisa dihapus.\n");
                    }
                    break;
                    }
                    else if (WordEqual(currentWord, stringToWord("SIMPAN", 6)))
                    {
                    // Pengguna ingin menyimpan draf
                    printf("Draf telah berhasil disimpan!\n");
                    break;
                    }
                    else if (WordEqual(currentWord, stringToWord("TERBIT", 6)))
                    {
                    // Pengguna ingin menerbitkan draf
                    Pop(&drafStack[idUser], &DrafUser);
                    DATETIME waktuterbit;
                    int SS, M, HH, DD, MM, YY;
                    getlocaltime(&SS, &M, &HH, &DD, &MM, &YY);
                    CreateDATETIME(&waktuterbit, DD, MM, YY, HH, M, SS);
                    DrafUser.waktu = waktuterbit;

                    ADVWORD();

                    printf("Selamat! Draf kicauan telah diterbitkan!\n\n");
                    Kicau temp;
                    temp.id = kList.nEff + 1;
                    temp.like = 0;
                    wordToString(temp.text, DrafUser.Draf);
                    temp.author = *akun.accounts[idUser].username;
                    temp.datetime = waktuterbit;
                    temp.utasKicau = NULL;

                    // Tambahkan logikanya untuk menerbitkan draf
                    AddToKicauan(&kList, temp);

                    printf("Detil kicauan:\n");
                    printf("| ID = %d\n", temp.id);
                    printf("| ");
                    printWord(*akun.accounts[idUser].username);
                    printf("\n");
                    printf("| ");
                    TulisDATETIME(waktuterbit);
                    printf("\n");
                    printf("| ");
                    printWord(DrafUser.Draf);
                    printf("\n");
                    printf("| ");
                    printf("Disukai: 0\n");
                    break;
                    }
                    else
                    {
                    printf("Perintah tidak valid. Silakan masukkan 'HAPUS', 'SIMPAN', 'TERBIT', atau 'KEMBALI'.\n");
                    }
                }
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (WordEqual(command, lihat_draf))
        {
            int idUser;
            int i = 0;
            boolean found = false;
            while (i < akun.count && found == false)
            {
                if (WordEqual(*akun.accounts[i].username, *akunLogin.username))
                {
                    idUser = i;
                    found = true;
                }
                i++;
            }
            if (isLogin)
            {
                drafkicau DrafUser;

                // Check if the user has any drafts
                if (!IsEmptyStack(drafStack[idUser]))
                {
                    printf("Ini draf terakhir anda:\n");
                    printf("| ");
                    TulisDATETIME(InfoTop(drafStack[idUser]).waktu);
                    printf("\n");
                    printf("| ");
                    printWord(InfoTop(drafStack[idUser]).Draf);
                    printf("\n");

                    printf("\nApakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");

                    while (1)
                    {
                    STARTWORD();
                    if (WordEqual(currentWord, stringToWord("HAPUS", 5)))
                    {
                        // Pengguna ingin menghapus draf
                        if (!IsEmptyStack(drafStack[idUser]))
                        {
                        Pop(&drafStack[idUser], &DrafUser);
                        printf("Draf telah berhasil dihapus!\n");
                        }
                        else
                        {
                        printf("Tidak ada draf yang bisa dihapus.\n");
                        }
                        break;
                    }
                    else if (WordEqual(currentWord, stringToWord("UBAH", 4)))
                    {
                        // Akuisisi dan simpan draf baru dalam stack
                        Pop(&drafStack[idUser], &DrafUser);
                        STARTSENTENCE();
                        printf("Masukkan draf yang baru:\n");

                        // Akuisisi dan simpan draf dalam stack
                        STARTSENTENCE();
                        CopyWordTo(&DrafUser.Draf, currentWord);
                        time_t rawtime;
                        struct tm *timeinfo;
                        time(&rawtime);                 // Get the current time
                        timeinfo = localtime(&rawtime); // Convert to local time

                        // Access individual components
                        int SS, M, HH, DD, MM, YY;
                        getlocaltime(&SS, &M, &HH, &DD, &MM, &YY);
                        DATETIME waktudraf;
                        CreateDATETIME(&waktudraf, DD, MM, YY, HH, M, SS);
                        DrafUser.waktu = waktudraf;
                        Push(&drafStack[idUser], DrafUser);

                        printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

                        while (1)
                        {
                        STARTWORD();
                        if (WordEqual(currentWord, stringToWord("HAPUS", 5)))
                        {
                            // Pengguna ingin menghapus draf
                            if (!IsEmptyStack(drafStack[idUser]))
                            {
                            Pop(&drafStack[idUser], &DrafUser);
                            printf("Draf telah berhasil dihapus!\n");
                            }
                            else
                            {
                            printf("Tidak ada draf yang bisa dihapus.\n");
                            }
                            break;
                        }
                        else if (WordEqual(currentWord, stringToWord("SIMPAN", 6)))
                        {
                            // Pengguna ingin menyimpan draf
                            printf("Draf telah berhasil disimpan!\n");
                            break;
                        }
                        else if (WordEqual(currentWord, stringToWord("TERBIT", 6)))
                        {
                            // Di-pop karena draf telah diterbitkan
                            Pop(&drafStack[idUser], &DrafUser);
                            DATETIME waktuterbit;
                            int SS, M, HH, DD, MM, YY;
                            getlocaltime(&SS, &M, &HH, &DD, &MM, &YY);
                            CreateDATETIME(&waktuterbit, DD, MM, YY, HH, M, SS);
                            DrafUser.waktu = waktuterbit;

                            ADVWORD();

                            printf("Selamat! Draf kicauan telah diterbitkan!\n\n");
                            Kicau temp;
                            temp.id = kList.nEff + 1;
                            temp.like = 0;
                            wordToString(temp.text, DrafUser.Draf);
                            temp.author = *akun.accounts[idUser].username;
                            temp.datetime = waktuterbit;
                            temp.utasKicau = NULL;

                            // Tambahkan logikanya untuk menerbitkan draf
                            AddToKicauan(&kList, temp);

                            printf("Detil kicauan:\n");
                            printf("| ID = %d\n", temp.id);
                            printf("| ");
                            printWord(*akun.accounts[idUser].username);
                            printf("\n");
                            printf("| ");
                            TulisDATETIME(waktuterbit);
                            printf("\n");
                            printf("| ");
                            printWord(DrafUser.Draf);
                            printf("\n");
                            printf("| ");
                            printf("Disukai: 0\n");
                            break;
                        }
                        else if (WordEqual(currentWord, stringToWord("KEMBALI", 7)))
                        {
                            // Pengguna ingin kembali
                            printf("Kembali ke draf sebelumnya.\n");
                            break;
                        }
                        else
                        {
                            printf("Perintah tidak valid. Silakan masukkan 'HAPUS', 'SIMPAN', 'TERBIT', atau 'KEMBALI'.\n");
                        }
                        }
                        break;
                    }
                    else if (WordEqual(currentWord, stringToWord("TERBIT", 6)))
                    {
                        // Di-pop karena draf telah diterbitkan
                        Pop(&drafStack[idUser], &DrafUser);
                        DATETIME waktuterbit;
                        int SS, M, HH, DD, MM, YY;
                        getlocaltime(&SS, &M, &HH, &DD, &MM, &YY);
                        CreateDATETIME(&waktuterbit, DD, MM, YY, HH, M, SS);
                        DrafUser.waktu = waktuterbit;

                        ADVWORD();

                        printf("Selamat! Draf kicauan telah diterbitkan!\n\n");
                        Kicau temp;
                        temp.id = kList.nEff + 1;
                        temp.like = 0;
                        wordToString(temp.text, DrafUser.Draf);
                        temp.author = *akun.accounts[idUser].username;
                        temp.datetime = waktuterbit;
                        temp.utasKicau = NULL;

                        // Tambahkan logikanya untuk menerbitkan draf
                        AddToKicauan(&kList, temp);

                        printf("Detil kicauan:\n");
                        printf("| ID = %d\n", temp.id);
                        printf("| ");
                        printWord(*akun.accounts[idUser].username);
                        printf("\n");
                        printf("| ");
                        TulisDATETIME(waktuterbit);
                        printf("\n");
                        printf("| ");
                        printWord(DrafUser.Draf);
                        printf("\n");
                        printf("| ");
                        printf("Disukai: 0\n");
                        break;
                    }
                    else if (WordEqual(currentWord, stringToWord("KEMBALI", 7)))
                    {
                        // Pengguna ingin kembali
                        printf("Kembali ke draf sebelumnya.\n");
                        break;
                    }
                    else
                    {
                        printf("Perintah tidak valid. Silakan masukkan 'HAPUS', 'UBAH', 'TERBIT', atau 'KEMBALI'.\n");
                    }
                    }
                }
                else
                {
                    printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
                }
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
         else if (WordEqual(command, kicau))
        {
            if (isLogin)
            {
                CreateKicau(akunLogin, &kList, &k);
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (wordCheck(command, 0, 11, suka_kicauan) && command.Length > 12)
        {
            if (isLogin)
            {
                SukaKicau(akunLogin, wordFromIndex(command, 13), &kList, &k, &akun, teman);
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (WordEqual(command, kicauan))
        {
            if (isLogin)
            {
                Kicauan(akunLogin, kList);
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (wordCheck(command, 0, 11, ubah_kicauan) && command.Length > 12)
        {
            if (isLogin)
            {
                UbahKicau(akunLogin, wordFromIndex(command, 13), &kList);
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (wordCheck(command, 0, 11, cari_kicauan) && command.Length > 12)
        {
            if (isLogin)
            {
                KicauanTagar(kList, wordFromIndex(command, 13));
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        // else if (wordCheck(command, 0, 6, balasan) && command.Length > 7){
        //     if(isIdInKicauan(WordToInt(wordFromIndex(command, 8)), &kList)){
        //         if (isLogin){
        //             int idKicau = WordToInt(wordFromIndex(command, 8));
        //             DisplayBalasan(kList, 3);
        //         }
        //         else{
        //             printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
        //         }
        //     }
        //     else{
        //         printf("Perintah tidak dikenali.\n");
        //     }
        // }
        else if (wordCheck(command, 0, 4, balas) && command.Length > 5){
            if(isIdInKicauan(WordToInt(wordFromIndexToSpace(command, 6)), &kList)){
                if(isWordInteger(wordFromIndex(command, balas.Length + wordFromIndexToSpace(command, 6).Length + 1))){
                    if (isLogin){
                        int idKicau = WordToInt(wordFromIndexToSpace(command, 6));
                        int idBalasan = WordToInt(wordFromIndex(command, balas.Length + wordFromIndexToSpace(command, 6).Length + 2));
                        Balas(&kList, akunLogin, idKicau, idBalasan);
                    }
                }
                else{
                    printf(".\n");
                }
            }
            else{
                printf("Perintah tidak dikenali.\n");
            }
        }
        
        // else if (wordCheck(command, 0, 13, hapus_balasan) && command.Length > 14){
        //     if(isIdInKicauan(WordToInt(wordFromIndexToSpace(command, 14)), &kList)){
        //         if(isWordInteger(wordFromIndex(command, hapus_balasan.Length + wordFromIndexToSpace(command, 14).Length + 1))){
        //             if (isLogin){
        //                 int idKicau = WordToInt(wordFromIndexToSpace(command, 14));
        //                 int idBalasan = WordToInt(wordFromIndex(command, hapus_balasan.Length + wordFromIndexToSpace(command, 14).Length + 2));
        //                 HapusBalasan(&kList, akunLogin, idKicau, idBalasan);
        //             }
        //         }
        //         else{
        //             printf(".\n");
        //         }
        //     }
        //     else{
        //         printf("Perintah tidak dikenali.\n");
        //     }

        // }
        else if (WordEqual(command, kelompok_teman)){
            if (isLogin)
            {
                int idAkun;
                int i = 0;
                boolean found = false;
                while(i < akun.count && found == false)
                {
                    if(WordEqual(*akun.accounts[i].username, *akunLogin.username))
                    {
                        idAkun = i;
                        found = true;
                    }
                    i++; 
                }
                DisjointSet Group;
                findGroups(teman, idAkun, &Group);
                if (listEffGraf(Group) == 0){
                    printf("Terdapat 1 orang dalam Kelompok Teman ");
                    printWord(*akun.accounts[idAkun].username);
                    printf(" :\n");
                    printWord(*akun.accounts[idAkun].username);
                    printf("\n");
                }
                else{
                    printf("Terdapat %d orang dalam Kelompok Teman ", listEffGraf(Group));
                    printWord(*akun.accounts[idAkun].username);
                    printf(" :\n");
                    int j;
                    for (j = 0; j < CAPACITYGRAF-1; j++){
                        if (ELMTLISTGRAF(Group,j) == 1)
                        {
                            printWord(*akun.accounts[j].username);
                            printf("\n");
                        }
                    }
                }
            }
            else
            {
                printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
            }
        }
        else if (WordEqual(command, fyb)){
            DisplayFYB(kList);
        }else if(wordCheck(command,0,4,balas)){
            
        }else if(WordEqual(command,simpan)){
            if (!isLogin){
                STARTSENTENCE();
                printf("Masukkan nama folder yang hendak disimpan:");
                STARTSENTENCE();
                Word fileee = currentWord;

                printWord(currentWord);
                printf("\n\n");
                char path[MAXChar] = "../cfg/";
                char *fold = (char*)malloc(MAXChar*sizeof(char));
                char *path1 = (char*)malloc(MAXChar*sizeof(char));
                w2s(fold,currentWord);
                path1 = strcopy(path1,path);
                strconcat(path1,fold);
                strconcat(path1,"/");
                if (!isDirExist(path1)){
                    int check = mkdir(path1,0777);
                    printf("Membuat folder baru....\n");
                }
                char file[20] = "pengguna.config";
                char *folder = (char*)malloc(MAXChar*sizeof(char));
                strcpy(folder,path1);
                strcat(folder,file);
                SaveUser_FILE(folder, &akun, teman, Q);
                free(folder);
                char file1[20] = "draf.config";
                folder = (char*)malloc(MAXChar*sizeof(char));
                strcpy(folder,path1);
                strcat(folder,file1);

                SaveDraf_FILE(folder, &akun, drafStack);
                free(folder);

                char file2[20] = "kicauan.config";
                folder = (char*)malloc(MAXChar*sizeof(char));
                strcpy(folder,path1);
                strcat(folder,file2);
                saveKicau_FILE(folder, kList);
                free(folder);

                char file3[20] = "utas.config";
                folder = (char*)malloc(MAXChar*sizeof(char));
                strcpy(folder,path1);
                strcat(folder,file3);
                FILE *configFile = fopen(folder, "w");
                fprintf(configFile,"%d",idUtas);
                for (int i=0;i<kList.nEff;i++){
                    if (kList.kicau[i].utasKicau!=NULL){
                        fprintf(configFile,"\n%d\n",kList.kicau[i].id);
                        kSambungAdd k = kList.kicau[i].utasKicau->content;
                        int j = 1;
                        while (k->next!=NULL)
                        {
                            j++;
                            k = k->next;
                        }
                        fprintf(configFile,"%d",j);
                        k = kList.kicau[i].utasKicau->content;
                        for (int n=0;n<j;n++){
                            fprintf(configFile,"\n%s\n",k->text);
                            char str[MAXChar];
                            wordToString(str,k->author);
                            fprintf(configFile,"%s\n",str);
                            fprintf(configFile, "%02d/%02d/%d %02d:%02d:%02d", k->datetime.DD, k->datetime.MM, k->datetime.YYYY, k->datetime.T.HH, k->datetime.T.MM, k->datetime.T.SS);
                            k = k->next;
                        }
                    }
                }
                free(folder);

                CreateAccountList(&akun);
                createEmptyGraf(&teman);
                MakeEmptyprio(&Q, 100);
                CreateEmptyStack(&draf);
                CreateListKicau(&kList);
                for (int i=0;i<5;i++){
                    if (i==0){ 
                        char *folder = (char*)malloc(MAXChar*sizeof(char));
                        strcpy(folder,path1);
                        strcat(folder,file);
                        ReadUser_FILE(folder,&akun,&teman,&Q);
                        free(folder);
                    }
                    else if (i==1){ 
                        char *folder = (char*)malloc(MAXChar*sizeof(char));
                        strcpy(folder,path1);
                        strcat(folder,file2);
                        ReadKicau_FILE(folder,&kList);
                        free(folder);
                    } 
                    else if (i==2){ // Draft config
                        char *folder = (char*)malloc(MAXChar*sizeof(char));
                        strcpy(folder,path1);
                        strcat(folder,file1);
                        ReadDraf_FILE(folder, &akun, &draf);
                        int i;
                        for (i = 0; i < 20; i++)
                        {
                            CreateEmptyStack(&drafStack[i]);
                        }

                        while (!IsEmptyStack(draf))
                        {
                            drafkicau temp;
                            Pop(&draf, &temp);
                            for (i = 0; i < 20; i++)
                            {
                                if (temp.IDuser == i)
                                {
                                    Push(&drafStack[i], temp);
                                }
                            }
                        }
                        free(folder);
                    }
                    else if (i==3){ // Utas config
                        char *folder = (char*)malloc(MAXChar*sizeof(char));
                        strcpy(folder,path1);
                        strcat(folder,file3);
                        readUtas(folder,&kList,&idUtas,akun);
                        free(folder);
                    }
                    else if (i==4){ //Reply config

                    }
                    
                }
            }else{
            printf("Anda harus keluar terlebih dahulu untuk melakukan penyimpanan !\n");
            }
        }
        else if (WordEqual(command, muat)){
            if (isLogin){
                printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n\n");
            }
            else{

                STARTSENTENCE();
                printf("Masukkan nama folder yang hendak dimuat:");
                STARTSENTENCE();
                Word fileee = currentWord;

                printWord(currentWord);
                printf("\n\n");
                char path[MAXChar] = "../cfg/";
                char *fold = (char*)malloc(MAXChar*sizeof(char));
                char *path1 = (char*)malloc(MAXChar*sizeof(char));
                w2s(fold,currentWord);
                path1 = strcopy(path1,path);
                strconcat(path1,fold);
                strconcat(path1,"/");
                if (isDirExist(path1)){
                    CreateAccountList(&akun);
                    createEmptyGraf(&teman);
                    MakeEmptyprio(&Q, 100);
                    CreateEmptyStack(&draf);
                    CreateListKicau(&kList);
                    for (int i=0;i<5;i++){
                        if (i==0){ 
                            char file[20] = "pengguna.config";
                            char *folder = (char*)malloc(MAXChar*sizeof(char));
                            strcpy(folder,path1);
                            strcat(folder,file);
                            ReadUser_FILE(folder,&akun,&teman,&Q);
                            free(folder);
                        }
                        else if (i==1){ 
                            char file[20] = "kicauan.config";
                            char *folder = (char*)malloc(MAXChar*sizeof(char));
                            strcpy(folder,path1);
                            strcat(folder,file);
                            ReadKicau_FILE(folder,&kList);
                            free(folder);
                        } 
                        else if (i==2){ // Draft config
                            char file[20] = "draf.config";
                            char *folder = (char*)malloc(MAXChar*sizeof(char));
                            strcpy(folder,path1);
                            strcat(folder,file);
                            ReadDraf_FILE(folder, &akun, &draf);
                            int i;
                            for (i = 0; i < 20; i++)
                            {
                                CreateEmptyStack(&drafStack[i]);
                            }

                            while (!IsEmptyStack(draf))
                            {
                                drafkicau temp;
                                Pop(&draf, &temp);
                                for (i = 0; i < 20; i++)
                                {
                                    if (temp.IDuser == i)
                                    {
                                        Push(&drafStack[i], temp);
                                    }
                                }
                            }
                            free(folder);
                        }
                        else if (i==3){ // Utas config
                            char file[20] = "utas.config";
                            char *folder = (char*)malloc(MAXChar*sizeof(char));
                            strcpy(folder,path1);
                            strcat(folder,file);
                            readUtas(folder,&kList,&idUtas,akun);
                            free(folder);
                        }
                        else if (i==4){ //Reply config

                        }
                        
                    }
                printf("Anda akan melakukan pemuatan dari ");
                printWord(fileee);
                printf("\n\n");
            }
            else{
                printf("Tidak ada folder yang dimaksud!\n\n");
            }
            }
        }
        else
        {
            printf("Perintah tidak dikenali.\n");
        }
    }
    ADVCOMMAND();
    return 0;
}
void saveUtas(char filename[], ListKicau* kList, int jumlahUtas, AccountList akunList){
    FILE *configFile = fopen(filename, "w");
    fprintf(configFile,"%d",jumlahUtas);
    for (int i=0;i<kList->nEff;i++){
        if (kList->kicau[i].utasKicau!=NULL){
            fprintf(configFile,"\n%d\n",kList->kicau[i].id);
            kSambungAdd k = kList->kicau[i].utasKicau->content;
            int j = 1;
            while (k->next!=NULL)
            {
                j++;
                k = k->next;
            }
            fprintf(configFile,"%d",j);
            k = kList->kicau[i].utasKicau->content;
            for (int n=0;n<j;n++){
                fprintf(configFile,"\n%s\n",k->text);
                char str[MAXChar];
                wordToString(str,k->author);
                fprintf(configFile,"%s\n",str);
                fprintf(configFile, "%02d/%02d/%d %02d:%02d:%02d", k->datetime.DD, k->datetime.MM, k->datetime.YYYY, k->datetime.T.HH, k->datetime.T.MM, k->datetime.T.SS);
                k = k->next;
            }
            
        }
    }   
}

