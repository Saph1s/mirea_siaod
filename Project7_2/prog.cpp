#include "prog.h"

list::list() : firstNode(nullptr), lastNode(nullptr) {}

bool
list::isEmpty()
{
	return firstNode == nullptr;
}

void list::addInTurn(Node* newNode)
{
	if (isEmpty()) { firstNode = newNode; lastNode = newNode; }
	else
	{
		Node* currentNode = firstNode;
		while (std::stoi(currentNode->phoneNumber.substr(0, 5)) < std::stoi(newNode->phoneNumber.substr()))
		{
			if (currentNode->nextNode == nullptr)
			{
				newNode->previousNode = currentNode;
				newNode->nextNode = nullptr;
				currentNode->nextNode = newNode;

				lastNode = newNode;
				return;
			}
			currentNode = currentNode->nextNode;
		}


		newNode->nextNode = currentNode->nextNode;
		newNode->previousNode = currentNode;
		currentNode->nextNode = newNode;
	}
}

std::string list::removeLastNode(std::string phoneNumber)
{
	Node* currentNode = lastNode;

	while (currentNode->phoneNumber != phoneNumber)
	{
		currentNode = currentNode->previousNode;
		if (currentNode == nullptr) { return"NOT FOUND"; }
	}

	currentNode->previousNode->nextNode = currentNode->nextNode;
	currentNode->nextNode->previousNode = currentNode->previousNode;
	delete currentNode; return"";
}

int list::getTimeCalls(std::string phoneNumber)
{
	Node* currentNode = firstNode;
	int resultTime = 0;
	while (currentNode != nullptr)
	{
		if (currentNode->phoneNumber == phoneNumber) { resultTime += currentNode->timeCall; }
		currentNode = currentNode->nextNode;
	}

	return resultTime;
}

void list::print()
{
	Node* currentNode = firstNode;

	while (currentNode != nullptr)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << "Phone: " << currentNode->phoneNumber << std::endl;
		std::cout << "Time Call: " << currentNode->timeCall << std::endl;
		std::cout << "Phone Caller: " << currentNode->phoneCaller << std::endl;
		currentNode = currentNode->nextNode;
	}
	std::cout << std::endl;

	currentNode = lastNode;

	while (currentNode != nullptr)
	{
		std::cout << "-----------------------" << std::endl;
		std::cout << "Phone: " << currentNode->phoneNumber << std::endl;
		std::cout << "Time Call: " << currentNode->timeCall << std::endl;
		std::cout << "Phone Caller: " << currentNode->phoneCaller << std::endl;
		currentNode = currentNode->previousNode;
	}
}