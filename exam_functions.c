#include <stdio.h>
#include <stdlib.h>
#include "exam_library.h"

int secondLongst(char *v)
{
	int n , maxcurrent = 0,index=-1,lenstring;
	printf("Numero di nomi da inserire:\n ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("insert %d name:\n",i+1);
		scanf("%s",v[i]);
		lenstring= strlen(v[i]);
		if(maxcurrent<lenstring)
		{
			maxcurrent=lenstring;
			index=i;
		}
	}
	if(index!=-1)
	{
			printf("The longest name is %s\n"v[index]);
	}
	else
	{
		printf("No names entred\n");
	}

}
int sumOdd(int n) {
    // Caso base: se n è 1, la somma è 1
    if (n == 1) {
        return 1;
    }
    // Caso ricorsivo: utilizzare la formula S(n) = S(n-1) + (2n - 1)
    else {
        return sumOdd(n - 1) + (2 * n - 1);
    }
}

void cancellakm(LINK *head, int k, int m) {
    int n = 1;  // Start counting from 1 for the first node

    while (*head != NULL) {
        if (n % k == 0 && (*head)->data % m == 0) {
            LINK temp = *head;
            *head = (*head)->next;
            free(temp);
        } else {
            head = &((*head)->next);
        }
        n++;
    }
}

// Function to print the list
void printList(LINK head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) {
            printf("-->");
        }
        head = head->next;
    }
    printf("\n");
}

void list_to_array(LIST list, float v[], int index) {
    if (list == NULL) {
        return;
    }
    v[index] = list->value;
    list_to_array(list->next, v, index + 1);
}

// Funzione ricorsiva per calcolare l'EMA
float EMA(float v[], float alpha, int index) {
    if (index == 0) {
        printf("EMA(%d) = %.2f\n", index, v[0]);
        return v[0];
    }
    float ema_previous = EMA(v, alpha, index - 1);
    float ema_current = alpha * v[index] + (1 - alpha) * ema_previous;
    printf("EMA(%d) = %.2f\n", index, ema_current);
    return ema_current;
}

void split(LINK lis, LINK* firsthalf, LINK* ndhalf)
{
	LINK fast;
	LINK slow;
	slow = lis;
	fast = lis->next;

	while (fast != NULL)//Scrolling the list
	{
		fast = fast->next; // e 2 step avanti rispetto slow -
		if (fast != NULL) // cosi quando fast==null; slow=middle of list
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*firsthalf = lis;//paritamo dal head della lista
	*ndhalf = slow->next; // partiamo dal next of middle 
	slow->next = NULL; //faccio finire la prima half del list
}

LINK mergesortedlists(LINK l1, LINK l2)
{
	LINK res = NULL;
	if (l1 == NULL) //stessa logic del es fatto in classe 
		return l2;
	else if (l2 == NULL)
		return l1;
	if (l1->data <= l2->data)
	{
		res = l1;
		res->next = mergesortedlists(l1->next, l2);
	}
	else
	{
		res = l2;
		res->next = mergesortedlists(l1, l2->next);
	}
	return res;
}
void mergesort(LINK* lis)
{
	LINK head = *lis;
	LINK l1;
	LINK l2;

	split(head, &l1, &l2);
	mergesort(&l1);
	mergesort(&l2);
	*lis = mergesortedlists(l1, l2);

}

/*No auxi space, uttilizando i next pointers dei nodi per fare il merge 
senza uttilizare extra space */