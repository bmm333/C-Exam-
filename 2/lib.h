#include <stdio.h>
#include <stdlib.h>


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
Student calcmedia(Student* students,int size);