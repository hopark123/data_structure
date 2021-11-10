#ifndef _STACK_
#define _STACK_

typedef struct StackNodeType
{
	int data;
}	StackNode;

typedef struct ArrayStackType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pTopElement;		// Top 노드의 포인터
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, StackNode element);
StackNode* popAS(ArrayStack* pStack);
StackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
int checkBracketMatching(char *pSource);
StackNode	*createArrayNode(int data);

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif

