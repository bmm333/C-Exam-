#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void dividi(Studenti A[], int n, Studenti** B, int* nB, Studenti** C, int* nC) {
    *nB = 0;
    *nC = 0;

    for (int i = 0; i < n; i++) {
        if (A[i].eta < 18) {
            (*nB)++;
        } else {
            (*nC)++;
        }
    }

    *B = (Studenti*)malloc(*nB * sizeof(Studenti));
    *C = (Studenti*)malloc(*nC * sizeof(Studenti));

    if (*B == NULL || *C == NULL) {
        printf("Errore: impossibile allocare memoria\n");
        exit(1);
    }

    int indexB = 0;
    int indexC = 0;
    for (int i = 0; i < n; i++) {
        if (A[i].eta < 18) {
            (*B)[indexB++] = A[i];
        } else {
            (*C)[indexC++] = A[i];
        }
    }

    *nB -= 1;
    *nC -= 1;
}

LINK newnode(DATA d)
{
    LINK p=malloc(sizeof(ELEMENT));
    p->data=d;
    p->next=NULL;
    return p;
}
void headinsert(LINK *lis,DATA d)
{
    LINK p = newnode(d);
    p->next = *lis;
    *lis = p;
}
LINK findkth(LINK lis,int k,int m)
{
    int c=0;
    while (lis!=NULL)
    {
        if(lis->data==k)
        {
            c++;
            if(c==m)
            {
                return lis;
            }
        }
        lis=lis->next;
    }
    return lis;
}
void printlis(LINK *lis)
{
    while(*lis!=NULL)
    {
        printf(">>>>%d\n",(*lis)->data);
        *lis=(*lis)->next;
    }
}


