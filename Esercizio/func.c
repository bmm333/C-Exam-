#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

char* maxwidthletter(char nome[][15], int max, int width, char k) {
    int maxCount = 0;
    char* maxString = NULL;

    for (int i = 0; i < max; i++) {
        int currentCount = 0;
        for (int j = 0; j < strlen(nome[i]); j++) {
            if (nome[i][j] == k) {
                currentCount++;
            }
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxString = nome[i];
        }
    }

    if (maxString) {
        char* result = (char*)malloc((strlen(maxString) + 1) * sizeof(char));
        if (result == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        strcpy(result, maxString);
        return result;
    }

    return NULL;
}
/*
int modiSalitaScala(int n)
{
    if(n<=1)
        return 1;
    return modiSalitaScala(n-1)+modiSalitaScala(n-2);
}
LINK newnode(DATA d)
{
    LINK p=malloc(sizeof(ELEMENT));
    if(p)
    {
        fprintf(stderr,"Error cannot allocate memory\n");
        exit(1);
    }
    p->data=d;
    p->next=NULL;
    return p;
}
void headinsert(LINK* lis,DATA d)
{
    LINK* temp=newnode(d);
    temp->next=(*lis);
    *lis=temp;
}
void tailinsert(LINK* lis,DATA d)
{
    if(*lis==NULL)
    {
        headinsert(&lis,d);
    }
    while(*lis->next!=NULL)
    {
        lis=lis->next;
    }
    LINK* temp=newnode(d);
    *lis->next=temp;
}
LINK estraiCrescenti(LINK l1,LINK l2);
{
    LINK l3=NULL;
    while(l1||l2)
    {

        if(l1->next->data>l2->next->data)
        {

            tailinsert(&l3,l1->data);
        }
        else if(l2->next->data>l1->next->data)
            tailinsert(&l3,l2->data);
        l1=l1->next;
        l2->l2->next;
    }
    return l3;
}
void caricalista(LINK lis,char* nome)
{
    
}
*/