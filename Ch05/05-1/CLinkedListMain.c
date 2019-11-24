#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "CLinkedList.h"

// LFirst() �Լ��� Data�� � ���� �����ؾ��ϴ°� �ƴϰ� �� Data�� ù��° ��尡 ����.

Employee * WhoisDuty(List * list, char * name, int day);
void ShowEmployeeInfo(Employee * data);

int main(void)
{
	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
	List list;
	ListInit(&list);

    Employee * result;

	Employee * employee1 = (Employee*)malloc(sizeof(Employee));
	employee1->number = 1111;
	strcpy(employee1->name, "Kim");

    Employee * employee2 = (Employee*)malloc(sizeof(Employee));
    employee2->number = 2222;
    strcpy(employee2->name, "Park");

    Employee * employee3 = (Employee*)malloc(sizeof(Employee));
    employee3->number = 3333;
    strcpy(employee3->name, "Jung");

    Employee * employee4 = (Employee*)malloc(sizeof(Employee));
    employee4->number = 4444;
    strcpy(employee4->name, "Ahn");

	LInsert(&list, employee1);
    LInsert(&list, employee2);
    LInsert(&list, employee3);
    LInsert(&list, employee4);

    result = WhoisDuty(&list, "Kim", 4);
    if(result != NULL)
        ShowEmployeeInfo(result);






	return 0;
}

Employee * WhoisDuty(List * list, char * name, int day)
{

    Employee * tmp;
    Employee * duty = NULL;

    if(LFirst(list, &tmp))
    {
        if(strcmp(tmp->name, name) == 0)
        {
            for(int i = 0; i < day; i++)
            {
                LNext(list, &duty);
            }

        } else
            {
                if(LNext(list, &tmp))
                {
                    if(strcmp(tmp->name, name) == 0)
                    {
                        for(int i = 0; i < day; i++)
                        {
                            LNext(list, &tmp);
                        }

                    }
                }
            }


    }

    return duty;

}


void ShowEmployeeInfo(Employee * data){

    printf("emp number: %d\n", data->number);
    printf("emp name: %s\n", data->name);
}



// ���
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "CLinkedList.h"
//#include "Employee.h"
//
//Employee * WhosNightDuty(List * plist, char * name, int day);
//void ShowEmployeeInfo(Employee * emp);
//
//int main(void)
//{
//    int i;
//    Employee * pemp;
//
//    // List�� ���� �� �ʱ�ȭ ///////
//    List list;
//    ListInit(&list);
//
//    // 4���� ������ ���� ///////
//    pemp = (Employee*)malloc(sizeof(Employee));
//    pemp->empNum = 11111;
//    strcpy(pemp->name, "Terry");
//    LInsert(&list, pemp);
//
//    pemp = (Employee*)malloc(sizeof(Employee));
//    pemp->empNum = 2222;
//    strcpy(pemp->name, "Jery");
//    LInsert(&list, pemp);
//
//    pemp = (Employee*)malloc(sizeof(Employee));
//    pemp->empNum = 3333;
//    strcpy(pemp->name, "Hary");
//    LInsert(&list, pemp);
//
//    pemp = (Employee*)malloc(sizeof(Employee));
//    pemp->empNum = 4444;
//    strcpy(pemp->name, "Sunny");
//    LInsert(&list, pemp);
//
//    // Terry �ڷ� 3�� �� �����ڴ�? ///////
//    pemp = WhosNightDuty(&list, "Tery", 3);
//    ShowEmployeeInfo(pemp);
//
//    // Sunny �ڷ� 15�� �� �����ڴ�? ///////
//    pemp = WhosNightDuty(&list, "Sunny", 15);
//    ShowEmployeeInfo(pemp);
//
//    // �Ҵ�� �޸��� ��ü �Ҹ� ///////
//    if(LFirst(&list, &pemp))
//    {
//        free(pemp);
//
//        for(i=0; i<LCount(&list)-1; i++)
//        {
//            if(LNext(&list, &pemp))
//                free(pemp);
//        }
//    }
//
//    return 0;
//}
//
//Employee * WhosNightDuty(List * plist, char * name, int day)
//{
//    int i, num;
//    Employee *ret;
//
//    num = LCount(plist);
//
//    // �̸� ã�� ///////
//    LFirst(plist, &ret);
//
//    if(strcmp(ret->name, name) != 0)
//    {
//        for(i=0; i<num-1; i++)
//        {
//            LNext(plist, &ret);
//
//            if(strcmp(ret->name, name) == 0)
//                break;
//        }
//        if(i >= num-1)     // �ش��ϴ� �̸��� �������� ������
//            return NULL;
//    }
//
//    // �� �ڷ� ��ĥ �� ///////
//    for(i=0; i<day; i++)
//        LNext(plist, &ret);
//
//    return ret;
//}
//
//void ShowEmployeeInfo(Employee * emp)
//{
//    printf("Employee name: %s \n", emp->name);
//    printf("Employee number: %d \n\n", emp->empNum);
//}