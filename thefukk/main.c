#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    LINK list=NULL;
    int num=0;
    printf("Input the number of elements to insert on the list\n");
    scanf("%d",&num);
    headinsert(&list,1);
    headinsert(&list,6);
    printlist(list);
    /*deleteelement(&list,6);*/
    printlist(list);
    printf("List length: %d\n",listlength(list));
    reverse(&list);
    printlist(list);
    
}