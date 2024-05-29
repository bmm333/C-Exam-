#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

struct linked
{
    DATA data;
    struct linked* next;
};
typedef struct linked ELEMENT;
typedef ELEMENT* LINK;

int maxSum(int *array, int size);
float ema(int *array, float alpha, int i);
LINK newnode(DATA d);
void headinsert(LINK *lis,DATA d);
void printlist(LINK lis);
void km(LINK *lis,int k,int m);