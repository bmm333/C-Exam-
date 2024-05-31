#ifndef LIB_H
#define LIB_H

typedef int DATA;
struct Nodo{
    DATA data;
    struct Nodo* next;
};
typedef struct Nodo ELEMENT;
typedef ELEMENT* LINK;
LINK newnode(DATA d);
void buildlist(LINK *lis, DATA d);
void printlist(LINK *lis);
void readfile(int **array);
int array_in(int arr1[],int arr2[],int index1,int size1,int index2,int size2);
void scalarproduct(LINK l1,LINK l2);
LINK list_build(LINK lis);

#endif // LIB_H