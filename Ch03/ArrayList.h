#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "03-2/NameCard.h"

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100

typedef NameCard * LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
// typedef 된 ArrayList를 다시 typedef를 하는 이유는
// typedef LinkedList List;로 변경할 수도 있다.
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif