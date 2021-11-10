#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>


static void	display_TEST(LinkedList *A, LinkedList *B, LinkedList *C)
{
	printf("A : ");
	displayPolynomial(A);
	printf("B : ");

	displayPolynomial(B);
	C = add_polynomial(A, B);
	printf("C : ");
	displayPolynomial(C);
}

int main()
{
	LinkedList	*A = createLinkedList();
	LinkedList	*B = createLinkedList();
	LinkedList	*C;
	ListNode	temp;

	printf("---------------- NULL TEST ----------------\n");
	display_TEST(A, B, C);
	free(C);
	printf("----------------  ONE TEST  ----------------\n");
	{
		temp.coefficient = 7;
		temp.degree = 4;
		addLLElement(A, 0, temp);
	}
	display_TEST(A, B, C);
	free(C);
	printf("---------------- BASIC TEST ----------------\n");
	{
		temp.coefficient = 1;
		temp.degree = 3;
		addLLElement(A, 1, temp);
	}
	{
		temp.coefficient = -2;
		temp.degree = 2;
		addLLElement(A, 2, temp);
	}
	{
		temp.coefficient = 4;
		temp.degree = 0;
		addLLElement(A, 3, temp);
	}
	{
		temp.coefficient = -2;
		temp.degree = 3;
		addLLElement(B, 0, temp);
	}
	{
		temp.coefficient = 8;
		temp.degree = 1;
		addLLElement(B, 1, temp);
	}
	display_TEST(A, B, C);
	free(A);
	free(B);
	free(C);
}