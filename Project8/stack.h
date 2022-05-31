#ifndef STACK_H
#define STACK_H

#include "node.h"

struct stack
{
	node* lastnode_;
	int size_;
	int currentNum_;
	stack(int size);

	bool isEmpty();
	bool isFull();
	void push(int data);
	node* get();
	int operator[] (int index);

	int getMax(int dataFirst, int dataSecond);
	int getMin(int dataFirst, int dataSecond);
	int calculateBuilds();
};
#endif