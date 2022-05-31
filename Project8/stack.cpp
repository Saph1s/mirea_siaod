#include "stack.h"

stack::stack(int size) : size_(size), lastnode_(nullptr), currentNum_(0) {}

bool stack::isEmpty()
{
	return(currentNum_ == 0);
}

void stack::push(int data)
{
	if (currentNum_ == size_) { throw; }
	else
	{
		node* currentnode = new node(data);

		if (isEmpty()) {}
		else
		{
			currentnode->nextnode = lastnode_;
		}
		lastnode_ = currentnode;
		currentNum_++;
	}
}

node* stack::get()
{
	if (isEmpty()) { throw; }
	else
	{
		node* currentnode = lastnode_;

		lastnode_ = lastnode_->nextnode;

		currentNum_--;
		return currentnode;
	}
}

int stack::operator[] (int index)
{
	node* currentnode = lastnode_;

	for (unsigned int i = 1; i < index; i++)
	{
		currentnode = currentnode->nextnode;
	}

	return currentnode->data;
}

bool stack::isFull()
{
	return(currentNum_ == size_);
}

int stack::getMax(int dataFirst, int dataSecond)
{
	if (dataFirst >= dataSecond) { return dataFirst; }
	else return dataSecond;
}

int stack::getMin(int dataFirst, int dataSecond)
{
	if (dataFirst >= dataSecond) { return dataSecond; }
	else return dataFirst;
}

int stack::calculateBuilds()
{
	int currentHeight = lastnode_->data;
	int numBuilds = 1;
	node* currentnode = lastnode_;

	while (currentnode != nullptr)
	{
		if (currentnode->data > currentHeight)
		{
			numBuilds++;
			currentHeight = currentnode->data;
		}

		currentnode = currentnode->nextnode;
	}

	return numBuilds;
}