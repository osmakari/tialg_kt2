#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    gcc t4.c -o t4
    ./t4   

    Run 1
        Left: 0
        Right: 0
    Run 2
        Left: 0
        Right: 0
    Run 3
        Left: 0
        Right: 2
    Run 4
        Left: 2
        Right: 5
    Run 5
        Left: 0
        Right: 0
    Run 6
        Left: 0
        Right: 2
    Run 7
        Left: 0
        Right: 0
    Run 8
        Left: 0
        Right: 2
    Run 9
        Left: 5
        Right: 5
    Run 10
        Left: 12
        Right: 16
    *****************************
    Merge sort:
        Input: 60, 170, 30, 2, 11, 19, 24, 50, 60, 3, 100
        Result: 2, 3, 11, 19, 24, 30, 50, 60, 60, 100, 170
    Total comparisons: 39


*/


int msmerge (int *a, int begin, int middle, int end, int *b) {
    int i = begin;
    int j = middle;

    int tot = 0;

    for(int k = begin; k < end; k++) {

        if(i < middle && (j >= end || a[i] <= a[j])) {
            b[k] = a[i];
            i++;
        }
        else {
            b[k] = a[j];
            j++;
        }
        tot++;
    }

    return tot;
}

int rc = 1;

int splitmerge (int *b, int begin, int end, int *a) {
    if(end - begin < 2) 
        return 0;

    int middle = (end + begin) / 2;

    int cmp1 = splitmerge(a, begin, middle, b);
    int cmp2 = splitmerge(a, middle, end, b);
    int tot = cmp1 + cmp2;

    printf("Run %i\n\tLeft: %i\n\tRight: %i\n", rc, cmp1, cmp2);

    rc++;

    return msmerge(b, begin, middle, end, a) + tot;
}

int mergesort (int *a, int c) {
    int *b = malloc(c * sizeof(int));
    memcpy(b, a, c * sizeof(int));
    int total = splitmerge(b, 0, c, a);

    free(b);
    return total;
}

int main () {
    int t[11] = { 60, 170, 30, 2, 11, 19, 24, 50, 60, 3, 100 };
    int total = mergesort(t, 11);
    printf("*****************************\nMerge sort:\n\tInput: 60, 170, 30, 2, 11, 19, 24, 50, 60, 3, 100\n\tResult: ");

    for(int i = 0; i < 11; i++) {
        printf("%i", t[i]);
        if(i != 10) {
            printf(", ");
        }
    }
    printf("\nTotal comparisons: %i\n", total);

    return 0;
}