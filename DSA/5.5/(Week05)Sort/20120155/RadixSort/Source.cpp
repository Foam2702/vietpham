#include <iostream>
using namespace std;

int getMax(int *arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int *arr, int n, int exp)
{
    int *output=new int[n]; 
    int i, count[1000] = {};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


void RadixSort(int *arr, int n)
{
  
    int m = getMax(arr, n);

   
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
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
    RadixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}