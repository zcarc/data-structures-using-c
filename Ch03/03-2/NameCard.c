//
// Created by zcarc on 2019-11-06.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"


// NameCard 구조체 변수의 동적 할당 및 초기화 후 주소 값 반환
NameCard * MakeNameCard(char * name, char * phone) {

    NameCard * nameCard = (NameCard *)malloc(sizeof(NameCard));
    strcpy(nameCard->name, name);
    strcpy(nameCard->phone, phone);

    return nameCard;
}


// NameCard 구조체 변수의 정보 출력
void ShowNameCardInfo(NameCard * pcard){

    printf("name: %s \n", pcard->name);
    printf("phone: %s \n", pcard->phone);
}


// 이름이 같으면 0, 다르면 0이 아닌 값 반환
int NameCompare(NameCard * pcard, char * name){

    // 내가 쓴 답
//    if(strcmp(pcard->name, name) == 0){
//        return 0;
//
//    } else {
//        return -1;
//    }

    // 정답지의 답
    // 둘 다 같은 경우에만 0을 반환하니 이런 답이 나온 것 같다.
    return strcmp(pcard->name, name);

}


// 전화번호 정보를 변경
void ChangePhoneNum(NameCard * pcard, char * phone){

    strcpy(pcard->phone, phone);
}