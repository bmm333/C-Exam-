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
void deleteelement(LINK *lis, DATA d) {
    if (*lis == NULL) {
        return;
    }

    while (*lis != NULL && (*lis)->data == d) {
        LINK temp = *lis;
        *lis = (*lis)->next;
        free(temp);
    }

    LINK current = *lis;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == d) {
            LINK temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}
void printlist(LINK lis)
{
    if(lis!=NULL)
    {
        printf(">>%d\n",lis->data);
        printlist(lis->next);
    }
    return;
}
int listlength(LINK lis)
{
    if(lis==NULL)
    {
        return 0;
    }
    if(lis!=NULL)
    {
        return 1 + listlength(lis->next);
    }
}
LINK reverse(LINK* lis)
{
    LINK prev=NULL;
    LINK Next=(*lis);
    LINK curr=(*lis);
    while(curr)
    {
        curr=curr->next;
        Next->next=prev;
        prev=Next;
        Next=curr;
    }
    *lis=prev;
    return prev;
}
int looplist(LINK* lis)
{
    LINK fast=(*lis);
    LINK slow=(*lis);

    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return 1;
        }
    }
    return 0;
}
LINK middleoflist(LINK* lis)
{
    LINK fast=(*lis);
    LINK slow=(*lis);

    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

LINK mergesortedlists(LINK l1,LINK l2)
{
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1!=NULL||l2!=NULL)
    {
        if(l1->data<l2->data)
        {
            l1->next=mergesortedlists(l1->next,l2);
            return l1;
        }
        else
        {
            l2->next=mergesortedlists(l1,l2->next);
            return l2;
        }
    }
}
LINK removedup(LINK* lis)
{
    if (*lis == NULL)
        return NULL;
    LINK curr=(*lis);
    while(curr->next!=NULL)
    {
        if(curr->next->data==(*lis)->data)
        {
            LINK dup=curr->next;
            curr->next=curr->next->next;
            free(dup);
        }
        else
            curr=curr->next;
    }
    removedup(&((*lis)->next));

}


