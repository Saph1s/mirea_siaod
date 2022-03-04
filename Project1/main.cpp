#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int N = 0;
	cout << "Размер массива" << endl;
	cin >> N;
	int* a = new int[N];
	long long c = 0;
	long long s = 0;


	int buff = 0;
	int i, j;

	for (int i = 0; i <= N; ++i)
	{
		a[i] = rand();
		//cout << a[i] << endl;
	}
	auto start = chrono::steady_clock::now();
	for (i = 1; i < N; i++)
	{
		buff = a[i];
		for (j = i - 1; j >= 0 && a[j] > buff; j--) {
			a[j + 1] = a[j];
			c += 1;
		}
		a[j + 1] = buff;
		s += 1;
	}

	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	//for (int i = 0; i < N; i++)
	//	cout << a[i] << '\t';
	//cout << endl;
	cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
	cout << "s = " << s << endl;
	cout << "c = " << c << endl;

	return(0);
}