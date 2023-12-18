#include "Pengguna.h"

Word emptyWord = {{'\0', 0}};
Word privat = {"Privat", 6};
Word publik = {"Publik", 6};

Word yes = {"ya", 2};
Word no = {"tidak", 5};

Word wetonJawa[] = {
        {"pon", 3},
        {"wage", 4},
        {"kliwon", 6},
        {"legi", 4},
        {"pahing", 6}
    };

MatrixChar default_foto(){
    MatrixChar mc;
    createMatrixchar(5, 10, &mc);
    int i, j;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 10; j++){
            if( j % 2 == 0){
                ELMTChar(mc, i, j) = 'R';
            }
            else{
                ELMTChar(mc, i, j) = '*';
            }
        }
    }
    return mc;
}

void inUser(Account *account, Word username){
    *Username(*account) = emptyWord;
    CopyWordTo(Username(*account), username);
}
void outUser(Account *account){
    *Username(*account) = emptyWord;
}

void CreateAccount(Account *account, Word username, Word password){
    CopyWordTo(Username(*account), username);
    CopyWordTo(Password(*account), password);
    CopyWordTo(Bio(*account), emptyWord);
    CopyWordTo(NoHP(*account), emptyWord);
    CopyWordTo(Weton(*account), emptyWord);
    CopyWordTo(JenisAkun(*account), publik);
    copyMatrixChar(default_foto(), &FotoProfil(*account));
}

void signup(AccountList *listakun){
    Account akun;
    STARTSENTENCE();
    printf("Masukkan nama: ");
    STARTSENTENCE();
    Word attemptUsername = currentWord;
    while(attemptUsername.Length > 20){
        STARTSENTENCE();
        printf("Nama terlalu panjang, masukkan maksimal 20 karakter!\n");
        printf("Masukkan nama: ");
        STARTSENTENCE();
        attemptUsername = currentWord;
    }
    
    while(IsUsernameInAccountList(listakun, attemptUsername)){
        STARTSENTENCE();
        printf("Nama tersebut sudah terdaftar, masukkan nama lain!\n");
        printf("Masukkan nama: ");
        STARTSENTENCE();
        attemptUsername = currentWord;
    }

    ADVSENTENCE();
    STARTSENTENCE();
    printf("Masukkan kata sandi: ");
    STARTSENTENCE();
    Word attemptPassword = currentWord;
    while(attemptPassword.Length > 20){
        STARTSENTENCE();
        printf("Kata sandi terlalu panjang, masukkan maksimal 20 karakter!\n");
        printf("Masukkan kata sandi: ");
        STARTSENTENCE();
        attemptPassword = currentWord;
    }

    ADVSENTENCE();
    CreateAccount(&akun, attemptUsername, attemptPassword);
    AddAccountToList(listakun, akun);
    printf("\nAkun berhasil ditambahkan ke daftar pengguna. Silahkan masuk untuk menikmati fitur Burbir.\n");
}

void signin(AccountList *akun, Account *akunLogin){
    if(isEmptyAccountList(akun)){
        printf("Tidak ada akun terdaftar.\n\n");
    }
    else{
        STARTSENTENCE();
        printf("Masukkan nama: ");
        STARTSENTENCE();
        Word attemptUsername = currentWord;
        while(attemptUsername.Length > 20){
            STARTSENTENCE();
            printf("Nama terlalu panjang, masukkan maksimal 20 karakter!\n");
            printf("Masukkan nama: ");
            STARTSENTENCE();
            attemptUsername = currentWord;
        }
        while(!IsUsernameInAccountList(akun, attemptUsername)){
            STARTSENTENCE();
            printf("Tidak ada akun dengan nama tersebut, silahkan masukkan nama lain.\n");
            printf("Masukkan nama: ");
            STARTSENTENCE();
            attemptUsername = currentWord;
        }
        ADVSENTENCE();

        STARTSENTENCE();
        printf("Masukkan kata sandi: ");
        STARTSENTENCE();
        Word attemptPassword = currentWord;
        while(attemptPassword.Length > 20){
            STARTSENTENCE();
            printf("Kata sandi terlalu panjang, masukkan maksimal 20 karakter!\n");
            printf("Masukkan kata sandi: ");
            STARTSENTENCE();
            attemptPassword = currentWord;
        }
        while(!cekPassword(akun, attemptUsername, attemptPassword)){
            STARTSENTENCE();
            printf("Kata sandi salah, coba lagi.\n");
            printf("Masukkan kata sandi: ");
            STARTSENTENCE();
            attemptPassword = currentWord;
        }
        ADVSENTENCE();
        inUser(akunLogin, attemptUsername);
        printf("Selamat datang, ");
        printWord(attemptUsername);
        printf("!\n\n");
    }
}

boolean isEmptyAccountList(AccountList *list){
    return list->count == 0;
}

void CreateAccountEmpty(Account *account) {
    *Username(*account) = emptyWord;
    *Password(*account) = emptyWord;
    *Bio(*account) = emptyWord;
    *NoHP(*account) = emptyWord;
    *Weton(*account) = emptyWord;
    *JenisAkun(*account) = emptyWord;
}

void CreateAccountList(AccountList *list) {
    list->count = 0;
}

void AddAccountToList(AccountList *list, Account account){
    list->accounts[list->count] = account;
    list->count++;
}

void DisplayAccounts(AccountList *list){
    if (list->count == 0) {
        printf("Tidak ada akun dalam list.\n\n");
    } else {
        int i;
        for (i = 0; i < list->count; i++) {
            printf("Akun %d:\n", i + 1);
            printf("Username: %s\n", list->accounts[i].username[0].TabWord);
            printf("Password: %s\n", list->accounts[i].password[0].TabWord);
            printf("Bio Akun: %s\n", list->accounts[i].bio[0].TabWord);
            printf("No HP: %s\n", list->accounts[i].noHP[0].TabWord);
            printf("Weton: %s\n", list->accounts[i].weton[0].TabWord);
            printf("Jenis Akun: %s\n\n", list->accounts[i].jenisAkun[0].TabWord);
            printf("Foto Profil:\n");
            colorizedProfil(list->accounts[i].fotoprofil);
            printf("\n");
        }
    }
}

boolean IsAccountListFull(AccountList *list){
    return list->count >= MAX_ACCOUNTS;
}

boolean WordEqualAccount(Word a, Word b) {
    if (a.Length != b.Length) {
        return false;
    } else {
        int n = a.Length;

        boolean equal = true;
        int i = 0;
        while (equal && (i < n)) {
            if ((a.TabWord[i] != b.TabWord[i])) {
                equal = false;
            } else {
                i += 1;
            }
        }

        return equal;
    }
}

boolean IsUsernameInAccountList(AccountList *list, Word username) {
    int i = 0;
    boolean found = false;
    while (!found && i < list->count) {
        if (WordEqualAccount(*list->accounts[i].username, username)) {
            found = true;
        }
        i++;
    }
    return found;
}

int GetAccountIdx(AccountList *list, Account account){
    int i = 0;
    boolean found = false;
    while (!found && i < list->count) {
        if (WordEqualAccount(*list->accounts[i].username, *Username(account))) {
            found = true;
        }
        i++;
    }
    return i-1;
}

boolean cekPassword(AccountList *list, Word username, Word password){
    int i = 0;
    boolean found = false;
    while (!found && i < list->count) {
        if (WordEqualAccount(*list->accounts[i].username, username) && WordEqualAccount(*list->accounts[i].password, password)) {
            found = true;
        }
        i++;
    }
    return found;
}


boolean isPhoneNumberValid(const Word phoneNumber) {
    for (int i = 0; i < phoneNumber.Length; i++) {
        char c = phoneNumber.TabWord[i];
        if (!((c >= '0' && c <= '9') || c == '+' || c == '-')) {
            return false;
        }
    }
    return true;
}

boolean isWetonJawa(Word word) {
    int i;
    for (i = 0; i < sizeof(wetonJawa) / sizeof(wetonJawa[0]); i++) {
        if (word.Length == wetonJawa[i].Length) {
            int j;
            boolean match = true;
            for (j = 0; j < word.Length; j++) {
                if (word.TabWord[j] != wetonJawa[i].TabWord[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;
            }
        }
    }
    return false;
}

Word toLowerCase(Word word) {
    Word result;
    int length = word.Length;
    result.Length = length;

    for (int i = 0; i < length; i++) {
        if (word.TabWord[i] >= 'A' && word.TabWord[i] <= 'Z') {
            result.TabWord[i] = word.TabWord[i] + 32;
        } else {
            result.TabWord[i] = word.TabWord[i];
        }
    }
    return result;
}

void edit_profile(AccountList *list, Account user){
    currentWord = emptyWord;
    printf("| Nama: %s\n", list->accounts[GetAccountIdx(list, user)].username->TabWord);
    printf("| Bio Akun: %s\n", list->accounts[GetAccountIdx(list, user)].bio->TabWord);
    printf("| No HP: %s\n", list->accounts[GetAccountIdx(list, user)].noHP->TabWord);
    printf("| Weton: %s\n\n", list->accounts[GetAccountIdx(list, user)].weton->TabWord);
    
    STARTSENTENCE();
    printf("Masukkan Bio Akun: ");
    STARTSENTENCE();
    Word attemptBio = currentWord;
    while(attemptBio.Length > 135){
        STARTSENTENCE();
        printf("Bio akun terlalu panjang, masukkan maksimal 135 karakter!\n");
        printf("Masukkan Bio Akun: ");
        STARTSENTENCE();
        attemptBio = currentWord;
    }

    if (!WordEqual(attemptBio, emptyWord)){
        CopyWordTo(list->accounts[GetAccountIdx(list, user)].bio, attemptBio);
    }
    currentWord = emptyWord;
    ADVSENTENCE();
    STARTSENTENCE();
    printf("Masukkan No HP: ");
    STARTSENTENCE();
    Word attemptNoHP = currentWord;
    if (!WordEqual(attemptNoHP, emptyWord)){
        while(attemptNoHP.Length > 20 || !isPhoneNumberValid(currentWord)){
            STARTSENTENCE();
            printf("No HP tidak valid, masukkan No HP yang valid!\n");
            printf("Masukkan No HP: ");
            STARTSENTENCE();
            attemptNoHP = currentWord;
        }
        CopyWordTo(list->accounts[GetAccountIdx(list, user)].noHP, attemptNoHP);
    }
    currentWord = emptyWord;
    ADVSENTENCE();
    STARTSENTENCE();
    printf("Masukkan Weton: ");
    STARTSENTENCE();
    Word attemptWeton = currentWord;
    if (!WordEqual(attemptWeton, emptyWord)){
        while(attemptWeton.Length > 20 || !isWetonJawa(toLowerCase(attemptWeton))){
            STARTSENTENCE();
            printf("Weton tidak valid, masukkan Weton yang valid!\n");
            printf("Masukkan Weton: ");
            STARTSENTENCE();
            attemptWeton = currentWord;
        }
        ADVSENTENCE();

        if (!WordEqual(attemptWeton, emptyWord)){
            CopyWordTo(list->accounts[GetAccountIdx(list, user)].weton, attemptWeton);
        }
    }
    printf("Akun anda berasil diperbaharui!\n\n");
}

void ganti_jenis_akun(AccountList *list, Account user){
    if(WordEqualAccount(*list->accounts[GetAccountIdx(list, user)].jenisAkun, publik)){
        currentWord = emptyWord;
        STARTSENTENCE();
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK): ");
        STARTSENTENCE();
        Word attemptJenis = currentWord;
        while(!(WordEqual(toLowerCase(attemptJenis), yes) || WordEqual(toLowerCase(attemptJenis), no))){
            STARTSENTENCE();
            printf("Input tidak valid!\n");
            printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat? (YA/TIDAK): ");
            STARTSENTENCE();
            attemptJenis = currentWord;
            printWord(attemptJenis);
        }
        ADVSENTENCE();
        if(WordEqual(toLowerCase(attemptJenis), yes)){
            CopyWordTo(list->accounts[GetAccountIdx(list, user)].jenisAkun, privat);
            printf("Akun anda sudah diubah menjadi akun Privat.\n\n");
        }
        else{
            printf("Akun anda tetap akun Publik.\n\n");
        }
    }
    else{
        currentWord = emptyWord;
        STARTSENTENCE();
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK): ");
        STARTSENTENCE();
        Word attemptJenis = currentWord;
        while(!(WordEqual(toLowerCase(attemptJenis), yes) || WordEqual(toLowerCase(attemptJenis), no))){
            STARTSENTENCE();
            printf("Input tidak valid!\n");
            printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik? (YA/TIDAK): ");
            STARTSENTENCE();
            attemptJenis = currentWord;
        }
        ADVSENTENCE();

        if(WordEqual(toLowerCase(attemptJenis), yes)){
            CopyWordTo(list->accounts[GetAccountIdx(list, user)].jenisAkun, publik);
            printf("Akun anda sudah diubah menjadi akun Publik.\n\n");
        }
        else{
            printf("Akun anda tetap akun Privat.\n\n");
        }
    }
}

void colorizedProfil(MatrixChar mc){
    int i, j;
    for (i = 0; i < ROW_EFFChar(mc); i++){
        for (j = 0; j < COL_EFFChar(mc) - 1; j++){
            if(ELMTChar(mc, i, j) == 'R'){
                print_red(ELMTChar(mc, i, j + 1));
            }
            else if(ELMTChar(mc, i, j) == 'G'){
                print_green(ELMTChar(mc, i, j + 1));
            }
            else if(ELMTChar(mc, i, j) == 'B'){
                print_blue(ELMTChar(mc, i, j + 1));
            }
        }
        printf("\n");
    }
}

void edit_foto(AccountList *list, Account user){
    printf("Foto Profil:\n");
    colorizedProfil(list->accounts[GetAccountIdx(list, user)].fotoprofil);
    printf("Masukkan foto profil baru:\n");
    int i, j;
    STARTSENTENCE();
    ADVSENTENCE();
    for (i = 0; i < ROW_EFFChar(list->accounts[GetAccountIdx(list, user)].fotoprofil); i++){
        for (j = 0; j < COL_EFFChar(list->accounts[GetAccountIdx(list, user)].fotoprofil); j++){
            ELMTChar(list->accounts[GetAccountIdx(list, user)].fotoprofil,i,j) = currentWord.TabWord[j*2];
        }
        ADVSENTENCE();
    }
    printf("Foto profil berhasil diubah!\n\n");
}

void show_profile(AccountList *l, Word username){
    int i = 0;
    boolean found = false;
    while (!found && i < l->count) {
        if (WordEqualAccount(*l->accounts[i].username, username)) {
            found = true;
        }
        i++;
    }
    if(found){
        printf("| Nama: %s\n", l->accounts[i-1].username->TabWord);
        printf("| Bio Akun: %s\n", l->accounts[i-1].bio->TabWord);
        printf("| No HP: %s\n", l->accounts[i-1].noHP->TabWord);
        printf("| Weton: %s\n", l->accounts[i-1].weton->TabWord);
        printf("| Jenis Akun: %s\n\n", l->accounts[i-1].jenisAkun->TabWord);
        printf("| Foto Profil:\n");
        colorizedProfil(l->accounts[i-1].fotoprofil);
        printf("\n");
    }
    else{
        printf("Username tidak ditemukan.\n\n");
    }
}


void PrintPrioQueue (prioqueuefren Q, AccountList * listakun)
{
    if(IsEmptyPrio(Q))
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
    else{
        int count = NBElmtPrio(Q);
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", count);
        printf("\n");
        int i = HeadQ(Q);
        while (i != TailQ(Q)+1){
            teman temp = Q.T[i];
            printf("| ");
            printWord(*listakun->accounts[temp.IDpengirim].username);
            printf("\n");
            printf("| Jumlah teman: %d\n\n", temp.Jumlahteman);
            i = (i + 1) % MaxElQ(Q);
        }
    }
}

void PrintTopPrioQueueChar (prioqueuefren Q, int IDuser, AccountList * listakun, int *idteman)
{
    if(IsEmptyPrio(Q))
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
    else{
        teman temp;
        printf("Permintaan pertemanan teratas dari ");
        printWord(*listakun->accounts[IDuser].username);
        printf("\n\n");
        int i = HeadQ(Q);
        temp = Q.T[i];
        printf("| ");
        printWord(*listakun->accounts[temp.IDpengirim].username);
        printf("\n");
        printf("| Jumlah teman: %d\n\n", temp.Jumlahteman);
        *idteman = temp.IDpengirim;
    }
}

void w2s(char (destination[MAXChar]),Word input){
    int i;
    for (i=0;i<input.Length;i++){
        (destination[i]) = input.TabWord[i];
    }
    (destination[i]) = '\0';
}