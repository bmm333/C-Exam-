#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void readfile(int **array) {
    int val = 0, i = 0;
    int size = 0;
    FILE *fp = fopen("text.txt", "r");
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
