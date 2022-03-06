
#include<iostream>
using namespace std;

void Merge(int arr[], int left, int mid, int right)
{
	int temp[7] = {};
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = (arr[j]);
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= right)
		{
			temp[k] = arr[j];
			j++, k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[k] = arr[i];
			i++, k++;
		}
	}

	for (int k = left; k <= right; k++)
	{
		arr[k] = temp[k];
	}
}
void MergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
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
		cout << "a[" << i << "]:";cin>> arr[i];
	}
	MergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}