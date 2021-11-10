#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;		// ���� ����� ������ ����
	DoublyListNode	*headerNode;		// ��� ���(Header Node)
} DoublyList;

DoublyList* createDoublyList();
DoublyListNode* getDLElement(DoublyList* pList, int position);
int addDLElement(DoublyList* pList, int position, DoublyListNode element);
int removeDLElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
void deleteDoublyList(DoublyList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define	ERROR		-1
#endif