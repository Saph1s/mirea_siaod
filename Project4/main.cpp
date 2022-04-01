#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

int search(int arr[], int size, int num, int *c) {
    int l(0);
    int r(size);
    int mid(0);
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] > num) {
            r = mid - 1;
           *c += 1;
        }
        else if (arr[mid] < num) {
            l = mid + 1;
            *c += 1;
        }
        else {
            return mid;
            *c += 1;
        }
    }
    return -1;
}

int tsearch(int arr[], int n, int num, int* c) {
    bool ok(1);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == num) {
            return i;
            ok = 0;
            break;
        }
        *c += 1;
    }
    return -1;
}

void quicksort(int arr[], int first, int last)
{
    int mid(arr[(first + last) / 2]);
    int l(last);
    int f(first);
    do {
        while (arr[f] < mid)f++;
        while (arr[l] > mid)l--;
        if (f <= l) {
            swap(arr[l], arr[f]);
            ++f;
            --l;
        }
    } while (f < l);
    if (first < l)quicksort(arr, first, l);
    if (f < last)quicksort(arr, f, last);
}
void backsort(int arr[], int n) {
    quicksort(arr, 0, n - 1);
    int c;
    for (int i = 0; i < (n / 2); i++) {
        c = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = c;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    srand(time(0));
    int n, num(0);
    int type;
    int c = 0;
    cout << "–азмер массива" << endl;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i <= n; ++i)
    {
        arr[i] = rand();
    }
    cout << "Enter num : " << endl;
    cin >> num;
    cout << "¬ид массива : " << endl;
    cout << " 1 - случайный набор чисел" << endl;
    cout << " 2 - строго возрастающие числа" << endl;
    cout << " 3 - строго убывающие числа" << endl;
    cin >> type;
    if (type == 1) {
        for (int i = 0; i < n; ++i)cout << arr[i] << " ";
        auto start = chrono::steady_clock::now();
        cout << endl << "Position : " << tsearch(arr, n, num, &c) << endl;
        auto end = chrono::steady_clock::now();
        auto diff = end - start;
        cout << endl << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    }
    if (type == 2) {
        auto start = chrono::steady_clock::now();
        quicksort(arr, 0, n - 1);
        cout << endl << "Position : " << tsearch(arr, n, num, &c) << endl;
        auto end = chrono::steady_clock::now();
        //for (int i = 0; i < n; ++i)cout << arr[i] << " ";
        auto diff = end - start;
        cout <<endl<< chrono::duration <double, milli>(diff).count() << " ms" << endl;
    }
    if (type == 3) {
        auto start = chrono::steady_clock::now();
        backsort(arr, n);
        cout << endl << "Position : " << tsearch(arr, n, num, &c) << endl;
        auto end = chrono::steady_clock::now();
        //for (int i = 0; i < n; ++i)cout << arr[i] << " ";
        auto diff = end - start;
        cout << endl << chrono::duration <double, milli>(diff).count() << " ms" << endl;
    }
    cout << "c = " << c << endl;
    return 0;
}
