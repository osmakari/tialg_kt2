#include <stdio.h>
#include <stdlib.h>

/*
    A:
        luvut: [9, 3, 11, 2]
        1. sykli
            9 > 3: swapataan, luvut nyt [3, 9, 11, 2]
            9 < 11: ei swappia
            11 > 2: swapataan, luvut nyt [3, 9, 2, 11]
        2. sykli
            3 < 9: ei swappia
            9 > 2: swapataan, luvut nyt [3, 2, 9, 11]
            9 < 11: ei swappia
        3. sykli
            3 > 2: swapataan, luvut nyt [2, 3, 9, 11]
            3 < 9: ei swappia
            9 < 11: ei swappia
        4. syklillä ei tule swappeja joten looppi pysähtyy ja tulos on
        [2, 3, 9, 11]

    B:
        pahimmassa tapauksessa 2500 vertausta, parhaimmassa tapauksessa 50 vertausta


    ***********************************

    gcc t3.c -o t3
    ./t3 
    Bubble sort:
        Input: 9, 3, 11, 2
        Result: 2, 3, 9, 11
*/


void swp (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubblesort (int *ip, int c) {
    int sw = 0;
    do {
        sw = 0;
        for(int i = 1; i < c; i++) {
            if(ip[i - 1] > ip[i]) {
                swp(&ip[i - 1], &ip[i]);
                sw = 1;
            }
        }
    } while(sw);
}


int main () {
    int t[4] = { 9, 3, 11, 2 };
    bubblesort(t, 4);
    printf("Bubble sort:\n\tInput: 9, 3, 11, 2\n\tResult: ");

    for(int i = 0; i < 4; i++) {
        printf("%i", t[i]);
        if(i != 3) {
            printf(", ");
        }
    }
    printf("\n");
    return 0;
}