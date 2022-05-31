#include <iostream>

using namespace std;

struct node
{
	int data;
	node* nextel;

	node(int value) : data(value), nextel(nullptr) {}
};

struct list
{
	node* firstel;
	node* lastel;

	list() : firstel(nullptr), lastel(nullptr) {}

	~list()
	{
		node* i = firstel;

		while (i != nullptr)
		{
			node* temp = i->nextel;
			delete i;
			i = temp;
		}
	}

	int find(int value)
	{
		if (is_empty()) { 
			return -89458492; 
		}

		int index = 0;
		node* i = firstel;

		while (i != nullptr)
		{
			if (value == i->data)
			{
				return index;
			}
			else
			{
				index++;
				i = i->nextel;
			}
		}
		return -1;
	}

	bool is_empty()
	{
		return(firstel == nullptr);
	}

	void push_forward(int value)
	{
		node* list_node = new node(value);

		if (is_empty())
		{
			firstel = list_node;
			lastel = list_node;
		}
		else
		{
			list_node->nextel = firstel;
			firstel = list_node;
		}
	}

	void print()
	{
		if (is_empty()) { 
			cout << "Empty"; 
			return; 
		}

		node* i = firstel;

		while (i != nullptr)
		{
			cout << i->data << "\t";
			i = i->nextel;
		}
	}

	int size()
	{
		int index = 0;
		node* i = firstel;

		while (i != nullptr)
		{
			index++; i = i->nextel;
		}
		return index;
	}

	int operator[] (int index)
	{

		node* i = firstel;
		int step = 0;

		while (i != nullptr)
		{
			if (step == index) { return i->data; }

			i = i->nextel;
			step++;
		}
	}
};

int main()
{
	srand(NULL);
	list l, l1, l2;

	for (int i = 0; i < 10; i++)
	{
		l1.push_forward(rand() % 100);
		l2.push_forward(rand() % 100);
	}

	for (int i = 0; i < l1.size(); i++)
	{
		if (l1.find(l2[i]) == -1) { l.push_forward(l2[i]); }
	}

	cout << "l1:" << endl;
	l1.print();

	cout << endl << "l2:" << endl;
	l2.print();

	cout << endl << "l:" << endl;
	l.print();

	return 0;
}