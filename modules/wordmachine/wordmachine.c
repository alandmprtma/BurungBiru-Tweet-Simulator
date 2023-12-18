#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks() { 
    /* Mengabaikan satu atau beberapa BLANK
    I.S. : currentChar sembarang
    F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar == BLANK) {
        ADV();
    }
}

void IgnoreNewLine() {
    if (currentChar == '\n' || currentChar=='\r')
    {
        ADV();
    }
}

void STARTWORD() { 
    /* I.S. : currentChar sembarang
    F.S. : EndWord = true, dan currentChar = MARK;
            atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }

}

void ADVWORD() { 
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWord();
        IgnoreBlanks();
    }
}

void ADVSENTENCE() { 
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
    F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, EndWord = true.
    Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == MARKBaris || currentChar == MARK || currentChar=='\r') {
        EndWord = true;
    } else {
        CopyWordSpace();
    }
}
void ADVSENTENCENL(){
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == MARKBaris || currentChar == MARK) {
        currentWord.Length = 0;
        EndWord = true;
    } else {
        CopyWordSpace();
    } 
}

void CopyWord() { 
    /* Mengakuisisi kata, menyimpan dalam currentWord
    I.S. : currentChar adalah karakter pertama dari kata
    F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i = 0;
    while ((currentChar != MARK) && (currentChar != BLANK)) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i < NMax) {
        currentWord.Length = i;
    } else {
        currentWord.Length = NMax;
    }
}

void CopyWordSpace()
/*Mengakuisisi kata, dengan enter atau NewLine sebagai MARK*/
{
    int i = 0;
    while (currentChar != MARKBaris && currentChar != MARK && currentChar!='\r' && i<NMax-1){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax){
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
    EndWord = true;
}

void printWord(Word w) 
{
    int i;
    for (i = 0; i < w.Length; i++) {
        printf("%c", w.TabWord[i]);
    }
    //printf("\n");
    //printf("%d\n", w.Length);
}

void STARTSENTENCE()
/* I.S. : currentChar sembarang
   F.S. : Mengakuisisi kata dengan pembatas NEWLINE terhadap kata berikutnya*/
{
   START();
   if (currentChar == MARKBaris || currentChar == MARK){
      EndWord = true;
   }
   else{
      EndWord = false;
      CopyWordSpace();
   }
}

void STARTWORD_FILE(char filename[])
/*Pita dari file eksternal siap dibaca oleh mesin kata. MARKFile merupakan NULL atau \0 dimana EndWord akan (menyala) bernilai TRUE saat
    Pita menyentuh NULL atau \0.*/
{
    STARTFILE(filename);
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == MARK || currentChar == MARKBaris || currentChar=='\r'){
        EndWord = true;
    }
    else{
        EndWord = false;
        ADVSENTENCE();
    }
}

boolean WordEqual(Word a, Word b) 
/*Mengirimkan true apabila Word a dan Word b identik.*/
{
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

boolean isWordIntegerFromIndex(Word word, unsigned int index){
    boolean cek = true;
    if (index >= word.Length) {
        return false;
    }

    for (unsigned int i = index; i < word.Length; i++){
        if (word.TabWord[i] < '0' || word.TabWord[i] > '9'){
            cek = false;
            break;
        }
    }
    return cek;
}

int WordToInt(Word string)
/*I.S. Kata yang telah diakuisi berisi string bilangan [0..9].
   F.S. Mengembalikan nilai integer dari kata yang diakuisisi.*/
{
    int hasil = 0;
    int i;
    for (i=0; i<string.Length; i++){
        hasil = hasil * 10 + (string.TabWord[i] - 48);
    }

    if (hasil < 0){
        int bilangan = 1;
        for (i=0; i<string.Length-1; i++){
            bilangan = bilangan * 10;
        }
        hasil += 38 * bilangan;
    }

    return hasil;
}

int CharToInt(char character)
/*I.S. character yang telah diakuisi berisi string bilangan [0..9].
   F.S. Mengembalikan nilai integer dari character yang diakuisisi.*/
{
    return character - 48;
}

Word stringToWord(char character[], int length)
/*Mengubah character(char) menjadi sebuah kata(Word).*/
{
    int i;
    Word strWord;

    strWord.Length = length;
    for (i = 0; i < length; i++)
    {
        strWord.TabWord[i] = character[i];
    }

    return strWord;
}

void CopyWordTo(Word *destination, Word source) {
    int i;
    for (i = 0; i < source.Length; i++) {
        destination->TabWord[i] = source.TabWord[i];
    }
    destination->Length = source.Length;
}

boolean wordCheck(Word perintah, int idxawal, int idxakhir, Word katauji){
    /*Mengembalikan true apabila katauji sama dengan kata yang ada di perintah dari idxawal sampai idxakhir*/
    boolean cek = true;
    int i;
    for (i=idxawal; i<=idxakhir; i++){
        if (perintah.TabWord[i] != katauji.TabWord[i]){
            cek = false;
        }
    }
    return cek;
}

// Fungsi yang mengembalikan Word dari index tertentu sampai akhir word lain
Word wordFromIndex(Word word, int index){
    Word newWord;
    int i;
    for (i = index; i < word.Length; i++) {
        newWord.TabWord[i - index] = word.TabWord[i];
    }
    newWord.Length = word.Length - index;
    return newWord;
}


void CopyWordCommand(){
    int i = 0;
    while (currentChar != MARK){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    if (i > NMax){
        currentWord.Length = NMax;
    }
    else{
        currentWord.Length = i;
    }
    EndWord = true;
}

void CopyString(char destination[MAXWord], char source[MAXWord]){
    int i = 0;
    while (source[i] != '\0'){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void STARTCOMMAND(){
    START();
    IgnoreBlanks();
    IgnoreNewLine();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWordCommand();
    }
}

void ADVCOMMAND(){
    IgnoreBlanks();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        CopyWordCommand();
    }
}

// Fungsi untuk mengambil word dari index tertentu sampai sebelum spasi, misal word = "BALAS 50 49" atau "BALAS 5 49 " maka yang diambil adalah "50" atau "5"
Word wordFromIndexToSpace(Word word, int index){
    Word newWord;
    int i;
    for (i = index; i < word.Length; i++) {
        if (word.TabWord[i] == ' '){
            break;
        }
        newWord.TabWord[i - index] = word.TabWord[i];
    }
    newWord.Length = i - index;
    return newWord;
}

boolean isWordInteger(Word angka){
    int i;
    boolean cek = true;
    for (i=0; i < angka.Length; i++){
        if (angka.TabWord[i] < 48 && angka.TabWord[i] > 57){
            cek = false;
        }
    }
    return cek;
}

// Fungsi untuk mengambil index terakhir dari 
