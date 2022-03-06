#include<iostream>
using namespace std;

int partition(int arr[], int left, int right)
{
	int pivvot = arr[right]; 
	int i = (left - 1); 

	for (int j = left; j <= right - 1; j++)
	{
		
		if (arr[j] < pivvot)
		{
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);
	return (i + 1);
}


void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		
		int piv = partition(arr, left, right);
		quickSort(arr, left, piv - 1);
		quickSort(arr, piv + 1, right);
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

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	

}


