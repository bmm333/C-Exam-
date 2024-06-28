#include <stdio.h>
#include <stdlib.h>


typedef int DATA;
typedef struct l{
	DATA data;
	struct l* next;
}ELEMENT;
typedef ELEMENT* LINK;

int cons(int* array,int len);
float ema(float alpha, float arr[], int i);
LINK newnode(DATA d);
void headinsert(LINK* lis,DATA d);
void buildinsert(LINK* lis);
void cancellak(LINK *lis,int k,int m);

