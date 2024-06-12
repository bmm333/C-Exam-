#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lib.h"

int main()
{
   /* int n=0;
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
    printf("Ultimo libro inserito e %s del autore %s nel %d\n",ris.titolo,ris.autore,ris.anno_pubblicazione);
    printf("Quantita dei studenti da registrare:\n");
    int num_stu=0;
    scanf("%d",&num_stu);
    if(num_stu<1)
    {
        fprintf(stderr,"Numero non accettabile , inserire almeno 1 studente\n");
        exit(1);
    }
    Student *stu=malloc(sizeof(num_stu*sizeof(Student)));
    if(!stu)
    {
        fprintf(stderr,"cannot allocate memory for new students to register\n");
        exit(2);
    }
    insertstudents(stu,num_stu);
    studentsout(stu,num_stu);
    printf("quanti prodotti volete inserire?\n");
    int nump=0;
    scanf("%d",&nump);
    Prodotto* prod=malloc(sizeof(nump*sizeof(Prodotto)));
     if (prod == NULL) {
        fprintf(stderr, "Errore di allocazione della memoria.\n");
        return 1;
    }
    for(int i=0;i<nump;++i)
    {
        prod[i].codice=-1;
    }
    inserisciProdotti(prod,nump);
    stampaprodotti(prod,nump);*/
    
    LINK list=NULL;
    char filename[50];
    printf("insert file name to prase data from:\n");
    scanf("%s",filename);
    list = uploadtolist(&list,filename);
    printlist(list);
    return 0;
}