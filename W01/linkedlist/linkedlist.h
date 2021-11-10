#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// ���� ����� ������ ����
	ListNode *headerNode;		// ��� ���(Header Node) 포인터가 아닌이유???
} LinkedList;

LinkedList* createLinkedList();
ListNode* getLLElement(LinkedList* pList, int position);
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);

void displayLinkedList(LinkedList* pList);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);


void	reverseLinkedList(LinkedList *plist);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif