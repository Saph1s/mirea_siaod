#ifndef NODE_H
#define NODE_H

#include <string>

struct Node
{
	std::string phoneNumber;
	std::string phoneCaller;
	int timeCall;

	Node* previousNode;
	Node* nextNode;

	Node(std::string phoneNumber, int timeCall, std::string phoneCaller);
};

#endif