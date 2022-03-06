#include<iostream>
using namespace std;

int SumMaTrix(int** arr, int dong, int cot)
{
	int sum = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			sum += arr[i][j];
		}
	}

	return sum;
}
int main()
{
	int dong, cot;
	int sum = 0;
	cout << "Nhap dong:"; cin >> dong;
	cout << "Nhap cot:"; cin >> cot;
	int** arr = new int* [dong];
	for (int i = 0; i < dong; i++)
	{
		arr[i] = new int[cot];
	}

	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "[" << i << "][" << j << "]:";
			cin >> arr[i][j];
		}
	}

	sum = SumMaTrix(arr, dong, cot);
	cout << sum;

	for (int i = 0; i < dong; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}