#include "SimpanMuat.h"
#include <sys/stat.h>
#include <time.h>

void wordToString(char destination[MAXChar],Word input){
    int i;
    for (i=0;i<input.Length;i++){
        (destination[i]) = input.TabWord[i];
    }
    destination[i] = '\0';
}
void concatStrings(const char *str1, const char *str2, char *result) {
    int i = 0;
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }
    
    int j = 0;
    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }
    
    result[i] = '\0';
}
char* strcopy(char* destination, const char* source) {
    char* start = destination;

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // Null-terminate the destination string
    return start;
}

// Function to concatenate two strings using strcat
char* strconcat(char* destination, const char* source) {
    char* start = destination;

    while (*destination != '\0') {
        destination++;
    }

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0'; // Null-terminate the concatenated string
    return start;
}
void muat(char folderName[],AccountList *listakun, Graf *Teman, prioqueuefren *Q,ListKicau * kList, Stack* draf, int* jumlahUtas){
    char path[] = "../cfg/";
    char *folder= (char *)malloc(strlen(path) + strlen(folderName) + 1);
    strcpy(folder,path);
    strcat(folder,folderName);
    if (!isDirExist(folder)){
        printf("Tidak ada folder yang dimaksud!\n");
    }else{
        printf("%s\n",folder);
        for (int i=0;i<5;i++){
            if (i==0){ 
                ReadUser_FILE(path,listakun,Teman,Q);
            }
            else if (i==1){ 
                ReadKicau_FILE(path,kList);
            } 
            else if (i==2){ // Draft config
                ReadDraf_FILE(path,listakun,draf);
            }
            else if (i==3){ // Utas config
                readUtas(path,kList,jumlahUtas,*listakun);
            }
            else if (i==4){ //Reply config

            }
        }
    }
}

// void simpan(char folderName[]){
//     // concat path to cfg folder
//     char path[]= "../cfg/";
//     if (!isDirExist(concatStr(path,folderName))){
//         printf("Belum terdapat Folder1.\nAkan dilakukan pembuatan Folder1 terlebih dahulu.\n");
//         printf("Mohon tunggu...\n1...\n2...\n3...\n%s sudah berhasil dibuat.\n",folderName);
//     }
//     for (int i= 0;i<5;i++){
//         if (i==0){ // User config

//         }
//         else if (i==1){ // Tweet config

//         } 
//         else if (i==2){ // Reply config

//         }
//         else if (i==3){ // Draft config

//         }
//         else if (i==4){ //Utas config
            
//         }
  
//     }
// }

boolean isDirExist(char path[]){
    struct stat stats;
    stat(path, &stats);

    if (S_ISDIR(stats.st_mode)){
        return true;
    }
    return false;
}
// void concatStr(char* path,char folder[]){
//     int i;
//     for (i=0;path[i]!='\0';i++);
//     for (int j=0;folder[j]!='\0';j++){
//         path[i] = folder[j];
//         i++;
//     }
//     path[i] = '\0';
//     strcat
// }
// // Load
void ReadUser_FILE(char filename[], AccountList *list, Graf *Teman, prioqueuefren *Q){
    int N;
    STARTWORD_FILE(filename);
    //Akuisisi Nilai N
    N = WordToInt(currentWord);
    ADVSENTENCE();
    int i,j;
    for (i = 0; i < N; i++)
    {
        Word username, password, bio, noHP, weton, jenisakun;
        Matrix profil;
        Account akun;
        CreateAccountEmpty(&akun);
        int j = 0;
        int batas = 11;
        while (j < batas)
        {
            if (currentChar == '\n' && j == 0)
            {
                CopyWordTo(Username(akun), currentWord);
                j++;
            }
            else if (currentChar == '\n' && j == 1)
            {
                CopyWordTo(Password(akun), currentWord);
                j++;
            }
            else if (currentChar == '\n' && j == 2)
            {
                if (WordEqual(*Password(akun),currentWord))
                {
                    CopyWordTo(Bio(akun), emptyWord);
                }
                else
                {
                    CopyWordTo(Bio(akun), currentWord);
                }
                j++;
            }
            else if (currentChar == '\n' && j == 3)
            {
                if (WordEqual(*Bio(akun), currentWord) || WordEqual(*Password(akun),currentWord))
                {
                    CopyWordTo(NoHP(akun), emptyWord);
                }
                else
                {
                    CopyWordTo(NoHP(akun), currentWord);
                }
                j++;
            }
            else if (currentChar == '\n' && j == 4)
            {
                if (WordEqual(*Bio(akun), currentWord) || WordEqual(*Password(akun),currentWord) || WordEqual(*NoHP(akun), currentWord))
                {
                    CopyWordTo(Weton(akun), emptyWord);
                }
                else{
                    CopyWordTo(Weton(akun), currentWord);
                }
                j++;
            }
            else if (currentChar == '\n' && j == 5)
            {
                CopyWordTo(JenisAkun(akun), currentWord);
                j++;
            }
            else if (currentChar == '\n' && j > 5 && j < 11)
            {
                //Foto Profil pengguna.config disini
                createMatrixchar(5, 10, &akun.fotoprofil);
                int k;
                for(k = 0; k < 10; k++){
                    ELMTChar(akun.fotoprofil,j-6,k) = currentWord.TabWord[k*2];
                }
                j++;
            }
            currentWord = emptyWord;
            ADVSENTENCE();
        }
        AddAccountToList(list, akun);
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            ELMTGRAF(*Teman,i,j) = CharToInt(currentWord.TabWord[j*2]);
        }
        ADVSENTENCE();
    }
    int countQ = WordToInt(currentWord);
    if(countQ != 0)
    {
        for(i = 0; i < countQ-1; i++){
            ADVSENTENCE();
            teman temp;
            for(j = 0; j < 3; j++){
                if(j == 0){
                    temp.IDpengirim = CharToInt(currentWord.TabWord[j*2]);
                }
                if(j == 1){
                    temp.IDpenerima = CharToInt(currentWord.TabWord[j*2]);
                }
                if(j == 2){
                    temp.Jumlahteman = CharToInt(currentWord.TabWord[j*2]);
                }
            }
            Enqueueprio(Q, temp);
        }
        i = 0;
        teman temp;
        while (i < 5){
            ADV();
            if(i == 0){
                temp.IDpengirim = CharToInt(currentChar);
            }
            else if(i == 2){
                temp.IDpenerima = CharToInt(currentChar);
            }
            else if (i == 4){
                temp.Jumlahteman = CharToInt(currentChar);
            }
            i++;
        }
        Enqueueprio(Q, temp);
    }
}

void ReadKicau_FILE(char filename[], ListKicau * kList){
    currentWord = emptyWord;
    STARTWORD_FILE(filename);
    int n = WordToInt(currentWord);
    int i;
    for(i = 0; i < n ; i++){
        Kicau temp; 
        currentWord = emptyWord;
        ADVSENTENCE();
        int id = WordToInt(currentWord);
        temp.id = id;
        ADVSENTENCE();
        w2s(temp.text ,currentWord);
        ADVSENTENCE();
        w2s(temp.tagar,currentWord);
        ADVSENTENCE();
        temp.like = WordToInt(currentWord);
        ADVSENTENCE();
        temp.author = emptyWord;
        CopyWordTo(&temp.author, currentWord);
        if (i != n-1){
            ADVSENTENCE();
        }
        else{
            currentWord = emptyWord;
            ADV();
            int m;
            for(m = 0; m < 19; m++){
                currentWord.TabWord[m] = currentChar;
                currentWord.Length++;
                ADV();
            }
        }
        DATETIME waktukicau;
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
        CreateDATETIME(&waktukicau, DD, MM, YY, HH, M, SS);
        temp.datetime = waktukicau;
        temp.utasKicau = NULL;
        AddToKicauan(kList, temp);
    }
}

void readUtas(char filename[], ListKicau* kList, int* jumlahUtas, AccountList akunList){
    currentWord = emptyWord;
    STARTWORD_FILE(filename);
    int n = WordToInt(currentWord);
    for (int i=0;i<n;i++){
        ADVSENTENCE();
        int id = WordToInt(currentWord);
        int l;
        Word user;
        for (l = 0;l<kList->nEff && id!=kList->kicau[l].id;l++);
        CopyWordTo(&user,kList->kicau[l].author);
        int k;
        for (k=0;k<akunList.count && !WordEqual(user,akunList.accounts[k].username[0]);k++);
        Account akun = akunList.accounts[k];
        currentWord = emptyWord;
        ADVSENTENCE();
        int jumlah = WordToInt(currentWord);
        for (int j=0;j<jumlah;j++){
            ADVSENTENCE();
            kSambungAdd ksam = createKicauanSambung(currentWord,akun);
            ADVSENTENCE();
            ADVSENTENCE();
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
            DATETIME date;
            CreateDATETIME(&date, DD, MM, YY, HH, M, SS);
            ksam->datetime = date;

            kSambungAdd kPrev;
            if (kList->kicau[l].utasKicau==NULL){
                Utas* u = (Utas*)malloc(sizeof(Utas));
                *jumlahUtas += 1;
                u->IDUtas = *jumlahUtas;
                kList->kicau[l].utasKicau = u;
                kList->kicau[l].utasKicau->content = ksam;
            }else{
                kPrev = kList->kicau[l].utasKicau->content;
                while (kPrev->next!=NULL)
                {
                    kPrev = kPrev->next;
                }
                kPrev->next = ksam;
            }
        }
    }
}
// void ReadDraf_FILE(char filename[], AccountList *list, Stack *S){
// /*Membaca file Draf dari Draf.config kedalam program
//     I.S. Stack terdefinisi dan AccountList sudah diakuisisi dari user.config
//     F.S. Stack terisi dengan drafkicauan dari Draf.Config
//     */
//     int N;
//     STARTWORD_FILE(filename);
//     N = WordToInt(currentWord);
//     int i;
//     for(i = 0; i < N; i++)
//     {
//         ADVSENTENCE();
//         Word user;
//         int jumlah;
//         int j;
//         CopyWordTo(&user, currentWord);
//         user.Length = user.Length - 2;
//         int idAkun;
//         int i = 0;
//         boolean found = false;
//         while(i < list->count && found == false)
//         {
//             if(WordEqual(*list->accounts[i].username, user))
//             {
//                 idAkun = i;
//                 found = true;
//             }
//             i++; 
//         }
//         jumlah = CharToInt(currentWord.TabWord[currentWord.Length-1]);
//         for(j = 0; j < jumlah; j++)
//         {
//             drafkicau DrafKicau;
//             DATETIME waktudraf;
//             ADVSENTENCE();
//             Word draf = currentWord;
//             ADVSENTENCE();
//             int k;
//             Word dd;
//             for(k = 0; k < 2; k++){
//                 dd.TabWord[k] = currentWord.TabWord[k];
//             }
//             dd.Length = 2;
//             int DD = WordToInt(dd);
//             Word mm;
//             for(k = 3; k < 5; k++){
//                 mm.TabWord[k-3] = currentWord.TabWord[k];
//             }
//             mm.Length = 2;
//             int MM = WordToInt(mm);
//             Word yy;
//             for(k = 6; k < 10; k++){
//                 yy.TabWord[k-6] = currentWord.TabWord[k];
//             }
//             yy.Length = 4;
//             int YY = WordToInt(yy);
//             Word hh;
//             for(k = 11; k < 13; k++){
//                 hh.TabWord[k-11] = currentWord.TabWord[k];
//             }
//             hh.Length = 2;
//             int HH = WordToInt(hh);
//             Word m;
//             for(k = 14; k < 16; k++){
//                 m.TabWord[k-14] = currentWord.TabWord[k];
//             }
//             m.Length = 2;
//             int M = WordToInt(m);
//             Word ss;
//             for(k = 17; k < 19; k++){
//                 ss.TabWord[k-17] = currentWord.TabWord[k];
//             }
//             ss.Length = 2;
//             int SS = WordToInt(ss);
//             CreateDATETIME(&waktudraf, DD, MM, YY, HH, M, SS);
//             DrafKicau.Draf = draf;
//             DrafKicau.IDuser = idAkun;
//             DrafKicau.waktu = waktudraf;
//             Push(S, DrafKicau);
//         }
//     }
// }
// ///////////////////////////////////////////////////////////////////////////////////////////
void saveKicau_FILE(char filename[], ListKicau kList){
    FILE *file = fopen(filename, "w");
    if (file == NULL){
        fprintf(stderr, "Error opening file.\n");
    }
    int N = kList.nEff;
    fprintf(file, "%d\n", N);
    int i;
    for(i = 0; i < N; i++){
        fprintf(file, "%d\n", kList.kicau[i].id);
        fprintf(file, "%s\n", kList.kicau[i].text);
        fprintf(file, "%s\n", kList.kicau[i].tagar);
        fprintf(file, "%d\n", kList.kicau[i].like);
        int j;
        for(j = 0; j < kList.kicau[i].author.Length; j++){
            fprintf(file, "%c", kList.kicau[i].author.TabWord[j]);
        }
        fprintf(file, "\n");
        if (i == N-1){
            fprintf(file, "%02d/%02d/%d %02d:%02d:%02d", kList.kicau[i].datetime.DD, kList.kicau[i].datetime.MM, kList.kicau[i].datetime.YYYY, kList.kicau[i].datetime.T.HH, kList.kicau[i].datetime.T.MM, kList.kicau[i].datetime.T.SS);
        }
        else{
            fprintf(file, "%02d/%02d/%d %02d:%02d:%02d\n", kList.kicau[i].datetime.DD, kList.kicau[i].datetime.MM, kList.kicau[i].datetime.YYYY, kList.kicau[i].datetime.T.HH, kList.kicau[i].datetime.T.MM, kList.kicau[i].datetime.T.SS);
        }
    }
    fclose(file);
}
// }
void SaveUser_FILE(char filename[], AccountList *list, Graf Teman, prioqueuefren Q)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL){
        fprintf(stderr, "Error opening file.\n");
    }
    fprintf(file, "%d\n", list->count);
    int i;
    for (i = 0; i < list->count; i++)
    {   
        char str[MAXChar];
        wordToString(str,list->accounts[i].username[0]);
        fprintf(file, "%s\n", str);
        wordToString(str,list->accounts[i].password[0]);
        fprintf(file, "%s\n",str);
        wordToString(str,list->accounts[i].bio[0]);
        fprintf(file, "%s\n", str);
        wordToString(str,list->accounts[i].noHP[0]);
        fprintf(file, "%s\n", str);
        wordToString(str,list->accounts[i].weton[0]);
        fprintf(file, "%s\n", str);
        wordToString(str,list->accounts[i].jenisAkun[0]);
        fprintf(file, "%s\n", str);
        int j;
        for(j = 0; j < 5; j++){
            int k;
            for(k = 0; k < 10; k++){
                fprintf(file, "%c", ELMTChar(list->accounts[i].fotoprofil,j,k));
                if (k != 9){
                    fprintf(file, " ");
                }
            }
            if (j != 4){
                fprintf(file, "\n");
            }
        }
        fprintf(file, "\n");
    }
    for (i = 0; i < list->count; i++){
        int j;
        for (j = 0; j < list->count; j++){
            fprintf(file, "%d", ELMTGRAF(Teman, i, j));
            if (j != list->count - 1){
                fprintf(file, " ");
            }
        }
        if (i != list->count - 1){
            fprintf(file, "\n");
        }
    }
    fprintf(file, "\n");
    fprintf(file, "%d\n", NBElmtPrio(Q));
    int count = NBElmtPrio(Q);
    for (i = 0; i < count; i++)
    {
        teman temp;
        Dequeueprio(&Q, &temp);
        if (i == count-1){
            fprintf(file, "%d %d %d", temp.IDpengirim, temp.IDpenerima, temp.Jumlahteman);
        }
        else{
            fprintf(file, "%d %d %d\n", temp.IDpengirim, temp.IDpenerima, temp.Jumlahteman);
        }
    }
    fclose(file);
}
void SaveDraf_FILE(char filename[], AccountList *list, Stack S[]){
/*Menyimpan file Draf dari program kedalam Draf.config
    I.S. Stack terdefinisi dan AccountList sudah diakuisisi dari user.config
    F.S. Stack terisi dengan drafkicauan dari Draf.Config
    */
    FILE *file = fopen(filename, "w");

    if (file == NULL){
        fprintf(stderr, "Error opening file.\n");
    }
    int i;
    int countdraf = 0;
    for(i = 0; i < 20; i++){
        if(!IsEmptyStack(S[i])){
            countdraf++;
        }
    }
    fprintf(file, "%d\n", countdraf);
    int count = 0;
    for(i = 0; i < 20; i++){
        if(!IsEmptyStack(S[i])){
            count++;
            fprintf(file, "%s %d\n", list->accounts[i].username->TabWord, NbElmtStack(S[i]));
            int j;
            int N = NbElmtStack(S[i]);
            for(j = 0; j < N; j++){
                drafkicau temp;
                Pop(&S[i], &temp);
                char str[281];
                wordToString(str,temp.Draf);
                fprintf(file, "%s\n", str);
                if (count == countdraf && j == N-1){
                    fprintf(file, "%02d/%02d/%d %02d:%02d:%02d", temp.waktu.DD, temp.waktu.MM, temp.waktu.YYYY, temp.waktu.T.HH, temp.waktu.T.MM, temp.waktu.T.SS);
                }
                else{
                    fprintf(file, "%02d/%02d/%d %02d:%02d:%02d\n", temp.waktu.DD, temp.waktu.MM, temp.waktu.YYYY, temp.waktu.T.HH, temp.waktu.T.MM, temp.waktu.T.SS);
                }
            }
        }
    }
    fclose(file);
}
