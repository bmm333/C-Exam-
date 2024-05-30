#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"



int main()
{
    srand(time(NULL));
    int *array;
    int size;
    float alpha=0.5;
    LINK list=NULL;
    printf("Enter the size of elements for the array");
    scanf("%d", &size); 
    array=(int*)malloc(size*sizeof(int));
     for (int i = 0; i < size; i++) {
        DATA data = rand() % (25 - 1 + 1) + 1;
        headinsert(&list, data);
    }
    if(array==NULL)
    {
        printf("not enough memory\n");
    }
    else 
    {
        for(int i=0;i<size;i++)
        {
            
        }
        printf("Allocated\n");
        for (int i = 0; i < size; i++) {
            array[i] = rand() % (25 - 1 + 1) + 1;
        }
        printf("Elements of array are:\n");
        for (int i = 0; i < size; i++) {
            printf("%d\n", array[i]); // Print each element on a separate line
        }
    }
    int max=maxSum(array,size);
    printf("Max sum of 2 elements in array is:\t%d\n",max);
     for (int i = 0; i < size; i++) {
        printf("EMA(%d): %.3f\n", i, ema(array, alpha, i + 1));
    }
    int k=2,m=2;
    printlist(list);
    km(&list,k,m);
    printf("La lista dopo la cancellazione di m in k\n");
    printlist(list);
}

/*Scrivere una funzione ricorsiva che prenda in input due liste e restituisca in output la lunghezza della sequenza
comune (con posizione corrispondente) piùlunga. Analizzare e motivare la complessità in tempo e spazio della
funzione proposta. PREDISPORRE IL CARICAMENTO DA FILE DELLA LISTA al di fuori della funzione.
Esempio
L1: 1-->1-->2-->2-->2-->3-->3-->3-->3-->1-->1
L2: 1-->1-->2-->2-->7-->7-->3-->3-->3-->1-->3
Output: 4
*/