#include "node.h"

Node::Node(std::string phoneNumber, int timeCall, std::string phoneCaller) :
	phoneNumber(phoneNumber), timeCall(timeCall), phoneCaller(phoneCaller),
	previousNode(nullptr), nextNode(nullptr) {}
