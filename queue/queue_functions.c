#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int isempty_q(que q)
{
    return (q->cnt==0);
}
void front(DATA *out,que q)
{
    if(!isempty_q)
    {
        *out=q->rear->data;
    }
}
