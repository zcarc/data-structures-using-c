#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
}

void LInsert(List * plist, LData data)
{
	if (plist->numOfData > LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)
		return FALSE;

	printf("LNext... curPostion 증가 전 curPosition %d \n", plist->curPosition);
	(plist->curPosition)++;
	printf("LNext... curPostion 증가 후 curPosition %d \n", plist->curPosition);
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;

	printf("삭제할 curPositon: %d \n", rpos);

	int num = plist->numOfData;
	printf("현재 numOfData: %d \n", num);

	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++) {
		printf("인덱스 i+1:  %d \n", i + 1);
		printf("인덱스 plist->arr[i+1]의 값: %d \n", plist->arr[i + 1]);
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}