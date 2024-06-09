#include <stdio.h>
#include <stdlib.h>

typedef struct citta{
    const char* nome;
    int popolazione;
} City;
typedef int DATA;
typedef struct linkedlist{
    DATA data;
    struct linkedlist* next;
} ELEMENT;
typedef ELEMENT* LINK;


City* second(City* cities, int num);
int coeffbin(int n,int k);
LINK newnode(DATA d);
void headinsert(LINK* lis,DATA d);
int nodesum(LINK l1,LINK l2,int k);


