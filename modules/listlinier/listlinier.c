#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Addresslin newNode(ElType val){
    Addresslin p = (Addresslin)malloc(sizeof(Node));
    if(p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx){
    while(idx--){
        FIRST(l) = NEXT(l);
    }
    return INFO(l);
}

void setElmt(List*l, int idx, ElType val){
    List p = *l;
    while(idx--){
        FIRST(p) = NEXT(p);
    }
    INFO(p)=val;
}

int indexOf(List l, ElType val){
    boolean found = false;
    int idx = 0;
    while(l != NULL && !found){
        if(INFO(l) == val){
            found = true;
        }
        else {
            idx++;
            FIRST(l) = NEXT(l);
        }
    }
    if (found) return idx;
    return IDX_UNDEFlin;
}

void insertFirst(List *l, ElType val){
    Addresslin p = newNode(val);
    if(p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val){
    if(isEmpty(*l)){
        insertFirst(l, val);
    }
    else {
        Addresslin p = newNode(val);
        if(p != NULL){
            Addresslin last = *l;
            while(NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
    if(idx == 0){
        insertFirst(l,val);
    }
    else {
        Addresslin p = newNode(val);
        if(p != NULL){
            int ctr = 0;Addresslin loc = *l;
            while(ctr < idx - 1){
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Addresslin p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLast(List *l, ElType *val){
    Addresslin p = *l, loc = NULL;
    while(NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if(loc == NULL){
        *l = NULL;
    }
    else{
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
    if(idx == 0){
        deleteFirst(l, val);
    } else {
        int ctr = 0;
        Addresslin loc = *l;
        while(ctr < idx - 1){
            ctr++;
            loc = NEXT(loc);
        }
        Addresslin p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l){
    printf("[");
    while(!isEmpty(l)){
        printf("%d", INFO(l));
        if(NEXT(l) != NULL){
            printf(",");
        }
        l = NEXT(l);
    }
    printf("]");
}

int length(List l){
    int cnt = 0;
    while(l != NULL){
        cnt++;
        l = NEXT(l);
    } return cnt;
}

List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Addresslin p = l1;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while(p != NULL){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    return l3;
}