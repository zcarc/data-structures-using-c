//
// Created by zcarc on 2019-11-07.
//


#include "../ArrayList.h"
#include <stdio.h>
#include <stdlib.h>

int main () {


    List list;
    NameCard * temp_nameCard;


    ListInit(&list);


    NameCard * nameCard01 = MakeNameCard("visa01", "01011112222");
    LInsert(&list, nameCard01);

    NameCard * nameCard02 = MakeNameCard("master01", "01033334444");
    LInsert(&list, nameCard02);

    NameCard * nameCard03 = MakeNameCard("kakao01", "01055556666");
    LInsert(&list, nameCard03);




    if(LFirst(&list, &temp_nameCard)) {


        // 내가 쓴 답
//        if(NameCompare(temp_nameCard, "master01") == 0) {
//            ShowNameCardInfo(temp_nameCard);
//        }
//
//        while(LNext(&list, &temp_nameCard)) {
//            if(NameCompare(temp_nameCard, "master01") == 0) {
//                ShowNameCardInfo(temp_nameCard);
//            }
//        }

        // 책의 답
        // C언어에서
        // 0은 FALSE
        // 1은 TRUE
        // 서로 같다면 0을 반환 -> 0이면 "TRUE"이어야해서 '!'연산자 사용으로 "TRUE"로 변환
        if(!NameCompare(temp_nameCard, "master01")){
            ShowNameCardInfo(temp_nameCard);

          // 이미 사용자가 나왔으니 아래가 실행될 필요가 없다.
          // 반대로 위의 "if"에서 사용자가 나오지 않을 때만 "else"가 실행되어야 한다.
        } else {
            while(LNext(&list, &temp_nameCard)) {
                if(!NameCompare(temp_nameCard, "master01")){
                    ShowNameCardInfo(temp_nameCard);

                    // 사용자가 나왔으니 "if"가 되어서 더 이상 "while"문을 돌 필요가 없다.
                    break;
                }
            }
        }

    }


    if(LFirst(&list, &temp_nameCard)) {

        // 내가 쓴 답
//        if(NameCompare(temp_nameCard, "kakao01") == 0){
//            ChangePhoneNum(temp_nameCard, "01044445555");
//        }
//
//        while(LNext(&list, &temp_nameCard)) {
//
//            if(NameCompare(temp_nameCard, "kakao01") == 0){
//                ChangePhoneNum(temp_nameCard, "01044445555");
//            }
//        }


        // 책의 답
        if(!NameCompare(temp_nameCard, "kakao01")){
            ChangePhoneNum(temp_nameCard, "01044445555");

        } else {
            while(LNext(&list, &temp_nameCard)) {

                if(!NameCompare(temp_nameCard, "kakao01")){
                    ChangePhoneNum(temp_nameCard, "01044445555");
                    break;
                }
            }
        }



    }


    if(LFirst(&list, &temp_nameCard)) {

        // 내가 쓴 답
//        if(NameCompare(temp_nameCard, "visa01") == 0) {
//            NameCard * removeData = LRemove(&list);
//            free(removeData);
//        }
//
//        while(LNext(&list, &temp_nameCard)) {
//
//            if(NameCompare(temp_nameCard, "visa01") == 0) {
//                NameCard * removeData = LRemove(&list);
//                free(removeData);
//            }
//        }

        // 책의 답
        if(!NameCompare(temp_nameCard, "visa01")) {

            // LFirst() 함수에서 &temp_nameCard 자체의 주소값을 넘겨주고
            // "temp_nameCard"는 현재 배열 기반 리스트의 0번째 인덱스에 동적할당된 NameCard의 주소값을 가리키고 있고
            // 근데 생각을 해보면 이미 LFirst() 함수로 인해서 temp_nameCard가 가리키고 있는 주소 값이
            // 결국에는 LRemove될 대상이다. 그래서
            // LRemove로 데이터를 반환받지 않아도 그 전에 삭제해도 무방할듯 싶다.
            temp_nameCard = LRemove(&list);
            free(temp_nameCard);

        } else {

            while(LNext(&list, &temp_nameCard)) {

                if(NameCompare(temp_nameCard, "visa01") == 0) {
                    NameCard * removeData = LRemove(&list);
                    free(removeData);
                    break;
                }
            }
        }


    }


    if(LFirst(&list, &temp_nameCard)) {

        printf("이름: %s\n", temp_nameCard->name);
        printf("전화번호: %s\n", temp_nameCard->phone);

        while(LNext(&list, &temp_nameCard)) {

            printf("이름: %s\n", temp_nameCard->name);
            printf("전화번호: %s\n", temp_nameCard->phone);
        }
    }



}