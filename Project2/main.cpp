#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

void sort(int* a, int first, int last, int* s, int* c) {
    int mid, tmp;
    int f = first, l = last;
    mid = a[(f + l) / 2]; //Вычисление опорного элемента
    do
    {
        while (a[f] < mid) f++;
        while (a[l] > mid) l--;
        if (f <= l) //Перестановка элементов
        {
            tmp = a[f];
            a[f] = a[l];
            a[l] = tmp;
            f++;
            l--;
            *s += 1; //Счетчик перестановок
        }
        *c += 1;//Счетчик проверок
    } while (f < l);

    if (first < l) sort(a, first, l, s, c);
    if (f < last) sort(a, f, last, s, c);
}

int main() {

    setlocale(LC_ALL, "RUS");
    
    int N = 0;
    cout << "Размер массива" << endl;
    cin >> N;
    int* a = new int[N];
    int c = 0;
    int s = 0;

    for (int i = 0; i <= N; ++i)
    {
        a[i] = rand();
    }

    auto start = chrono::steady_clock::now();
    sort(a, 0, N, &s, &c);
    auto end = chrono::steady_clock::now();
    auto diff = end - start;

    /*for (int i = 0; i <= N; ++i)
    {
        cout << a[i] << endl;
    }*/

    cout << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    cout << "s = " << s << endl;
    cout << "c = " << c << endl;
}

