#ifndef PROG_H
#define PROG_H
#include "node.h"

#include <iostream>

struct list
{
	Node* firstNode;
	Node* lastNode;

	list();
	bool isEmpty();
	void addInTurn(Node* currentNode);
	std::string removeLastNode(std::string phoneNumber);
	int getTimeCalls(std::string phoneNumber);
	void print();
};

#endif