/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef __WORDMACHINE_H__
#define __WORDMACHINE_H__

#include "../boolean.h"
#include "charmachine.h"

#define NMax 281
#define BLANK ' '
#define MARKBaris '\n'
#define MARKFile '\0'
#define MAXWord 281

typedef struct
{
   char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Word */
extern boolean EndWord;
extern Word currentWord;


/* ********** UTILITAS ********** */
void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK \n
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreNewLine();
/* Mengabaikan satu atau beberapa NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NEWLINE atau currentChar = MARK */

/* ********** INPUT/OUTPUT Mesin Kata (I/O) ********** */
void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void ADVSENTENCE();

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordSpace();
/*Mengakuisisi kalimat ke dalam kata(currentWord), dengan enter atau NewLine sebagai MARK*/

void printWord(Word w);
/*Mencetak kata, dengan input suatu variabel word yang telah diakuisisi.*/

void STARTWORD_FILE(char filename[]);
/*Pita dari file eksternal siap dibaca oleh mesin kata.*/

/* ********** OPERATOR RELASIONAL ********** */
boolean WordEqual(Word a, Word b);
/*Mengirimkan true apabila Word a dan Word b identik.*/

boolean isWordInteger(Word angka);
/*Mengirimkan true apabila Word merupakan bilangan atau integer.*/

/* ********** KONVERTOR ********** */
int WordToInt(Word string);
/*I.S. Kata yang telah diakuisi berisi string bilangan [0..9].
   F.S. Mengembalikan nilai integer dari kata yang diakuisisi.*/

int CharToInt(char character);
/*I.S. character yang telah diakuisi berisi string bilangan [0..9].
   F.S. Mengembalikan nilai integer dari character yang diakuisisi.*/

Word stringToWord(char character[], int length);
/*Mengubah character(char) menjadi sebuah kata(Word).*/

void CopyWordTo(Word *destination, Word source);

void CopyWordCommand();

void CopyString(char destination[MAXWord], char source[MAXWord]);

boolean wordCheck(Word perintah, int idxawal, int idxakhir, Word katauji);

Word wordFromIndex(Word word, int index);

void CopyWordCommand();

void STARTCOMMAND();

void ADVCOMMAND();

#endif
