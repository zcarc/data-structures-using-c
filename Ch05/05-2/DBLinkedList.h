#ifndef __DB_LINKED_LIST_H__
#define __DB_LINKED_LIST_H__

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
	struct _node * prev;
} Node;

typedef struct _dbLinkedList
{
	Node * head;
	Node * tail;
	Node * cur;
	int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data); // 꼬리에 노드를 추가

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);

Data LRemove(List * list); // 앞서 참조가 이뤄진 노드를 삭제
int LCount(List * plist);

#endif