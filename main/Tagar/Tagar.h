#ifndef TAGAR_H
#define TAGAR_H

#include "../../modules/adt.h"
#include "../includeADT.h"

void wordToStr(char destination[MAXChar],Word input);
boolean compareWithoutHash(const char *str1, const char *str2);
char toLowerz(char ch);
void toLowerCaze(const char *source, char *destination);
void KicauanTagar(ListKicau list, Word tags);

#endif