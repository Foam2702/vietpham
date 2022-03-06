#include"array.h"

void Input(int arr[], int& n)
{
	do
	{
		cout << "Nhap so luong phan tu:"; cin >> n;
		if (n <= 0 || n > 20)
		{
			cout << "So luong phan tu phai thuoc doan 0 <= n <= 20" << endl;
		}
	} while (n <= 0 || n > 20);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

void Output(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}