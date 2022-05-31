#include <iostream>

#include "stack.h"

using namespace std;

int main()
{
	int n, currentBuild;
	cin >> n;
	stack stackBuilds(n);

	for (unsigned int i = 0; i < n; i++)
	{
		cin >> currentBuild;
		stackBuilds.push(currentBuild);
	}
	cout << endl << stackBuilds.calculateBuilds() << endl;
}