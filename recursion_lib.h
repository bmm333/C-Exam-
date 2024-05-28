#include <stdio.h>
#include <stdlib.h>

typedef DATA data;

struct lista{
	DATA data;
	struct lista* next;
};
typedef struct lista ELEMENT;
typedef ELEMENT *LINK;

LINK newnode(DATA d);
void buildlis_rec(LINK *lis,DATA d[],int len,int pos,int sel);
void headinsert_rec(LINK *lis,DATA d);
void tailinsert_rec(LINK *lis,DATA d);
void printlis_rec(LINK lis);
void sumnodes_rec(LINK *lis);