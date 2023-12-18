#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

//test case awal-awal prolly 2-4
boolean isEmptyQ(Queue q){
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

//tc 5-6
boolean isFullQ(Queue q){
    return (IDX_HEAD(q) - 1 == IDX_TAIL(q) || (IDX_TAIL(q) == 0 && IDX_HEAD(q) == CAPACITY - 1) || (IDX_HEAD(q) == 0 && IDX_TAIL(q) == CAPACITY - 1));
}

int lengthQ(Queue q){
    if(isEmptyQ(q)){
        return 0;
    }
    if(IDX_HEAD(q) == IDX_TAIL(q)){
        return 1;
    }
    if(IDX_HEAD(q) > IDX_TAIL(q)){
        return IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1;
    }
    return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

void enqueue(Queue *q, ElType val){
    if(isEmptyQ(*q)){
        IDX_TAIL(*q) = 0;
        IDX_HEAD(*q) = 0;
    }
    else{
        if(IDX_TAIL(*q) != CAPACITY - 1){
            IDX_TAIL(*q)++;
        }
        else{
            IDX_TAIL(*q) = 0;
        }
    }
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if(lengthQ(*q) == 1){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        if(IDX_HEAD(*q) == CAPACITY - 1){
            IDX_HEAD(*q) = 0;
        }else{
            IDX_HEAD(*q)++;
        }
    }
}

void displayQueue(Queue q){
    int val;
    int firstLength = lengthQ(q);
    printf("[");
    for(int i = 0; i < firstLength; i++){
        if(i != firstLength - 1){
            printf("%d,", HEAD(q));
        }else{
            printf("%d", HEAD(q));
        }
        if(IDX_HEAD(q) == CAPACITY - 1){
            IDX_HEAD(q) = 0;    
        }
        else{
            IDX_HEAD(q)++;
        }
    }
    printf("]\n");
}