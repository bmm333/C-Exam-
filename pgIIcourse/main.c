#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main()
{
    int n=0;
    printf("inserire il numero degli studenti\n");
    scanf("%d",&n);
    Studenti* A=malloc(n*sizeof(Studenti));
    for(int i=0;i<n;i++)
    {
        printf("inserire leta del %d studente\n",i);
        scanf("%d",&A[i].eta);
    }
    Studenti* B = NULL;
    Studenti* C = NULL;
    int nB = 0;
    int nC = 0;
    dividi(A, n, &B, &nB, &C, &nC);
     printf("Studenti minorenni:\n");
    for (int i = 0; i <= nB; i++) {
        printf("%d ", B[i].eta);
    }
    printf("\n");

    printf("Studenti maggiorenni:\n");
    for (int i = 0; i <= nC; i++) {
        printf("%d ", C[i].eta);
    }
    printf("\n");
    free(B);
    free(C);
    free(A);
    return 0;
/*---------------------------------------------INIZIO Chiamate su lista-------------------------------------------------------------*/
    LINK list=NULL;
    int numnodi=6;
    for(int i=0;i<n;i++)
    {
        DATA data=rand()%(6-1+1)+1;
        headinsert(&list,data);
    }
    int k=6,m=1;
    findkth(list,k,m);
    printlis(&list);
}