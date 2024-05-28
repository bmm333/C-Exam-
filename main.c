#include <stdio.h>
#include <stdlib.h>
#include "recursion_lib.h"


int main()
{	
	int i=0,idpos=0;
	LINK list = NULL;
	DATA data[]={20,54,13,65};
	int len_array=sizeof(data)/sizeof(data[0]); // dimensione del array
	buildlis_rec(&list,data,len_array,idpos);
	sumnodes_rec(list);
	return 0;
}