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
char* maxwidthletter(char nome[][15], int max, int width, char k);
int modiSalitaScala(int n);

