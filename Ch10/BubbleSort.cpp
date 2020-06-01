//
// Created by zcarc on 2020-06-01.
//
#include <stdio.h>

void bubbleSort(int a[], int length) {
    int tmp;

    for(int i=0; i<length-1; i++) {
        for(int j=0; j<(length-i)-1; j++) {
            if(a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main () {

    int a[4] = {2, 3, 4, 1};

    bubbleSort(a, sizeof(a) / sizeof(int));

    for(int i=0; i<4; i++)
        printf("%d ", a[i]);

    return 0;
}