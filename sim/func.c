#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

City* second(City* cities, int num)
{
    if (num < 2) {
        printf("Not enough cities to determine the second largest.\n");
        return NULL;
    }
    City* firstlargest=NULL;
    City* secondlargest=NULL;

    for(int i=0;i<num;i++)
    {
        if(firstlargest==NULL||cities[i].popolazione>firstlargest->popolazione)
        {
            secondlargest=firstlargest;
            firstlargest=&cities[i];
        }
        else if(secondlargest==NULL||cities[i].popolazione>secondlargest->popolazione)
        {
            secondlargest=&cities[i];
        }
    }
    return secondlargest;
}
int coeffbin(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }

    return coeffbin(n - 1, k - 1) + coeffbin(n - 1, k);
}
LINK newnode(DATA d)
{
    LINK p=malloc(sizeof(ELEMENT));
    if(!p)
    {
        fprintf(stderr,"Error cannot allocate memory for node\n");
        exit(1);
    }
    p->data=d;
    p->next=NULL;
    /*Handling the pointer's in the new node function will make calls to and returns easier to work on*/
    return p;
}
void headinsert(LINK* lis,DATA d)
{
    /*No need to explictly check for edge case in headinsert*/
    LINK temp=newnode(d);
    temp->next=(*lis);
    (*lis)=temp;
}
int nodesum(LINK l1,LINK l2,int k)
{
    /*We will start summing on the list with updated head*/
    int cnt = 0, sum = 0;

    // Traverse l1 to the kth node
    while (l1 != NULL && cnt < k) {
        l1 = l1->next;
        cnt++;
    }

    // Traverse l2 to the kth node
    cnt = 0;
    while (l2 != NULL && cnt < k) {
        l2 = l2->next;
        cnt++;
    }

    // Sum the nodes after the kth position in both lists
    while (l1 != NULL) {
        sum += l1->data;
        l1 = l1->next;
    }

    while (l2 != NULL) {
        sum += l2->data;
        l2 = l2->next;
    }

    return sum;
}

LINK reverse(LINK lis,LINK prev)
{
    if(!lis)
    {
        return prev;
    }
    else{
        LINK next=lis->next;
        lis->next=prev;
        return reverse(next,lis);
    }
}