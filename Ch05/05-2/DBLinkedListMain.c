
#include "DBLinkedList.h"
#include <stdio.h>
#include "stdlib.h"


int main ()
{

    List list;
    Data searched_data;
    Data removedData;
    ListInit(&list);


    printf("list.head:%p\n",list.head);
    printf("list.tail:%p\n",list.tail);

    LInsert(&list, 10);
    LInsert(&list, 20);
    LInsert(&list, 30);
    LInsert(&list, 40);
    LInsert(&list, 50);
    LInsert(&list, 60);
    LInsert(&list, 70);

    printf("데이터 2개 추가 후 리스트 데이터 수: %d\n", LCount(&list));

    if(LFirst(&list, &searched_data))
    {
        printf("첫번째 데이터 조회 결과: %d\n", searched_data);


        for(int i = 0; i < LCount(&list)-1; i++)
        {
            LNext(&list, &searched_data);
            printf("다음 데이터 조회 결과: %d\n", searched_data);
        }
    }


    if(LFirst(&list, &searched_data))
    {
        printf("삭제할 첫번째 데이터 조회 결과: %d\n", searched_data);
        removedData = LRemove(&list);
        printf("삭제된 데이터 %d\n", removedData);

        int count = LCount(&list);
        for(int i = 0; i < count; i++)
        {
            LNext(&list, &searched_data);
            printf("다음 데이터 조회 결과: %d\n", searched_data);
            removedData = LRemove(&list);
            printf("삭제된 데이터 %d\n", removedData);
        }
    }


    printf("데이터 전부 삭제 후 리스트 데이터 수: %d\n", LCount(&list));

    free(list.head);
    free(list.tail);


    return 0;
}