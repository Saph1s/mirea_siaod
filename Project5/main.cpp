#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int hashnum(int k, int m) {
	if (k % 2 != 0){
		return (k+10+1);

	}
	else {
		return (k+10);
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	int N = 0;
	cout << "Размер массива" << endl;
	cin >> N;
	int* a = new int[N];
	int* b = new int[N];
	int num;
	int f = 0;

	for (int i = 0; i <= N; ++i)
	{
		a[i] = rand();
	}

	cout << "Enter num : " << endl;
	cin >> num;
	num = hashnum(num, N);
	//cout << num << endl;

	for (int i = 0; i <= N; i++)
	{
		b[i] = hashnum(a[i], N);
	}

	for (int i = 0; i <= N; ++i)
	{
		if (num == b[i]) {
			cout << "Pos = " << i << endl;
			f = 1;
			break;
		}
	}
	if (f == 0) cout << "Not found";

	return 0;
}