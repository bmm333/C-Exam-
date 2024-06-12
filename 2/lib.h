#include <stdio.h>
#include <stdlib.h>
#define MAX_VOTI 10


typedef struct ci {
char *nome;
int popolazione;
} Cit;
typedef Cit* City;


void inputCities(City* citta,int n);
Cit secondlargest(City* citta,int n);

typedef struct   {
    char titolo[100];
    char autore[100];
    int anno_pubblicazione;
} Libro;

void insertbooks(Libro* bibloteca,int bsize);
Libro ultimo(Libro* bibloteca,int bsize);

typedef struct {
    char nome[100];
    char cognome[100];
    int eta;
    int matricola;
    float voti[MAX_VOTI];
    int num_voti;
    float media;
}   Student;

void insertstudents(Student* students,int size);
void studentsout(Student* students,int ns);

typedef struct
{
    char nome[50];
    int codice;
    int quantita;
    float prezzo;
}   Prodotto;

void inserisciProdotti(Prodotto* prodotti, int num_prodotti);
void stampaprodotti(Prodotto* prodotti,int nump);

typedef int DATA;
typedef struct linkedlist
{
    DATA data;
    struct linkedlist* next;
}   ELEMENT;
typedef ELEMENT* LINK;

LINK uploadtolist(LINK* lis,char* nome);
void printlist(LINK lis);
int maxprod(int *array,int arrsize);
