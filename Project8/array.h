#ifndef ARRAY_H
#define ARRAY_H

struct array
{
	int* array_;
	int currentNum_;
	int size_;
	array(int size);
	void push(int data);
	void drop();
	int operator[] (int index);
	bool isFull();
	bool isEmpty();
	int getMax(int dataFirst, int dataSecond);
	int  getMin(int dataFirst, int dataSecond);
};
#endif