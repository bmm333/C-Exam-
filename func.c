#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void insertc(citta* city){
	printf("Insert population:\n");
	scanf("&d",&city->popolazione);
	printf("insert nome della citta\n");
	char name[100];
	scanf("%s",name);
	city->nome=strdup(name);
}
void second(citta* city,int len){
	if(len<2)
	{
		printf("inserire piu di due citta\n");
		exit(2);
	}
	int max=-1;
	int min=-1;
	int indexmin=-1;
	int indexmax=-1;
	for(int i=0;i<len;i++)
	{
		if(max<citta[i]->popolazione)
		{
			min=max;
			indexmin=indexmax;
			max=citta[i]->popolazione;
			indexmax=i;
		}
		else if(citta[i]->popolazione>min&&citta[i]->popolazione!=max)
		{
			min=citta[i]->popolazione;
			indexmin=i;
		}
	}
	if(indexmin==-1)
	{
		printf("non esiste una citta seconda piu grande\n");
	}
	else
	{
		printf("Seconda citta piu grande e : %s con %d popolazione \n",citta[indexmin].nome,citta[indexmin].popolazione);
	}
}

LINK newnode(DATA d)
{
	LINK p=malloc(sizeof(ELEMENT));
	if(!p)
	{
		fprintf(stderr,"error cannot allocate memory for new node");
		exit(3);
	}
	p->data=d;
	p->next=NULL;
	return p;
}

void headinsert(LINK* lis,DATA d)
{
	LINK temp=newnode(d);
	temp->next=(*lis);
	(*lis)=temp;
}

void tailinsert(LINK* lis,DATA d)
{
	if(!(*lis))
		*lis=newnode(d);
	LINK curr=(*lis);
	while(curr)
	{
		curr=curr->next;
	}
	curr->next=newnode(d);
}

LINK buildlist(LINK* lis,char nome)
{
	FILE* fp=fopen(nome,"r");
	if(!fp)
	{
		fprintf("cannot open file check permission/path\n");
		exit(4);
	}
	int val=0;
	while(fscanf(fp,"%d",&val)!=EOF)
	{
		if(val>0)
		{
			headinsert(&lis,val);
		}
	}
	return *lis;
}
void printlis(LINK lis)
{
	if(lis)
	{
		printlis(lis->next);
		printf(">>>%d",lis->data);
	}
}

LINK merge(LINK lis,int k)
{
	if(!lis)
	{
		return NULL;
	}
	LINK p=NULL,tail=NULL;
	while(lis)
	{
		if(lis->data%k==0)
		{
			LINK temp=newnode(lis->data);
			if(!p)
			{
				p=temp;
				tail=p;
			}
			else
			{
				tail->next=temp;
				tail=tail->next;
			}
		}
	}
	return p;
}

int maxsub(LINK l1,LINK l2)
{
	if(!l1)
		return l2;
	if(!l2)
		return l1;
	if(l1->data==l2->data)
	{
		return 1+maxsub(l1->next,l2->next);
	}
	return maxsub(l1->next,l2->next);
}