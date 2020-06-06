//
// Created by zcarc on 2020-06-07.
//
#include <stdio.h>

void SelectionSort(int a[], int length) {
    int i, j;
    int maxIdx;
    int tmp;

    for(i=0; i<length-1; i++) {
        maxIdx = i;

        for(j=i+1; j<length; j++) { // 최솟값 탐색
            if(a[j] < a[maxIdx]) {
                maxIdx = j;
            }
            printf("j: %d, a[j]: %d \n", j, a[j]);
        }

        // 교환
        tmp = a[i];
        a[i] = a[maxIdx];
        a[maxIdx] = tmp;

    }
    // 1 4 2 3
    // 1 2 4 3
    // 1 2 3 4

}

int main () {

    int a[4] = {3, 4, 2, 1};

    SelectionSort(a, sizeof(a) / sizeof(int));

    for(int i=0; i<4; i++)
        printf("%d ", a[i]);

    return 0;
}