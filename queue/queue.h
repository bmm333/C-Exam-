#include <stdio.h>
#include <stdlib.h>
#include "../recursion_lib.h"


typedef struct QUEUE{
    LINK front;
    LINK rear;
    int cnt;
}queue;

typedef queue* que;

int isempty_q(que q);
void front(DATA *out,que q);
void clear_q(que q);
void enqueue(DATA,que q);
void dequeue(DATA *out, que q);