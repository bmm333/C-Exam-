#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int array[]={1,4,6,7,8,9};
    int size=sizeof(array)/sizeof(array[0]);
    printf("MAx conx sum is: %d\n",maxsum(array,size));
    float aem[]={0.6,1.7,4.8,1.5};
    int sizema=sizeof(aem)/sizeof(aem[0]);
    float alpha=0.5;
    for(int i=0;i<sizema;i++)
    {
        printf("EMA is %f\n",ema(alpha,aem,i));
    }
    LINK l1 = NULL;
    LINK l2 = NULL;
    headinsert(&l1, 6);
    headinsert(&l1, 6);
    headinsert(&l1, 6);
    headinsert(&l1, 2);
    headinsert(&l2, 9);
    headinsert(&l2, 6);
    headinsert(&l2, 6);
    headinsert(&l2, 6);
    
    int k = 1, m = 2;
    /*deletk(l1, k, m);*/
    
    printf("La lista e: \n");
    printlis(l1);
    
    int cn=0;
    printf("Lunghezza comune massima e %d\n", longest_common_subseq(l1, l2));
    
    return 0;
}