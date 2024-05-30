#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void readfile(int **array) {
    int val = 0, i = 0;
    int size = 0;
    FILE *fp = fopen("./lab5-30-2024/text.txt", "r");
    if (fp == NULL) {
        printf("Error cannot open file");
        return;
    }
    int *temp = NULL;
    while (fscanf(fp, "%d", &val) != EOF) {
        if (val > 0) {
            temp = (int *) realloc(*array, (i + 1) * sizeof(int));
            if (temp == NULL) {
                free(*array);
                printf("Errore di allocazione della memoria!\n");
                fclose(fp);
                return;
            }
            *array = temp;
            (*array)[i] = val;
            i++;
            size = i;
        }
    }
    fclose(fp);

    for (i = 0; i < size; i++) {
        printf("Elementi nel array: %d\n", (*array)[i]);
    }
  /*  int min=(*array)[i];
    int max=(*array)[i];
    int sum
    int media=0;
    for(i=0;i<size;i++)
    {
        if(min>array[i])
        {
            min=array[i];
        }
        else if(max<array[i])
        {
            max=array[i];
        }
        sum+=array[i];
    }
    media=sum/size;*/
}

int array_in(int arr1[], int arr2[], int index1, int size1, int index2, int size2) {
    // Se tutti gli elementi di arr1 sono stati trovati in arr2
    if (index1 == size1) {
        return 1;
    }
    // Se arr2 è esaurito prima di trovare tutti gli elementi di arr1
    if (index2 == size2) {
        return 0;
    }
    // Se l'elemento corrente di arr1 è uguale all'elemento corrente di arr2
    if (arr1[index1] == arr2[index2]) {
        // Continua a cercare il prossimo elemento di arr1 e di arr2
        return array_in(arr1, arr2, index1 + 1, size1, index2 + 1, size2);
    }
    // Se l'elemento corrente di arr1 non è stato trovato in arr2, continua la ricerca in arr2 dall'elemento successivo
    return array_in(arr1, arr2, index1, size1, index2 + 1, size2);
}

LINK newnode(DATA d)
{
    LINK nodo=malloc(sizeof(ELEMENT));
    nodo->data=d;
    nodo->next=NULL;
    return nodo;
}
void buildlist(LINK *lis,DATA d)
{
    LINK p=newnode(d);
	p->next=(*lis);
	*lis=p;
    buildlist(lis,d);
}