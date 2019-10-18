#include <stdio.h>
#include <stdlib.h>

/*
    gcc t1.c -o t1
    ./t1
    Sekoita:
        Viesti: 79, 73, 75, 69, 65
        Avain: 1, 3, 0, 4, 2
        Tulos: 75, 79, 65, 73, 69

    ohjelma sekoittaa taulun avaimen mukaan
*/


int *sekoita (int *v, int *avain, int c) {
    int *tulos = malloc(c * sizeof(int));
    for(int k = 0; k < c; k++) {
        int paikka = avain[k];
        tulos[paikka] = v[k];
    }
    return tulos;
}

int main () {
    printf("Sekoita:\n\tViesti: 79, 73, 75, 69, 65\n\tAvain: 1, 3, 0, 4, 2\n\tTulos: ");
    int viesti[5] = { 79, 73, 75, 69, 65 };
    int avain[5] = { 1, 3, 0, 4, 2};
    int *tulos = sekoita(viesti, avain, 5);
    for(int i = 0; i < 5; i++) {
        printf("%i", tulos[i]);
        if(i != 4) {
            printf(", ");
        }
    }
    printf("\n");
    free(tulos);
    return 0;
}