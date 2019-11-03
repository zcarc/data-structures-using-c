//
// Created by zcarc on 2019-11-04.
// 문제 03-1 (p.85)
//

#include <stdio.h>
#include "ArrayList.h"

int main ()
{
    List list;
    int data;

    ListInit(&list);


    for(int i = 1; i < 10; i++) {
        LInsert(&list, i);
    }

    printf("현재 데이터 수: %d\n", LCount(&list));

    if( LFirst(&list, &data) ) {
        printf("첫번째 result: %d \n", data);
        if(data % 2 == 0 || data % 3 == 0) {
            LRemove(&list);
        }


        while( LNext(&list, &data) ){
            printf("연이은 result: %d \n", data);
            if(data % 2 == 0 || data % 3 == 0) {
                LRemove(&list);
            }

        }
    }

    printf("현재 데이터 수: %d\n", LCount(&list));

    if( LFirst(&list, &data) ) {
        printf("첫번째 result: %d \n", data);


        while( LNext(&list, &data) ){
            printf("연이은 result: %d \n", data);

        }
    }


    return 0;
}