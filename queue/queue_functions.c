#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int isempty_q(que q)
{
    return (q->cnt==0);
}
void front(DATA *out,que q)
{
    if(!isempty_q(q))
    {
        *out=q->rear->data;
    }
}
void clear_q(que q)
{
  q->cnt= 0;
  disposelis(&(q->front));
  q->front = NULL;
  q->rear= NULL;
}
void enqueue(DATA i,que q)
{
    if(!isempty_q(q))
    {
        headinsert_rec(&(q)->front,i);
        
    }
}
void dequeue(DATA *out, que q)
{
    if(!isempty_q(q))
    {

    }
}