#include <stdio.h>
#include <stdlib.h>

/*
    gcc t2.c -o t2
    ./t2
    Insertion sort:
        Input: 50, 70, 30, 2, 40, 24, 19, 60
        Result: 2, 19, 24, 30, 40, 50, 60, 70
        Comparisons: 17

*/

void swp (int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int inssort (int *ip, int c) {
    int i = 1;
    int j;
    int cyc = 0;
    while(i < c) {
        j = i;
        while(j > 0 && ip[j - 1] > ip[j]) {
            swp(&ip[j], &ip[j - 1]);
            j = j - 1;
            cyc++;
        }
        i++;
    }
    return cyc;
}


int main () {
    int t[8] = { 50, 70, 30, 2, 40, 24, 19, 60 };
    int cycles = inssort(t, 8);

    printf("Insertion sort:\n\tInput: 50, 70, 30, 2, 40, 24, 19, 60\n\tResult: ");

    for(int i = 0; i < 8; i++) {
        printf("%i", t[i]);
        if(i != 7) {
            printf(", ");
        }
    }
    printf("\n\tComparisons: %i\n", cycles);
    return 0;
}