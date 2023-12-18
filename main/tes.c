#include "includeADT.h"
#include "functions.c"


int main() {
    // AccountList list;
    // CreateAccountList(&list);
    // Graf temanl;
    // createEmptyGraf(&temanl);    
    // ReadUser_FILE("../cfg/pengguna.config", &list, &temanl);
    // DisplayAccounts(&list);
    // displayGraf(temanl, list.count);
    teman t1,t2,t3;
    prioqueuefren Q;
    t1.IDpenerima = 0;
    t1.IDpengirim = 1;
    t1.Jumlahteman = 5;
    t2.IDpenerima = 1;
    t2.IDpengirim = 2;
    t2.Jumlahteman = 3;
    t3.IDpenerima = 0;
    t3.IDpengirim = 2;
    t3.Jumlahteman = 4;
    MakeEmptyprio(&Q,10);
    Enqueueprio(&Q,t1);
    Enqueueprio(&Q,t2);
    Enqueueprio(&Q,t3);
    printf("!");
    while(!IsEmptyPrio(Q)){
        teman temp;
        Dequeueprio(&Q, &temp);
        printf("%d\n", temp.Jumlahteman);
    }
}