#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void readfile(int **array) {
    int val = 0, i = 0;
    int size = 0;
    FILE *fp = fopen("./lab5-30-2024/text.txt", "r");
    if (fp == NULL) {
        printf("Error: cannot open file");
        return;
    }
    int *temp = NULL;
    while (fscanf(fp, "%d", &val) != EOF) {
        if (val > 0) {
            temp = (int *)realloc(*array, (i + 1) * sizeof(int));
            if (temp == NULL) {
                free(*array);
                printf("Memory allocation error!\n");
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

    for (i = 0; i < size; i++) 
    {
        printf("Element in array: %d\n", (*array)[i]);
    }

    if (size == 0) 
    {
        printf("No valid elements to process.\n");
        return;
    }

    int min = (*array)[0];
    int max = (*array)[0];
    int sum = 0;
    float media;

    for (int l = 0; l < size; l++) 
    {
        if (min > (*array)[l]) 
        {
            min = (*array)[l];
        }
        if (max < (*array)[l]) 
        {
            max = (*array)[l];
        }
        sum += (*array)[l];
    }

    media = sum / (float)size;  // Cast size to float to get a float result
    printf("La media è: %.2f\n", media);  // Use %.2f to print the float value with 2 decimal places
    printf("Il minimo è: %d\n", min);
    printf("Il massimo è: %d\n", max);
}

int array_in(int arr1[], int arr2[], int index1, int size1, int index2, int size2) 
{
    // Se tutti gli elementi di arr1 sono stati trovati in arr2
    if (index1 == size1)
    {
        return 1;
    }
    // Se arr2 è esaurito prima di trovare tutti gli elementi di arr1
    if (index2 == size2) 
    {
        return 0;
    }
    // Se l'elemento corrente di arr1 è uguale all'elemento corrente di arr2
    if (arr1[index1] == arr2[index2])
    {
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

    LINK p = newnode(d);
    p->next = *lis;
    *lis = p;
}
void printlist(LINK *lis)
{
    if(*lis!=NULL)
    {
        printf(">>>%d\n",(*lis)->data);
        printlist(&((*lis)->next));
    }
}
void scalarproduct(LINK l1,LINK l2)
{

    int sum=0;
    while(l1!=NULL&&l2!=NULL)
    {
        sum+=l1->data*l2->data;
        l1=l1->next;
        l2=l1->next;
    }
    printf("Prodotto scalare: %d\n",sum);
    
}

LINK list_build(LINK lis)
{
    LINK dup=NULL;
    while(lis!=NULL)
    {
        LINK curr=lis->next;
        int count=0;
        while(curr!=NULL)
        {
            if(curr->data==lis->data)
            {
                count++;
            }
            curr=curr->next;
        }
        if(count>0)
        {
            buildlist(&dup,lis->data);
        }
        lis=lis->next;
    }
    return dup;
}
LINK reverse(LINK *lis)
{
    LINK curr = *lis;
    LINK prev = NULL;
    LINK next = NULL;

    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;       
        curr = next;       
    }
    *lis = prev;
    return *lis;
}