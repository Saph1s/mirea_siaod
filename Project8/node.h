#ifndef node_H
#define node_H

struct node
{
	node(int data);

	int data;
	node* nextnode;
};


#endif