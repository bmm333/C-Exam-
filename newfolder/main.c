#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
	int arr[]={1,2,3,4,5,6};
	int* p=arr;
	int max=0;
	int len=sizeof(arr)/sizeof(arr[1]);
	max=cons(arr,len);
	printf("Maximum consecutive sum of 2 numbers is <%d>\n",max);
	float alpha = 0.5;  // Esempio di alpha
    float ar[] = {2.4, 5.1, 0.2, 7.8, 10.0, 0.9};  // Array di esempio
    int n = sizeof(ar) / sizeof(ar[0]);
    for (int i = 0; i < n; i++) {
        float em = ema(alpha, ar, i);
        printf("EMA(%d): %.3f\n", i, em);
    }
	printf("\n");
	LINK lis=NULL;
	buildinsert(&lis);
	cancellak(&lis,2,2);
	return 0;
}
