#ifndef BALASAN_H
#define BALASAN_H

#include "../includeADT.h"
#include "../../modules/adt.h"
#include "../Kicauan/Kicauan.h"
int hitungKicauanDenganBalasan(ListKicau listKicauan);
void PrintBalasan(Balasan kontol, int indent);
void PrintTreeBalasan(TreeBalasan t, int indent);
void Balas(ListKicau *listKicauan, Account akunLogin, int idkicau, int idbalasan);
void DisplayBalasan(ListKicau listKicauan, int idkicau);
void HapusBalasan(ListKicau *listKicauan);

#endif