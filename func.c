#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

LINK newnode(DATA d){
	LINK p=malloc(sizeof(ELEMENT));
	if(p==NULL)
	{
		printf("Error cannot allocate memory for new node\n");
	}
	p->data=d;
	p->next=NULL;
	return p;
}

void headinsert(LINK *lis,DATA d)
{
	LINK p=newnode(d);
	p->next=*lis;
	*lis=p
}

void tailinsert(LINK *lis,DATA d)
{
	LINK tail=newnode(d);
	if(*lis==NULL)
		*lis=tail;
	while(*lis!=NULL)
	{
		*lis=(*lis)->next;
	}
	tail->next=NULL;
	*lis->next=tail;
	return lis;
}
void buildlist(LINK *lis,DATA d,int ch)
{
	if(ch==1)
	{
		headinsert(&lis,d);
	}
	else
		tailinsert(&lis,d);
}
void printlist(LINK *lis){
	if(*lis==NULL)
	{
		return;
	}
	while(*lis)
	{
		printf(">>>%d\n",(*lis)->data);
		(*lis)=(*lis)->next;
	}

}

void insertbefore(LINK *lis,DATA x,DATA d)
{
	LINK p=*lis;
	if(p==NULL)
		return;
	else
	{
		while(p->next!=NULL)
		{
			if(p->next->data==x)
			{
				LINK temp=newnode(d);
				temp->next=p->next;
				p->next=temp;
				return;
			}
			p=p->next;
		}
		printf("elemento non trovato\n");
	}

}

void incrementa(LINK lis)
{
	if(lis==NULL)
	{
		printf("lista vuota\n");
		return;	
	}
	while(lis)
	{
		lis->data+=1;
		lis=lis->data;
	}
}

void printgreater(LINK lis,DATA k)
{
	while(lis)
	{
		if(lis->data==k)
		{
			printf(">>>%d\n",lis->data);
		}
		lis=lis->next;
	}
}

void removefirstnode(LINK *lis){
	LINK p=*lis;
	if(p)
	{
		*lis=(*lis)->next;
		free(p);
	}
}

void removelast(LINK *lis)
{
	LINK p;
	if(p)
	{
		if(p->next==NULL)
		{
			*lis=NULL;
			free(p);
		}
		else
		{
			while(p->next->next!=NULL)
				p=p->next;
				free(p->next);
				p->next=NULL;
		}
	}
}

void deletelist(LINK *lis)
{
	LINK p;
	while(*lis)
	{
		p=*lis;
		*lis=(*lis)->next;
		free(p);
	}

}

void duplist(LINK lis)
{
	LINK p,head,tail;
	head==NULL;
	if(lis==NULL)
		return;
	else
	{
		while(lis)
		{
			p=newnode(lis->data);
			if(head==NULL)
				head=p;
				tail=p;
			else
				tail->next=p;
				tail=p;
			lis=lis->next;
		}
	}
	return head;
}
LINK duplistcn(LINK lis,int x)
{
	LINK p,head,tail;
	head=NULL;
	while(lis)
	{
		if(lis->data==x)
		{
			p=newnode(lis->data);
			if(head==NULL)
			{
				head=p;
				tail=p;
			}
			else
			{
				tail->next=p;
				tail=p;
			}
		}lis=lis->next;
	}
	return head;
}

void insertat(LINK *lis,int position,DATA d)
{
	LINK p=*lis;
	int cnt=0;
	if(p==NULL)
	{
		return;
	}
	while(p)
	{
		cnt++;
		if(cnt==position)
		{
			LINK temp=newnode(d);
			temp->next=p->next;
			p->next=temp;
		}
		p=p->next;
	}
}

void deleteposition(LINK *lis,int pos)
{
	if(*lis==NULL)
	{
		return;
	}
	int cnt=0;
	while(*lis&&(*lis)->next!=NULL)
	{
		cnt++;
		if((cnt+1)==pos)
		{
			LINK temp=p;
			p=p->next->next;
			free(temp);
		}
		p=p->next;
	}

}

void reverse(LINK *lis)
{
	if(*lis==NULL)
		return;
	LINK prev=NULL,node=*lis,curr=*lis;
	while(*lis)
	{
		node->next=prev;
		curr=curr->next;
		prev=node;
		node=curr;
	}
	head=curr;
	return head;
}

void printrec(LINK lis)
{
	if(lis)
		printf(">>>>%d",lis->data);
		printrec(lis->next);
	return;
}

LINK searchrec(LINK *lis,DATA d)
{
	if(*lis==NULL)
		return;
	if(*lis)
	{
		LINK p=*lis;
		if((*lis)->data==d)
		{
			return p;
		}
		searchrec((*lis)->next,d);
	}
	return *lis;
}

DATA sumlistrec(LINK *lis)
{
	if(*lis==NULL)
	{
		return 0;
	}
	if(*lis)
	{
		int sum=0;
		sum+=lis->data;
		sumlistrec(lis->next);
	}
	return sum;
