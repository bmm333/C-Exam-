#include <stdio.h>
#include <stdlib.h>
#include "exam_library.h"

int main()
{
	LINK list = NULL;
	LIST list = NULL;
	int length = 5; // Lunghezza della lista
    float values[length];
    list_to_array(list, values, 0);

    // Calcolare l'EMA
    float alpha = 0.5;
    EMA(values, alpha, length - 1);
    int k, m;
    int array[20];
	secondLongest(array);
	sumOdd(5);
    // Example to load the list from input (you could also load from a file)
    int values[] = {11, 1, 3, 9, 7, 11, 4};
    int size = sizeof(values) / sizeof(values[0]);
    for (int i = size - 1; i >= 0; i--) {
        insert(&list, values[i]);
    }

    printf("Inserisci il valore di k: ");
    scanf("%d", &k);
    printf("Inserisci il valore di m: ");
    scanf("%d", &m);

    printf("Lista originale: ");
    printList(list);

    cancellakm(&list, k, m);

    printf("Lista dopo la cancellazione: ");
    printList(list);
	return 0;
}