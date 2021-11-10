#ifndef _STACK_
#define _STACK_

typedef struct StackNodeType
{
	int data;
	struct StackNodeType* pLLink;
	struct StackNodeType* pRLink;
}	StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
int checkBracketMatching(char *pSource);
StackNode	*createLinkedNode(int data);

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif