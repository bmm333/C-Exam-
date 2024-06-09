#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main() {
    int num = 0;

    printf("Quante citta volete inserire?\n");
    scanf("%d", &num);

    // Allocate memory for the array of cities
    City* cities = (City*)malloc(num * sizeof(City));

    // Check if the memory allocation was successful
    if (cities == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Temporary buffer for city names
    char buffer[100];

    for (int i = 0; i < num; i++) {
        printf("Inserire nome della citta:\n");
        scanf("%s", buffer);

        // Allocate memory for the city name and copy the buffer
        char* cityName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        if (cityName == NULL) {
            printf("Memory allocation for city name failed\n");
            // Free previously allocated memory before returning
            for (int j = 0; j < i; j++) {
                free((char*)cities[j].nome);
            }
            free(cities);
            return 1;
        }
        strcpy(cityName, buffer);

        // Assign the city name to the cities array
        cities[i].nome = cityName;

        printf("Inserire la popolazione della citta:\n");
        scanf("%d", &cities[i].popolazione);
    }

    // Find the second largest city
    City* secondLargestCity = second(cities, num);
    if (secondLargestCity != NULL) {
        printf("La seconda citta piu grande e': %s con popolazione di %d\n",
               secondLargestCity->nome, secondLargestCity->popolazione);
    }

    // Free the allocated memory for city names and the cities array
    for (int i = 0; i < num; i++) {
        free((char*)cities[i].nome);
    }
    free(cities);

    int cof=0,g=9,k=3;
    cof=coeffbin(g,k);
    printf("il coefficente e %d\n",cof);
/*--LIST Function's start here--------------------------------------------------------------*/
    LINK list=NULL;
    LINK lista=NULL;
    headinsert(&list,4);
    headinsert(&list,3);
    headinsert(&list,0);
    headinsert(&lista,1);
    headinsert(&lista,8);
    headinsert(&lista,2);
    int position=1;
    printf("Somam dei nodi dopo k e %d\n",nodesum(list,lista,position));
    return 0;
}