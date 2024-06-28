#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int cons(int* array,int len)
{
	int max=0;
	for(int i=0;i<len-1;i++)
	{
		if(max<array[i]+array[i+1])
			max=array[i]+array[i+1];
	}
	if(max!=0)
		return max;
	else
		return 0;
}

float ema(float alpha, float arr[], int i) {
    if (i == 0) {
        return arr[0];
    } else {
        return alpha * arr[i] + (1 - alpha) * ema(alpha, arr, i - 1);
    }
}
LINK newnode(DATA d)
{
	LINK p=malloc(sizeof(ELEMENT));
	if(p==NULL)
	{
		fprintf(stderr,"Error cannot allocate memory\n");
		exit(EXIT_FAILURE);
	}
	p->data=d;
	p->next=NULL;
	return p;
}
void headinsert(LINK* lis,DATA d){
	LINK temp=newnode(d);
	temp->next=(*lis);
	(*lis)=temp;
}
void buildinsert(LINK* lis){
	char f[100];
	printf("Filename:\n");
	scanf("%s",f);
	FILE* fp=fopen(f,"r");
	if(fp==NULL)
	{
		fprintf(stderr,"Error usage <%s>",f);
		exit(EXIT_FAILURE);
	}
	int val=0;
	while(fscanf(fp,"%d",val)!=EOF)
	{
		if(val>0)
		{
			headinsert(lis,val);
		}
	}
	fclose(fp);
}
void cancellak(LINK* lis,int k,int m)
{
	if(lis==NULL)
		return;
	LINK curr=(*lis);
	LINK prev=NULL;
	int cnt=0;
	while(curr!=NULL)
	{ 
		 cnt++;
		 if((cnt%k==0)&&(curr->data%m==0))
		 {
			LINK temp=curr;
			if(prev==NULL)
			{
				*lis=curr->next;
			}
			else{
				prev->next=curr->next;
			}
			curr=curr->next;
			free(temp);
		 }
		 else{
			prev=curr->next;
			curr=curr->next;
			cnt++;
		 }
	}
}