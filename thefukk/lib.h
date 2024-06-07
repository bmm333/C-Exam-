#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
typedef struct linkedlist
{
    DATA data;
    struct linkedlist* next;
} ELEMENT;
typedef ELEMENT* LINK;

LINK newnode(DATA d);
void headinsert(LINK *lis,DATA d);
void deleteelement(LINK *lis,DATA d);
void deletelist(LINK* lis);
int listlength(LINK lis);
void printlist(LINK lis);