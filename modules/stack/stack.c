#include <stdio.h>
#include "stack.h"

void CreateEmptyStack(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S){
    return Top(S) == Nil;
}

boolean IsFullStack(Stack S){
    return Top(S) == MaxEl - 1;
}

void Push(Stack *S, drafkicau X){
    Top(*S)++;
    InfoTop(*S) = X;
}

void Pop(Stack *S, drafkicau * X){
    *X = InfoTop(*S);
    Top(*S)--;
}

int NbElmtStack(Stack S){
    return Top(S) + 1;
}