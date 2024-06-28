#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "lib.h"
#include <time.h>
#define MAX_VOTI 10


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
        students[i].matricola=rand() % (200599 + 1 - 200100) + 200100;
        printf("inseire il nome della matricola %d \n",students[i].matricola);
        scanf("%s",students[i].nome);
        printf("inseire il cognome della matricola %d \n",students[i].matricola);
        scanf("%s",students[i].cognome);
        printf("inseire leta della matricola %d \n",students[i].matricola);
        scanf("%d",&students[i].eta);
        printf("Quanti voti voelte inserire ?\n");
        scanf("%d",&students[i].num_voti);
        float somma_voti=0;
         while (students[i].num_voti <= 0 || students[i].num_voti > MAX_VOTI) {
            printf("Il numero di voti deve essere compreso tra 1 e %d. Reinserire: \n", MAX_VOTI);
            scanf("%d", &students[i].num_voti);
        }
        for (int j = 0; j < students[i].num_voti; j++) {
            printf("Inserire il voto %d per lo studente %s: \n", j + 1, students[i].nome);
            scanf("%f", &students[i].voti[j]);
            somma_voti += students[i].voti[j];
        }

        students[i].media =(float) somma_voti / students[i].num_voti;
    }
}
void studentsout(Student* students,int ns)
{
    for(int i=0;i<ns;i++)
    {
        printf("Matricola: %d\nNome: %s\nCognome: %s\nEta: %d\nMedia:%.2f\n",students[i].matricola,students[i].nome,students[i].cognome,students[i].eta,students[i].media);
        for(int j=0;j<students[i].num_voti;j++)
        {
            printf("Voti della matricola %f\n",students[i].voti[j]);
        }
    }
}
void inserisciProdotti(Prodotto* prodotti, int num_prodotti)
{
    for (int i = 0; i < num_prodotti; i++) 
    {
        if (prodotti[i].codice != -1) {
            // Skip if the product is already initialized
            continue;
         }
        printf("Inserisci il nome del prodotto %d: ", i + 1);
        scanf("%s", prodotti[i].nome);
        printf("Inserisci il codice del prodotto %d: ", i + 1);
        scanf("%d", &prodotti[i].codice);
        printf("Inserisci la quantita' del prodotto %d: ", i + 1);
        scanf("%d", &prodotti[i].quantita);
        printf("Inserisci il prezzo del prodotto %d: ", i + 1);
        scanf("%f", &prodotti[i].prezzo);
    }
}

void stampaprodotti(Prodotto* prodotti,int nump)
{
    for (int i = 0; i < nump; i++) {
        if (prodotti[i].codice == -1) {
            // Skip uninitialized products
            continue;
        }
        printf("Prodotto %d:\n", i + 1);
        printf("Nome: %s\nCodice: %d\nQuantita': %d\nPrezzo: %.2f\n",
               prodotti[i].nome, prodotti[i].codice, prodotti[i].quantita, prodotti[i].prezzo);
    }
}

LINK uploadtolist(LINK* lis, char* nome) {
    int value;
    FILE* fp = fopen(nome, "r");
    if (!fp) {
        printf("cannot open file\n");
        exit(3);
    }
    LINK head = NULL;
    LINK tail = NULL;
    printf("Reading data from file...\n");
    while (fscanf(fp, "%d", &value) != EOF) {
        printf("Read value: %d\n", value);
        LINK p = (LINK)malloc(sizeof(ELEMENT));
        if (!p) {
            fprintf(stderr, "Cannot allocate memory for new node\n");
            exit(4);
        }
        p->data = value;
        p->next = NULL;
        if (!head) {
            head = p;
            tail = p;
            printf("Initialized head with value: %d\n", head->data);
        } else {
            tail->next = p;
            tail = p;
            printf("Appended value %d to the list\n", p->data);
        }
    }
    fclose(fp);
    printf("Data read from file successfully.\n");
    return head;
}
void printlist(LINK lis)
{
    while(lis)
    {
        printf(">>>%d\n",lis->data);
        lis=lis->next;
    }
}
LINK newnode(DATA d)
{
    LINK p=malloc(sizeof(ELEMENT));
    if(!p)
    {
        fprintf(stderr,"Error cannot allocate memory for new node\n");
        exit(3);
    }
    p->data=d;
    p->next=NULL;
    return p;
}
void headinsert(DATA d,LINK* lis)
{
    LINK temp=*lis;
    temp->next=*lis;
    *lis=temp;
}

int maxprod(int *array,int arrsize)
{
    int max=0;
    int curr=0;
    for(int i=0;i<arrsize-1;i++)
    {
        curr=array[i]*array[i+1];
        if(curr>max)
        {
            max=curr;
        }
    }
    return max;
}

int commonlength(LINK l1,LINK l2)
{
    int cnt=0;
    int max=0;
    if(l1->next||l2->next)
    {
        while(l1&&l2)
        {
            if (l1->data == l2->data)
        {
            cnt++;
            if (cnt > max)
            {
                max = cnt;
            }
            }
            else
            {
                cnt = 0;
            }
            l1=l2->next;
            l2=l2->next;
        }
    }
    return max;
}

LINK deletekm(LINK* l1,int* cnt,int k,int m)
{
    if((*l1)==NULL)
    {
        return NULL;
    }
    if((*cnt)%k==0&&(*l1)->data%m==0)
    {
        LINK temp=*l1;
        (*l1)=(*l1)->next;
        free(temp);
        return deletekm(l1,cnt,k,m);
    }
    else
    {
        (*cnt)++;
        (*l1)->next=deletekm(&((*l1)->next),cnt,k,m);
        return *l1;
    }
}