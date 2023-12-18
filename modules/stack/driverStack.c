#include <stdio.h>
#include "../adt.h"

// how to compile, gcc -o driverStack driverStack.c

int main()
{
  Stack S;
  int SS, M, HH, DD, MM, YY;
  getlocaltime(&SS, &M, &HH, &DD, &MM, &YY);
  DATETIME waktudraf;
  CreateDATETIME(&waktudraf, DD, MM, YY, HH, M, SS);
  CreateEmptyStack(&S);
  if (IsEmptyStack(S))
  {
    printf("Stack kosong\n");
  }
  if (IsFullStack(S))
  {
    printf("Stack penuh\n");
  }
  drafkicau X;
  CopyWordTo(&X.Draf, stringToWord("Hello", 5));
  X.IDuser = 1010;
  X.waktu = waktudraf;
  Push(&S, X);
  if (IsEmptyStack(S))
  {
    printf("Stack kosong\n");
  }
  if (IsFullStack(S))
  {
    printf("Stack penuh\n");
  }
  Pop(&S, &X);
  printWord(X.Draf);
  printf("\n");
  printf("Top stack: %d\n", X.IDuser);
  TulisDATETIME(X.waktu);
}