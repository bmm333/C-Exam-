#include <stdio.h>
#include <stdlib.h>

typedef struct STU {
    int eta;
} Studenti;

typedef int DATA;

typedef struct linked{
    DATA data;
    struct linked* next;
} ELEMENT;
typedef ELEMENT * LINK;


void dividi(Studenti A[], int n, Studenti** B, int* nB, Studenti** C, int* nC);
void headinsert(LINK *lis,DATA d);
LINK findkth(LINK lis,int k,int m);
void printlis(LINK *lis);
