#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define MAX_LEN 15
#define MAX_WID 15

int main()
{
    char nome[MAX_LEN][MAX_WID]={"Carlo","Maurizio","Patanza","Lanza","Valangala"};
    char k='a';
    maxwidthletter(&nome,MAX_LEN,MAX_WID,k);
  /*  int num;
    num=modiSalitaScala(10);
    printf("%d",num);*/
    LINK lis=NULL;
    LINK lisz=NULL;
    char* result = maxwidthletter(nome, MAX_LEN, MAX_WID, k);

    if (result) {
        printf("String with most occurrences of '%c': %s\n", k, result);
        free(result);
    } else {
        printf("No occurrences of '%c' found\n", k);
    }

}