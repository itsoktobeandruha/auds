#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aud8.h"

int main()
{
	list* head = (list*)malloc(sizeof(list));
	list* tail = (list*)malloc(sizeof(list));
	list* current = NULL;
	double right_rand, left_rand;
	printf("Type left and right borders\n");
	scanf_s("%lf%lf", &left_rand, &right_rand);
	system("cls");
	head->next = tail;
	head->previous = NULL;
	tail->next = NULL;
	tail->previous = head;
	head->value = (double)(rand() % (int)(right_rand - left_rand) + left_rand) + lower;
	if (head->value > 0)
		head->value += (double)(rand()) / RAND_MAX * 1;
	else head->value -= (double)(rand()) / RAND_MAX * 1;
	tail->value = (double)(rand() % (int)(right_rand - left_rand) + left_rand) + lower;
	if (tail->value > 0)
		tail->value += (double)(rand()) / RAND_MAX * 1;
	else tail->value -= (double)(rand()) / RAND_MAX * 1;
	list* right, * left;

	while (1)
	{
		char ch;

		printf("Press 1 to outputToRight \nPress 2 to outputToLeft \nPress 3 to addToRight\nPress 4 to addToLeft\nPress 5 to findByValue\nPress 6 todeleteByValue\nPress 7 to addBeforeCurrent\nPress 8 to addBeforeValue\nPress 9 to swap by value\nPress 0 to splice!");
		ch = _getch();
		system("cls");

		switch (ch)
		{
		case '1':
		{
			outputToRight(head);
			break;
		}
		case '2':
		{
			outputToLeft(tail);
			break;
		}
		case '3':
		{
			tail = addToRight(tail, right_rand, left_rand);
			break;
		}
		case '4':
		{
			head = addToLeft(head, right_rand, left_rand);
			break;
		}
		case '5':
		{
			double value;
			printf("Type the value: ");
			scanf_s("%lf", &value);
			printf("\n");
			current = findByValue(head, value);
			if (current == NULL)
				printf("Not found\n");
			else printf("%p - adress of the element\n", current);
			break;
		}
		case '6':
		{
			double value;
			printf("Type the value: ");
			scanf_s("%lf", &value);
			printf("\n");
			deleteByValue(head, value);
		}
		case '7':
		{
			addBeforeCurrent(current, right_rand, left_rand);
			break;
		}
		case '8':
		{
			addBeforeValue(head, current, right_rand, left_rand);
			break;
		}
		case '9':
		{
			swapTwoElements(head);
			break;
		}
		case '10':
		{
			double value;
			scanf_s("%lf", &value);
			left = findByValue(head, value);
			scanf_s("%lf", &value);
			right = findByValue(head, value);
			splice(left, right, current);
			break;
		}
		default:
		{
			freeAll(head, tail);
			exit(3);
		}
		}
	}

	freeAll(head, tail);
	system("pause");
	return 0;
}