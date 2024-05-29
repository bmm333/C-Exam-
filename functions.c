#include <stdio.h>
#include <stdlib.h>
#include "recursion_lib.h"

LINK newnode(DATA d){
	LINK p=malloc(sizeof(ELEMENT));
	if(p==NULL)
	{
		printf("Not Enough space in memory");
		return;
	}
	p->data=d;
	p->next=NULL;
	return p;
}
void buildlis_rec(LINK *lis,DATA d[],int len,int pos,int sel){
	if(pos<len)
	{
		if(sel==1)
		{
			tailinsert_rec(lis,d[pos]);
			buildlis_rec(lis,d,len,pos+1,sel);
		}
		else
		{
		headinsert_rec(lis,d[pos]);
		buildlis_rec(lis,d,len,pos+1,sel);
		}
	}
	
	
	
}
void headinsert_rec(LINK *lis,DATA d)
{
/*	if((*lis)==NULL)
	{
		*lis=newnode(d);
	}*/
	LINK p=newnode(d);
	p->next=(*lis);
	*lis=p;
	headinsert_rec(lis,d);
}
void tailinsert_rec(LINK *lis,DATA d)
{
	if((*lis)==NULL)
	{
		lis=newnode(d);
	}
	else
	{
		tailinsert_rec(&((*lis)->next),d);
	}
}
void printlis_rec(LINK lis){
	if(lis!=NULL)
	{
		printf(">>>>%d",lis->data);
		printlis_rec(lis->next);
	}
}

int sumnodes_rec(LINK *lis)
{
	if(*lis==NULL)
	{
		return 0;
	}
	return (*lis)->data + sumnodes_rec((*lis)->next);
}
int findbiggestcouple_rec(LINK lis)
{
	if(lis==NULL || lis->next==NULL)
	{
		return 0;
	}
	int maxcurr = lis->data + lis->next->data;
	int max = findbiggestcouple_rec(lis->next);
	if(maxcurr>max)
	{
		return maxcurr;
	}
	else
	{
		return max;
	}
}
LINK reverselist_rec(LINK lis)
{
	if(lis==NULL)
	{
		return NULL;
	}
	LINK rest = reverselist_rec(lis->next);
	lis->next->next=lis;
	lis->next=NULL;
	return rest;
}
LINK mergelists_rec(LINK l1,LINK l2)
{
	if(l1==NULL)
	{
		return l2;
	}
	if(l2==NULL)
	{
		return l1;
	}
	if(l1->data<l2->data)
	{
		l1->next=mergelists_rec(l1->next,l2);
		return l1;
	}
	else
		l2->next=mergelists_rec(l1,l2->next);
	    return l2;
}

int sumoflis_rec(LINK lis)
{
	if(lis==NULL)
	{
		return 0;
	}

	return lis->data+sumoflis_rec(lis->next);
}

int productlis_rec(LINK lis)
{
	if(lis==NULL)
	{
		return 1;
	}

	return lis->data * productlis_rec(lis->next); 
}
