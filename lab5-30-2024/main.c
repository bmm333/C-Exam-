#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

int main()
{
    srand(time(NULL));
    LINK list=NULL;
    int n=0;
    printf("inserire il numero dei nodi:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        DATA data=rand()%(100-0+1)-0;
        buildlist(&list,data);
    }
    int *array=NULL;
    readfile(&array);
    int arr1[]={2,4,5};
    int arr2[]={0,1,2,5,4};
    int index1=0;
    int size1=sizeof(arr1)/sizeof(int);
    int index2=0;
    int size2=sizeof(arr2)/sizeof(int);
    int ris= array_in(arr1,arr2,index1,size1,index2,size2); 
    if (ris) {
        printf("Gli elementi di arr1 compaiono in arr2 nello stesso ordine\n");
    } else {
        printf("Gli elementi di arr1 non compaiono in arr2 nello stesso ordine\n");
    }
}