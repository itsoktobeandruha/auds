#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "aud8.h"

void outputToRight(list* head)
{
	while (head != NULL)
	{
		if (head->next != NULL)
			printf("%.4lf -> ", head->value);
		else if (head->next == NULL)
			printf("%.4lf.\n", head->value);
		head = head->next;
	}
}

void outputToLeft(list* tail)
{
	while (tail != NULL)
	{
		if (tail->previous != NULL)
			printf("%.3lf -> ", tail->value);
		else if (tail->previous == NULL)
			printf("%.3lf.\n", tail->value);
		tail = tail->previous;
	}
}

list* addToRight(list* tail, double right_rand, double left_rand)
{
	int minus = rand() % 3 + 1;
	tail->next = (list*)malloc(sizeof(list));
	tail->next->previous = tail;
	tail = tail->next;
	tail->value = (double)(rand() % (int)(right_rand - left_rand) + left_rand) + lower;
	if (tail->value > 0)
		tail->value += (double)(rand()) / RAND_MAX * 1;
	else tail->value -= (double)(rand()) / RAND_MAX * 1;
	tail->next = NULL;
	return tail;
}

list* addToLeft(list* head, double right_rand, double left_rand)
{
	head->previous = (list*)malloc(sizeof(list));
	head->previous->next = head;
	head = head->previous;
	head->previous = NULL;
	head->value = (double)(rand() % (int)(right_rand - left_rand) + left_rand) + lower;
	if (head->value > 0)
		head->value += (double)(rand()) / RAND_MAX * 1;
	else head->value -= (double)(rand()) / RAND_MAX * 1;
	return head;
}

list* findByValue(list* head, double _value)
{
	while (head != NULL)
	{
		if (fabs(head->value - _value) < comp)
		{
			return head;
		}
		head = head->next;
	}

	return NULL;
}

void swapTwoElements(list* head)
{
	double value1, value2;
	list* cur, * cur1, * temp = (list*)malloc(sizeof(list));
	printf("Please, type what you want to change: ");
	scanf_s("%lf%lf", &value1, &value2);
	cur = findByValue(head, value1);
	cur1 = findByValue(head, value2);
	if (cur == NULL || cur1 == NULL)
	{
		printf("Not found\n");
		return (void*)NULL;
	}
	temp->next = cur1->next;
	temp->previous = cur1->previous;
	if (cur->previous != NULL)
		cur->previous->next = cur1;
	if (cur->next != NULL)
		cur->next->previous = cur1;
	if (cur1->next != NULL)
		cur1->next->previous = cur;
	if (cur1->previous != NULL)
		cur1->previous->next = cur;
	cur1->next = cur->next;
	cur1->previous = cur->previous;
	cur->previous = temp->previous;
	cur->next = temp->next;
	free(temp);
}

void deleteByValue(list* head, double _value)
{
	list* cur = findByValue(head, _value);
	if (cur == NULL)
	{
		printf("Not found\n");
		return NULL;
	}
	else
	{
		cur->previous->next = cur->next;
		cur->next->previous = cur->previous;
		printf("%lf Deleted\n", cur->value);
		free(cur);
	}
}

void addBeforeCurrent(list* current, double right_rand, double left_rand)
{
	if (current == NULL)
	{
		printf("Not chosen\n");
		return NULL;
	}
	list* new = (list*)malloc(sizeof(list));
	list* temp;
	new->value = (double)(rand() % (int)(right_rand - left_rand) + left_rand) + lower;
	if (new->value > 0)
		new->value += (double)(rand()) / RAND_MAX * 1;
	else new->value -= (double)(rand()) / RAND_MAX * 1;
	temp = current->previous;
	current->previous = new;
	new->previous = temp;
	new->next = current;
	temp->next = new;
	printf("Added succesfully\n");
}

void addBeforeValue(list* head, list* current, double right_rand, double left_rand)
{
	double value;
	scanf_s("%lf", &value);
	current = findByValue(head, value);
	addBeforeCurrent(current, right_rand, left_rand);
}

void splice(list* left, list* right, list* position)
{
	if (position->next == left)
		return NULL;

	if (left->previous != NULL)
		left->previous->next = right->next;
	if (right->next != NULL)
		right->next->previous = left->previous;
	if (left->previous != NULL)
		left->previous = position;
	if (right->next != NULL)
		right->next = position->next;
	position->next->previous = right;
	position->next = left;
}

void freeAll(list* head, list* tail)
{
	while (head->next != NULL)									//dont forget to free!
	{
		head = head->next;
		free(head->previous);
	}
	free(tail);
}
