#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int main(){
	Matrix m;
	createMatrix(4,4,&m);
	readMatrix(&m,4,4);
    pTranspose(&m);
	displayMatrix(m);
}