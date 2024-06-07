#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    LINK list=NULL;
    headinsert(&list,6);
    printlist(list);
}