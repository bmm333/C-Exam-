#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int maxSum(int *array, int size) {
    int max = 0;
    for (int i = 0; i < size - 1; i++) {
        if (array[i] + array[i + 1] > max) {
            max = array[i] + array[i + 1];
        }
    }
    return max;
}

float ema(int *array, float alpha, int i) {
    // Caso base
    if (i == 0) {
        return array[0];
    }
    // Passo ricorsivo
    return alpha * (float)array[i] + (1 - alpha) * ema(array, alpha, i - 1);
}
LINK newnode(DATA d)
{
    LINK node=malloc(sizeof(ELEMENT));
    node->data=d;
    node->next=NULL;
    return node;
}
void headinsert(LINK *lis,DATA data)
{
	LINK node=newnode(data);
	node->next=(*lis);
	(*lis)=node;
}
void tailinsert(LINK *lis,DATA d)
{
    LINK p,q;
    p=newnode(d);
    q=(*lis);
    if(q==NULL)
    {
        (*lis)=p;
    }
    else{
        while(q!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }

}
void printlist(LINK lis)
{
    printf("List");
    while(lis!=NULL)
    {
        
        printf("->%d",lis->data);
        lis=lis->next;
    }
    printf("->NULL");
    printf("\n");

}
void km(LINK *lis,int k,int m)
{
    int n=0;
    LINK current=(*lis);
      while (current != NULL) {
        if (current->data % m != 0 && n % k == 0) {
            LINK temp = current;
            *lis = current->next;
            current = current->next;
            free(temp);
        } else {
            n++;
            current = current->next;
        }
    }
}
