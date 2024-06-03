#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
	int n=0;
	LINK list=NULL;
	printf("Inserire la quantita dei nodi da creare:\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int ch;
		printf("insert in tail(1) or head?(2)\n");
		scanf("%d",ch);
		DATA data=rand()%(11-1+1)+1;
		buildlist(&list,data,ch);
	}
	printf("La lista Creata:");
	printlist(list);

}