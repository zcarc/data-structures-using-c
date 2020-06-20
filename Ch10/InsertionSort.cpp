//
// Created by zcarc on 2020-06-20.
//

#include <stdio.h>

void InsertSort(int arr[], int n) {
    int i, j;
    int insData;

    for (i = 1; i < n; i++) {

        insData = arr[i]; // 정렬대상을 insData에 저장

        for (j = i - 1; j >= 0; j--) {
            if (arr[j] > insData)
                arr[j + 1] = arr[j];
            else
                break;
        }


        arr[j + 1] = insData;
        printf("arr[j + 1]: %d\n", arr[j + 1]);
    }
}

int main(void) {

    int arr[5] = {5, 3, 2, 4, 1};
    int i;

    InsertSort(arr, sizeof(arr) / sizeof(int));

    for(i = 0; i < 5; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}

// 5 3 2 4 1
// 5 5 2 4 1
// 3 5 2 4 1

// 3 5 5 4 1
// 3 3 5 4 1
// 2 3 5 4 1

// 2 3 5 5 1
// 2 3 4 5 1

// 2 3 4 5 5
// 2 3 4 4 5
// 2 3 3 4 5
// 2 2 3 4 5
// 1 2 3 4 5
