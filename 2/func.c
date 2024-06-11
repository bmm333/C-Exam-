#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lib.h"


void inputCities(City* citty,int n)
{
    for(int i=0;i<n;i++)
    {
        citty[i]=(City)malloc(sizeof(Cit));
        char name[100];
        printf("inserire nome di citta: %d\n",i+1);
        scanf("%s",name);
        citty[i]->nome=strdup(name);
        printf("inseire la popolazione della citta %d :",i+1);
        scanf("%d",&citty[i]->popolazione);
    }
}

Cit secondlargest(City* citta, int n) {
    if (n < 2) {
        Cit empty;
        empty.nome = NULL;
        empty.popolazione = 0;
        return empty;
    }

    Cit max1 = {NULL, INT_MIN};
    Cit max2 = {NULL, INT_MIN};

    for (int i = 0; i < n; i++) {
        if (citta[i]->popolazione > max1.popolazione) {
            max2 = max1;
            max1 = *(citta[i]);
        } else if (citta[i]->popolazione > max2.popolazione && citta[i]->popolazione < max1.popolazione) {
            max2 = *(citta[i]);
        }
    }

    return max2;
}

void insertbooks(Libro* biblioteca, int bsize) {
    for(int i = 0; i < bsize; i++) {
        printf("Inserire il titolo del %d libro: ", i + 1);
        scanf("%s", biblioteca[i].titolo);
        printf("Inserire il nome dell'autore del libro %d: ", i + 1);
        scanf("%s", biblioteca[i].autore);
        printf("Inserire l'anno di pubblicazione del libro %d: ", i + 1);
        scanf("%d", &biblioteca[i].anno_pubblicazione);
    }
}
Libro ultimo(Libro* bibloteca,int bsize)
{
    if(bsize<=0)
    {
        Libro vuoto={"","",0};
        return vuoto;
    }
    Libro ultimo = bibloteca[0];
    for(int i=0;i<bsize;i++)
    {
        if(bibloteca[i].anno_pubblicazione>ultimo.anno_pubblicazione)
        {
            ultimo=bibloteca[i];
        }
    }
    return ultimo;
}
void insertstudents(Student* students,int size)
{
    for(int i=0;i<size;i++)
    {
        srand(time(NULL));
        students[i].matricola=rand()%(size + 1 - 1) + 1;
        printf("inseire il nome della matricola %d \n",students[i].matricola);
        scanf("%s",students[i].nome);
        printf("inseire il cognome della matricola %d \n",students[i].matricola);
        scanf("%s",students[i].cognome);
        printf("inseire leta della matricola %d \n",students[i].matricola);
        scanf("%d",&students[i].eta);
    }
}