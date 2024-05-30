#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
struct Nodo{
    DATA data;
    struct nodo* next;
};
typedef struct Nodo ELEMENT;
typedef ELEMENT * LINK;

void readfile(int **array);
int array_in(int arr1[],int arr2[],int index1,int size1,int index2,int size2);
LINK newnode(DATA d);
void buildlist(LINK *lis,DATA d);