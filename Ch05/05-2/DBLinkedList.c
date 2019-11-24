#include "DBLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List * plist)
{

    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));

    plist->head->prev = NULL;
    plist->head->next = plist->tail;

    plist->tail->prev = plist->head;
    plist->tail->next = NULL;

    plist->cur = NULL;
    plist->numOfData = 0;

}


void LInsert(List * plist, Data data) // 꼬리에 노드를 추가
{

    Node * newNode = (Node*)malloc(sizeof(Node));
    printf("LInsert newNode: %p\n", newNode);

    newNode->data = data;
    printf("newNode->data = data: %d\n", newNode->data);

    newNode->prev = plist->tail->prev;
    plist->tail->prev->next = newNode;

    newNode->next = plist->tail;
    plist->tail->prev = newNode;


    (plist->numOfData)++;

}


int LFirst(List * plist, Data * pdata)
{

    if(plist->numOfData == 0)
        return 0;

    plist->cur = plist->head->next;
    printf("LFirst plist->cur = plist->head->next: %p\n", plist->cur);
    *pdata = plist->cur->data;
    return 1;
}


int LNext(List * plist, Data * pdata)
{
    printf("LNext\n");
    printf("plist->cur: %p\n", plist->cur);
    if(plist->cur == NULL)
        return 0;


    plist->cur = plist->cur->next;
    printf("plist->cur = plist->cur->next: %p\n", plist->cur);

    *pdata = plist->cur->data;
    printf("*pdata = plist->cur->data: %d\n", *pdata);
    return 1;
}


Data LRemove(List * list) // 앞서 참조가 이뤄진 노드를 삭제
{


    Node * removeNode = list->cur;
    Data tempData = list->cur->data;
    list->cur->next->prev = list->cur->prev;
    list->cur->prev->next = list->cur->next;

    (list->numOfData)--;

    printf("LRemove 삭제후 numOfData: %d\n", list->numOfData);

    if(list->numOfData > 0)
        list->cur = list->cur->prev;

    else
        list->cur = NULL;


    free(removeNode);

    return tempData;
}


int LCount(List * plist)
{
    return plist->numOfData;
}