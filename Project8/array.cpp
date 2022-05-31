#include "array.h"

array::array(int size)
{
	size_ = size;
	currentNum_ = size - 1;
	array_ = new int[size];
}

void array::push(int data)
{
	array_[currentNum_] = data;
	currentNum_--;
}

void array::drop()
{
	int* newArray = new int[size_];

	for (unsigned int i = size_ - 1; i > currentNum_; i--)
	{
		newArray[i] = array_[i];
	}

	delete[] array_;
	array_ = newArray;
	newArray = nullptr;

	currentNum_++;
}

int array::operator[] (int index)
{
	if (index >= size_) { throw; }
	else
	{
		return array_[index];
	}
}

bool array::isFull()
{
	return(currentNum_ == -1);
}

bool array::isEmpty()
{
	return(currentNum_ == size_ - 1);
}

int array::getMax(int dataFirst, int dataSecond)
{
	if (dataFirst >= dataSecond) { return dataFirst; }
	else return dataSecond;
}

int array::getMin(int dataFirst, int dataSecond)
{
	if (dataFirst >= dataSecond) { return dataSecond; }
	else return dataFirst;
}