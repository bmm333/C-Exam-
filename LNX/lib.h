#include <stdio.h>
#include <stdlib.h>

typedef int DATA;
typedef struct lista
{
	DATA data;
	struct lista* next;
} ELEMENT;
typedef ELEMENT* LINK;

LINK newnode(DATA d);
void headinsert(LINK *lis, DATA d);
void tailinsert(LINK *lis, DATA d);
void buildlist(LINK *lis, DATA d, int ch);
void printlist(LINK lis);
void insertbefore(LINK *lis, DATA x, DATA d);
void incrementa(LINK lis);
void printgreater(LINK lis, DATA k);
void removefirstnode(LINK *lis);
void removelast(LINK *lis);
void deletelist(LINK *lis);
LINK duplist(LINK lis);
LINK duplistcn(LINK lis, int x);
void insertat(LINK *lis, int position, DATA d);
void deleteposition(LINK *lis, int pos);
void reverse(LINK *lis);
void printrec(LINK lis);
LINK searchrec(LINK lis, DATA d);
DATA sumlistrec(LINK lis);

// Additional function prototypes for recursion exercises
int listLengthRecursively(LINK head);
int countOccurrencesRecursively(LINK head, DATA data);
LINK reverseListRecursively(LINK head);
DATA findMaxRecursively(LINK head);
DATA findMinRecursively(LINK head);
bool isPalindromeRecursively(LINK head);
LINK mergeSortedListsRecursively(LINK list1, LINK list2);

