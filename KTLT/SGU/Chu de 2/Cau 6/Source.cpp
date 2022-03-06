#include<iostream>
using namespace std;

int countMax(int* arr, int n)
{
	int max = arr[0];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == max) count++;
	}
	return count;
}
int main()
{
	int n;
	cout << "Nhap so luong phan tu:"; cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "]:";
		cin >> arr[i];
	}
	int countmax = countMax(arr, n);
	cout << countmax;
}