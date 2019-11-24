#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#include "Employee.h"

#define TRUE	1
#define FALSE	0


typedef Employee * Data;
// typedef int Data;

// 여기서 큰 실수를 했다. 이유는
// Node 자체의 구조체는 변경되지 않아야하는데
// Node 구조체 대신에 Employee 라는 새로운 구조체로 Node를 대체했다.
// 새로 만든 Employee 구조체 자체를 Node의 data로 사용해야한다.

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;


typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);
void LInsertFront(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
Data LRemove(List * plist);
int LCount(List * plist);

#endif