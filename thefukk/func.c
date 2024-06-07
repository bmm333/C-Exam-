 /*implement a singly linked list with basic operations like insertion, deletion, and traversal.
Finding the Length of a Linked List*/
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

LINK newnode(DATA d){
    LINK p=malloc(sizeof(ELEMENT));
    if(p==NULL)
    {
        fprintf(stderr,"ERROR cannot allocate new node\n");
    }
    p->data=d;
    p->next=NULL;
    return p;
}
void headinsert(LINK *lis,DATA d){
    if(*lis==NULL)
    {
        (*lis)=newnode(d);
    }
    else
    {
        LINK temp=newnode(d);
        temp->next=(*lis);
        *lis=temp;
    }
}
void deleteelement(LINK *lis,DATA d)
{
    if((*lis)==NULL)
    {   
        return;
    }    
    if((*lis)->next != NULL && (*lis)->next->data == d)
    {
        LINK temp=(*lis)->next;
        (*lis)->next=temp->next;
        free(temp);
        deleteelement(&((*lis)->next), d);
    }
    else{
        deleteelement(&((*lis)->next), d);
    }

}
void printlist(LINK lis)
{
    if(lis!=NULL)
    {
        printf(">>%d",lis->data);
        printlist(lis->next);
    }
    return;
}

