#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node* LINK;

int secondLongst(char *v);
int sumOdd(int n);
void cancellakm(LINK *head, int k, int m);
void printList(LINK head);

typedef struct ListNode {
    float value;
    struct ListNode* next;
} ListNode;

typedef ListNode ELEMENT;
typedef ELEMENT* LIST;

void list_to_array(LIST list, float v[], int index);
float EMA(float v[], float alpha, int index);

void splitList(LINK lis, LINK* frontRef, LINK* backRef);
LINK mergesortedlists(LINK a, LINK b);
void mergeSort(LINK* lis);