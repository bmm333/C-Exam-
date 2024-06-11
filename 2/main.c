#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lib.h"

int main()
{
    int n=0;
    printf("quante citta volete inserire?\n");
    scanf("%d",&n);
    City citta[n];
    inputCities(citta, n);

    Cit result = secondlargest(citta, n);
    if(!result.nome)
    {
        printf("non ci sono abbastnza citta per paragonarli\n");
    }
    else
    {
        printf("la seconda citta piu grande insertia e %s con %d popolazione\n",result.nome,result.popolazione);
    }
    for(int i=0;i<n;i++)
    {
        free((char*)citta[i]->nome);
        free(citta[i]);
    }
    int num_libri=0;
    printf("inserire il numero dei libri da inserire:\n");
    scanf("%d",&num_libri);
    Libro *bibloteca=malloc(sizeof(num_libri * sizeof(Libro)));
    if(!bibloteca)
    {
        fprintf(stderr,"cannot allocate memory for the library\n");
        exit(1);
    }
    insertbooks(bibloteca,num_libri);
    Libro ris=ultimo(bibloteca,num_libri);
    printf("Ultimo libro inserito e %s del autore %s nel %d",ris.titolo,ris.autore,ris.anno_pubblicazione);


    return 0;
}