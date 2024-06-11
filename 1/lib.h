#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
typedef struct linkedlist
{
    DATA data;
    struct linkedlist* next;
}   ELEMENT;
typedef ELEMENT* LINK;

LINK newnode(DATA d);
void headinsert(LINK* lis,DATA d);

int maxsum(int* array,int size);
float ema(float alpha,float *aem,int i);
LINK newnode(DATA d);
void headinsert(LINK* lis,DATA d);
LINK deletk(LINK l1,int k,int m);
void printlis(LINK lis);
int longest_common_subseq(LINK l1, LINK l2);