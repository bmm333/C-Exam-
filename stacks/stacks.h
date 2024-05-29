#include <stdio.h>
#include <stdlib.h>
#include "recursion_lib.h"

#define MAXLEN 1000
#define EMPTY -1
#define FULL MAXLEN -1

typedef int DATA;

typedef struct Stack
{
    LINK top;
    int cnt;
    int back
    
}stack;

int isEmpty_s(stack *stk);
