#ifndef _POLYNOMIAL_
#define _POLYNOMIAL_

typedef struct ListNodeType
{
	int degree;
	int coefficient;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode *headerNode;
} LinkedList;

LinkedList* createLinkedList();
ListNode* getLLElement(LinkedList* pList, int position);
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

void displayPolynomial(LinkedList* pList);

void	reverseLinkedList(LinkedList *plist);
LinkedList	*add_polynomial(LinkedList *A, LinkedList *B);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1
#define NULL		0

#endif
