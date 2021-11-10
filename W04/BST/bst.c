#include "bst.h"
#include <unistd.h>



BST*        makeBST(BSTNode rootNode)
{
	BST         *pBST;
	BSTNode*    currNode;

	if (!(pBST = malloc(sizeof(BST))))
		return (NULL);
	if (!(pBST->pRootNode = malloc(sizeof(BSTNode))))
	{
		free(pBST);
		return (NULL);
	}
	if (!(currNode = makeBSTNode(rootNode)))
	{
		free(pBST);
		free(pBST->pRootNode);
		return (NULL);
	}
	pBST->pRootNode->data = INT32_MAX;
	pBST->pRootNode->visited = -1;
	pBST->pRootNode->leftNode = currNode;
	pBST->pRootNode->rightNode = NULL;
	return (pBST);
}

BSTNode*    makeBSTNode(BSTNode element)
{
	BSTNode*    res;
	res = malloc(sizeof(BSTNode));
	if (!res)
		return (NULL);
	res->data = element.data;
	res->visited = 0;
	res->leftNode = NULL;
	res->rightNode = NULL;
	return (res);
}

BSTNode*    getRootNodeBST(BST* pBST)
{
	if (!pBST)
		return (NULL);
	return (pBST->pRootNode->leftNode);
}

BSTNode*	searchParentNodeBST(BST* pBST, BSTNode element)
{
	BSTNode *parentNode;
	BSTNode *currNode;

	currNode = pBST->pRootNode->leftNode;
	parentNode = pBST->pRootNode;
	while (currNode)
	{
		if (currNode->data == element.data)
			break ;
		parentNode = currNode;
		if (currNode->data > element.data)
			currNode = parentNode->leftNode;
		else if (currNode->data < element.data)
			currNode = parentNode->rightNode;
	}
	return (parentNode);
}

int	insertChildNodeBST(BST* pBST, BSTNode element)
{
	BSTNode *parentNode;
	BSTNode *newNode;

	if (!pBST)
		return (FALSE);
	if (searchkeyBST(pBST, element))
		return (FALSE);
	parentNode = searchParentNodeBST(pBST, element);
	if (!(newNode = makeBSTNode(element)))
		return (FALSE);
	if (parentNode->visited == -1)
	{
		parentNode->leftNode = newNode;
		parentNode->rightNode = NULL;
	}
	else if (parentNode->data > element.data)
		parentNode->leftNode = newNode;
	else
		parentNode->rightNode = newNode;
	return (TRUE);
}

BSTNode*	searchkeyBST(BST* pBST, BSTNode element)
{
	BSTNode *currNode;

	if (!pBST)
		return (NULL);
	currNode = pBST->pRootNode->leftNode;
	while (currNode)
	{
		if (currNode->data > element.data)
			currNode = currNode->leftNode;
		else if (currNode->data < element.data)
			currNode = currNode->rightNode;
		else
			return (currNode);
	}
	return (NULL);
}



int			isChildLeft(BSTNode *parentNode, BSTNode *childNode)
{
	if (parentNode->leftNode == childNode)
		return (1);
	else 
		return (0);
}

BSTNode*		findMax(BSTNode* rootNode)
{
	if (rootNode == NULL)
		return (NULL);
	else if (rootNode->rightNode == NULL)
		return (rootNode);
	else
		return (findMax(rootNode->rightNode));
}

BSTNode*		deleteBSTNode(BSTNode* rootNode, BSTNode element)
{
	if (rootNode == NULL)
		return (NULL);
	if (element.data < rootNode->data)
		rootNode->leftNode = deleteBSTNode(rootNode->leftNode, element);
	else if (element.data > rootNode->data)
		rootNode->rightNode = deleteBSTNode(rootNode->rightNode, element);
	else //element.data == rootNode.data 찾은경우
	{
		if (rootNode->leftNode && rootNode->rightNode) // 자식이 2개인경우
		{
			BSTNode*	canNode;
			canNode = findMax(rootNode->leftNode); //left에서 가장 큰 값 찾기
			rootNode->data = canNode->data;
			rootNode->leftNode = deleteBSTNode(rootNode->leftNode, *canNode);
		}
		else //자식이 1개 이하
		{
			BSTNode*	temp;
			temp = rootNode;
			if (rootNode->leftNode == NULL)
				rootNode = rootNode->rightNode;
			else if (rootNode->rightNode == NULL)
				rootNode = rootNode->leftNode;
			free(temp);
		}
	}
	return (rootNode);
}



void		clearBST(BST* pBST, BSTNode* pBSTNode)
{
	if (!pBSTNode)
		return ;
	clearBST(pBST, pBSTNode->leftNode);
	clearBST(pBST, pBSTNode->rightNode);
	free(pBST);
}

void		deleteBST(BST** pBST)
{
	if (!(*pBST))
		return ;
	clearBST((*pBST), (*pBST)->pRootNode->leftNode);
	free((*pBST)->pRootNode);
	free(*pBST);
	(*pBST) = NULL;
}

void        Inorder(BSTNode* pBSTNode)
{
	if (!pBSTNode)
		return ;
	Inorder(pBSTNode->leftNode);
	printf("|%d|", pBSTNode->data);
	Inorder(pBSTNode->rightNode);
}



/*

			30
	20			40
 14    24     34
10 16 
  15

			24
	20			40
 14    22     34
10 16
  15

  			24
	20			40
 10    22     34
   16
  15
			24
	20			40
 16    22     34
15
			22
	20			40
 16           34
15

   			20
	16			40
 15           34

			20
	16			34
15
	
		20
	16	
15
*/

int main(void)
{
	BST     *pBST;
	BSTNode BSTNode;
	int     lst[10] = {30, 20, 14, 16, 24, 22, 10, 40, 34, 15};
	// int     lst[10] = {20, 16, 15};

	int     lst2[12] = {30, 46, 14, 10, 24, 22, 11, 40, 34, 20, 15, 16};
	// int     lst2[12] = {20, 15, 16};

	int     idx = -1;

	printf("========= MAKE BST TEST =========\n");
	BSTNode.data = lst[0];
	BSTNode.leftNode = 0;
	BSTNode.rightNode = 0;
	pBST = makeBST(BSTNode);
	Inorder(pBST->pRootNode->leftNode);

	printf("\n------ DEL TEST ------\n");
	// deleteBSTNode(pBST->pRootNode->leftNode, BSTNode);

	printf("\n========= INSERT TEST =========\n");
	while (++idx < 10 && lst[idx])
	{
		BSTNode.data = lst[idx];
		insertChildNodeBST(pBST, BSTNode);
	}
	Inorder(pBST->pRootNode->leftNode);
	printf("\n========= DEL TEST =========\n");
	idx = -1;
	while (++idx < 12 && lst[idx])
	{
		BSTNode.data = lst2[idx];
		printf("del %d\n", BSTNode.data);
		printf("bf : ");
		Inorder(pBST->pRootNode->leftNode);

		pBST->pRootNode->leftNode = deleteBSTNode(pBST->pRootNode->leftNode, BSTNode);
		printf("\naf : ");
		Inorder(pBST->pRootNode->leftNode);
	}
	deleteBST(&pBST);
	return(0);
}











// void		deleteBSTNode(BST *pBST, BSTNode element) // 더 좋은방법으로 대체
// {
// 	BSTNode*	delNode;
// 	BSTNode*	del_parentNode;
// 	BSTNode*	canNode;
// 	BSTNode*	can_parentNode;

// 	if (!pBST)
// 		return ;
// 	if (!(delNode = searchkeyBST(pBST, element)))
// 		return ;
// 	del_parentNode = searchParentNodeBST(pBST, element);
// 	if (isChildLeft(del_parentNode, delNode) == 1)
// 	{
// 		if (!delNode->leftNode && !delNode->rightNode) // delnode's child is 0
// 		{
// 			if (isChildLeft(del_parentNode, delNode) == 1) // Parent-Child is left
// 				del_parentNode->leftNode = NULL;
// 			else // Parent-Child is right
// 				del_parentNode->rightNode = NULL;
// 		}
// 		else if (delNode->leftNode == NULL || delNode->rightNode == NULL)  // delnode's child is 1
// 		{
// 			if (delNode->leftNode == NULL)
// 			{
// 				if (isChildLeft(del_parentNode, delNode) == 1) // Parent-Child is left
// 					del_parentNode->leftNode = delNode->rightNode;
// 				else // Parent-Child is right
// 					del_parentNode->rightNode = delNode->rightNode;
// 			}
// 			else // delNode->rightNode == NULL 
// 			{
// 				if (isChildLeft(del_parentNode, delNode) == 1) // Parent-Child is left
// 					del_parentNode->leftNode = delNode->leftNode;
// 				else // Parent-Child is right
// 					del_parentNode->rightNode = delNode->leftNode;
// 			}
// 		}
// 		else // delnode's child is 2
// 		{
// 			canNode = searchCandidateNodeBST(delNode);
// 			can_parentNode = searchParentNodeBST(pBST, *canNode);
// 			if (isChildLeft(can_parentNode, canNode) == 1)
// 				can_parentNode->leftNode = canNode->leftNode;
// 			else
// 				can_parentNode->rightNode = canNode->rightNode;
// 			delNode->data = canNode->data;
// 			delNode->visited = canNode->visited;
// 			delNode = canNode;
// 		}
// 		free(delNode);
// 	}
// 	return ;
// }

// BSTNode*	searchCandidateNodeBST(BSTNode* pBSTNode)
// {
// 	BSTNode*    left_canNode;
// 	BSTNode*    right_canNode;

// 	if (pBSTNode->leftNode)
// 	{
// 		left_canNode = pBSTNode->leftNode;
// 		while (left_canNode->rightNode)
// 			left_canNode = left_canNode->rightNode;
// 		return (left_canNode);
// 	}
// 	else if (pBSTNode->rightNode)
// 	{
// 		right_canNode = pBSTNode->rightNode;
// 		while (right_canNode->leftNode)
// 			right_canNode = right_canNode->leftNode;
// 		return (right_canNode);
// 	}
// 	else
// 		return (pBSTNode);
// }