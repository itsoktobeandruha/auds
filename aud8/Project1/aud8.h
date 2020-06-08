#ifndef _AUD_8_H
#define _AUD_8_H

#include<stdio.h>
#define comp pow(10, -3)
#define lower pow(10, -10)
struct spisok
{
	double value;
	struct spisok* next;
	struct spisok* previous;
};
typedef struct spisok list;
void outputToLeft(list*);
list* addToRight(list*, double, double);
list* addToLeft(list*, double, double);
list* findByValue(list*, double);
void swapTwoElements(list*);
void deleteByValue(list*, double);
void addBeforeCurrent(list*, double, double);
void addBeforeValue(list*, list*, double, double);
void freeAll(list*, list*);
void splice(list*, list*, list*);


#endif