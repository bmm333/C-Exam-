#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int maxsum(int* array,int size)
{
    int currsum=0;
    int maxsum=0;
    for(int i=0;i<size;i++)
    {
        currsum=array[i]+array[i+1];
        if(currsum>maxsum)
        {
            maxsum=currsum;
        }
    }
    return maxsum;
}

float ema(float alpha,float* v,int i)
{
    if(i==0)
    {
        return v[i];
    }
    return alpha * v[i] + (1 - alpha) * ema(alpha, v, i - 1);
}
LINK newnode(DATA d)
{
    LINK p=malloc(sizeof(ELEMENT));
    if(!p)
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
    LINK temp=newnode(d);
    temp->next=*lis;
    *lis=temp;
}
LINK deletk(LINK l1, int k, int m) {
    if (!l1)
        return NULL;

    LINK curr = l1;
    int cnt = 1;

    while (curr && curr->next) {
        if (cnt % k == 0) {
            if ((curr->next->data % 2) == 0) {
                LINK temp = curr->next;
                curr->next = temp->next;
                free(temp);
                // Decrement cnt to ensure the correct position for the next node after deletion
                cnt--;
            }
        }
        cnt++;
        curr = curr->next;
    }

    return l1;
}
void printlis(LINK lis){
    while(lis)
    {
        printf("%d\n",lis->data);
        lis=lis->next;
    }
}
int longest_common_subseq(LINK l1, LINK l2) {
    if (!l1 || !l2) {
        return 0;
    }

    if (l1->data == l2->data) {
        return 1 + longest_common_subseq(l1->next, l2->next);
    } else {
        int skip_l1 = longest_common_subseq(l1->next, l2);
        int skip_l2 = longest_common_subseq(l1, l2->next);

        if (skip_l1 > skip_l2) {
            return skip_l1;
        } else {
            return skip_l2;
        }
    }
}