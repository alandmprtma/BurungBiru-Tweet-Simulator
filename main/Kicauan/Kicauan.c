#include "../../modules/adt.h"
#include "../includeADT.h"

Word public = {"Publik", 6};

int GetAccountIndex(AccountList *list, Account account){
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

ListKicau CreateListKicau(ListKicau *list)
{
    list->nEff = 0;
    list->Cap = 100;
    list->kicau = (Kicau*) malloc(list->Cap * sizeof(Kicau));
    return *list;
}

int CreateIDKicau(ListKicau *list) {
    if (list->nEff == 0) 
    {
        return 1;
    } 
    else 
    {
        return list->kicau[list->nEff - 1].id + 1;
    }
}

void AddToKicauan(ListKicau *list, Kicau k) {

    list->kicau[list->nEff] = k;
    list->nEff++;
    
}

void CreateKicau(Account akunLogin, ListKicau *list, Kicau *k) {
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    DATETIME local;
    CreateDATETIME(&local, tm_struct->tm_mday, tm_struct->tm_mon + 1, tm_struct->tm_year + 1900, tm_struct->tm_hour, tm_struct->tm_min, tm_struct->tm_sec);

    //baca text kicauan
    int el = 0;
    printf("Masukkan kicauan:\n");
    START();
    while (currentChar=='\n' || currentChar=='\r')
    {
        ADV();
    }
    
    while (currentChar!=';')
    {
        if (el<MAXChar)
        {
            k->text[el] = currentChar;
            el++;
        }
        
        ADV();
    }
    k->text[el] = '\0';

    //baca tagar
    boolean space = true;
    while (space){
        el = 1;
        k->tagar[0] = '#';
        printf("Masukkan tagar:\n");
        START();
        while (currentChar=='\n' || currentChar=='\r')
        {
            ADV();
        }
        
        while (currentChar!=';')
        {
            if (el<MAXChar)
            {
                k->tagar[el] = currentChar;
                el++;
            }
            
            ADV();
        }
        k->tagar[el] = '\0';

        if (containsSpace(k->tagar))
        {
            space = true;
            printf("Tagar tidak boleh mengandung spasi!\n");
        }
        else
        {
            space = false;
        }
    }



    k->id = CreateIDKicau(list); 
    k->like = 0;
    CopyWordTo(&k->author,akunLogin.username[0]);
    k->datetime = local;
    k->utasKicau = NULL;
    k->balasan = NULL;
    printf("\n\nSelamat! Kicauan telah diterbitkan!\n Detil kicauan:\n");
    BaseDisplay(*k);
    AddToKicauan(list, *k);
}

void BaseDisplay (Kicau k)
{
    printf("\n| ID = %d\n", k.id);

    //print author (without length seperti di ADT)
    printf("| ");
    int i;
    for (i = 0; i < k.author.Length; i++) 
    {
        printf("%c", k.author.TabWord[i]);
    }
    printf("\n");

    //print time upload kicauan
    printf("| ");
    TulisDATETIME(k.datetime);
    printf("\n");

    //print text
    int j = 0;
    printf("| ");
    while (k.text[j] != '\0')
    {
        printf("%c", k.text[j]);
        j++;
    }
    //jika tagar tidak kosong, tampilkan tagar
    if (k.tagar[1] != '\0')
    {
        printf("\n| ");
        j = 0;
        while (k.tagar[j] != '\0')
        {
            printf("%c", k.tagar[j]);
            j++;
        }
    }
    //print likes
    printf("\n| Disukai: %d\n\n", k.like);
}

void Kicauan(Account akunLogin, ListKicau list) {
    int found = 0;
    for (int i = list.nEff - 1; i >= 0; i--) {
        // if (WordEqual(list.kicau[i].author, *akunLogin.username)) {
        BaseDisplay(list.kicau[i]);
        found = 1;
        // }
    }
    if (!found) {
        printf("Tidak ada kicauan oleh pengguna %s.\n", akunLogin.username[0].TabWord);
    }
}

int listLengthKicauan(ListKicau list)
{
    return list.nEff;
}

int idxOfKicauan(int id, ListKicau listKicau) {
    int i = 0;
    boolean found = false;
    while (!found && i < listLengthKicauan(listKicau)) {
        if (listKicau.kicau[i].id == id) {
            found = true;
        } else {
            i++;
        }
    }

    if (found) {
        return i;
    } else {
        return IDX_UNDEF_KICAUAN;
    }
}

void SukaKicau (Account akunLogin, Word id, ListKicau *listkicau, Kicau *k, AccountList* listakun, Graf teman)
{
    //Account ID user saat ini
    printWord(id);
    int id_user = GetAccountIndex(listakun, akunLogin);
    int id_int = WordToInt(id)-1;
    //Account ID username penulis kicauan yang ingin di-like
    int i = 0;
    boolean found = false;
    while (!found && i <= listkicau->nEff) {
        if (WordEqualAccount(listakun->accounts[i].username[0], listkicau->kicau[k->id-1].author)) {
            found = true;
        }
        i++;
    }
    int id_penulis = i-1;
    if (!found){
        printf("Kicauan tidak ditemukan\n");
        }
    if (id_int > listkicau->nEff)
    {
        printf("Tidak ditemukan kicauan dengan ID = %d;", id_int);
    }
    else
    {
        if (WordEqual(akunLogin.username[0],listakun->accounts[id_penulis].username[0]))
        {
            printf("Tidak bisa menyukai kicauan sendiri!\n");
        }
        else{
            //Jika dua akun berteman
            if(WordEqual(listakun->accounts[id_penulis].jenisAkun[0], public) || ELMTGRAF(teman, id_user, id_penulis))
            {
                listkicau->kicau[id_int].like += 1;
                printf("Selamat! kicauan telah disukai!\nDetil kicauan:");
                BaseDisplay(listkicau->kicau[id_int]);
            }
            else{
                printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
            }
        }
    }
}

boolean isIdInKicauan (int id, ListKicau *list)
{
    if (id > list->nEff)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < list->nEff; i++)
        {
            if (list->kicau[id].id == 0)
            {
                return false;
            }
        }
        return true;
    }
}

void UbahKicau (Account akunLogin, Word id, ListKicau *list) 
{   int id_int = WordToInt(id);
    if (!isIdInKicauan(id_int-1, list))
    {
        printf("Tidak ditemukan kicauan dengan ID = %d!", id_int);
    }
    else
    {
        if (!WordEqual(list->kicau[id_int-1].author, *akunLogin.username))
        {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", id_int);
        }
        else
        {
            printf("Masukkan kicauan baru:\n");
            START();
             while (currentChar=='\n' || currentChar=='\r')
            {
                ADV();
            }
            int el = 0;
            while (currentChar != ';')
            {
                if (el<MAXChar)
                {
                    list->kicau[id_int-1].text[el] = currentChar;
                    el++;
                }
                ADV();
            }
            list->kicau[id_int-1].text[el] = '\0';
            printf("Kicauan telah diubah!\nDetil kicauan:");
            BaseDisplay(list->kicau[id_int-1]);
        }
    }
}