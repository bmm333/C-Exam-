#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    LINK list=NULL;
    int num=0;
    /* printf("Input the number of elements to insert on the list\n");
    scanf("%d",&num);*/
    headinsert(&list,1);
    headinsert(&list,6);
    headinsert(&list,6);
    headinsert(&list,6);
    headinsert(&list,6);
    headinsert(&list,8);
    headinsert(&list,8);
    printlist(list);
    /*deleteelement(&list,6);
    printlist(list);*/
    printf("List length: %d\n",listlength(list));
    reverse(&list);
    printlist(list);
    printf("Middle of list: %d\n", middleoflist(&list)->data);
    LINK l2=NULL;
    headinsert(&l2,5);
    headinsert(&l2,2);
    mergesortedlists(list,l2);
    printlist(list);
    removedup(&list);
    printf("List after duplicates removed\n");
    printlist(list);
}