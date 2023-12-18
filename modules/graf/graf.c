#include <stdio.h>
#include "graf.h"

void createEmptyGraf(Graf *g)
{
    int i, j;
    for (i = 0; i < ROW_GRAF; i++){
        for (j = 0; j < COL_GRAF; j++){
            ELMTGRAF(*g, i, j) = MARKGRAF;
        }
    }
}

void CreateListGraf(ListGraf *l)
{
    for (int i = 0; i <= CAPACITYGRAF-1; i++) {
        ELMTLISTGRAF(*l, i) = MARKLISTGRAF;
    }
}

int listEffGraf(ListGraf l)
{
    int sum = 0;
    for (int i = 0; i <= CAPACITYGRAF-1; i++) {
        if(ELMTLISTGRAF(l, i) == 1)
        {
            sum++;
        }
    }
    return sum;
}

boolean isEmptylistGraf(ListGraf l)
{
    return (listEffGraf(l) == 0);
}

void getOne(Graf g, IdxGraf rowID, ListGraf *l)
{
    int j;
    for (j = 0; j < COL_GRAF; j++)
    {
        if (ELMTGRAF(g,rowID,j) == 1 && rowID != j)
        {
            ELMTLISTGRAF(*l,j) = 1;
        }
    }
}

void displayGraf(Graf g, int count)
{
    int i, j;
    for (i = 0; i < count; i++){
        for (j = 0; j < count; j++){
            printf("%d", ELMTGRAF(g, i, j));
            if (j != count - 1){
                printf(" ");
            }
        }
        if (i != count - 1){
            printf("\n");
        }
    }
    printf("\n");
}

void printListGraf(ListGraf l)
{
    printf("[");
    for (int i = 0; i <=CAPACITYGRAF-1; i++) {
        if (i==CAPACITYGRAF-1) {
            printf("%d", ELMTLISTGRAF(l,i));
        } else {
            printf("%d,", ELMTLISTGRAF(l,i));
        }
    } 
    printf("]");
}
