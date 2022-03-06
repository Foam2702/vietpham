#include <iostream>
using namespace std;

void CountingSort(int *arr, int n) {

    int arr1[100] = {};
    int count_arr[100] = {};
    int x = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > x)
            x = arr[i];
    }

    for (int i = 0; i <= x; ++i) 
    {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) 
    {
        count_arr[i] += count_arr[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) 
    {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) 
    {
        arr[i] = arr1[i];
    }
}


int main()
{
    int n;
    do
    {
        cout << "Nhap so luong phan tu:"; cin >> n;
        if (n <= 0)
        {
            cout << "Nhap lai " << endl;
        }
    } while (n <= 0);
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "]:"; cin >> arr[i];
    }
    CountingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}