#include"Header.h"

void nhapMatran(int matrix[][50], int& dong, int& cot)
{
	do
	{
		cout << "Nhap so dong: ";
		cin >> dong;
		if (dong < 1 || dong > 50)
			cout << "So phan tu phai <= 50 ";
	} while (dong < 1 || dong > 50);
	do
	{
		cout << "Nhap so cot: ";
		cin >> cot;
		if (cot < 1 || cot > 50)
			cout << "So phan tu phai <=50 ";
	} while (cot < 1 || cot > 50);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << "[" << i << "][" << j << "]:";
			cin >> matrix[i][j];
		}
	}
}

void xuatMatran(int matrix[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void sort_Arr(int b[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[i] % 2 == 0 && b[j] % 2 == 1)
				swap(b[i], b[j]);
		}
	}
	int k = n - 1;
	for (int i = 0; i < n - 1; i++)
	{
		if (b[i] % 2 == 1 && b[i + 1] % 2 == 0)
			k = i;
	}

	for (int i = 0; i < k - 1; i++)
	{
		for (int j = i + 1; j < k; j++)
		{
			if (b[i] > b[j] && b[i] % 2 == 1)
				swap(b[i], b[j]);
		}
	}

	for (int i = n - 1; i > k; i--)
	{
		for (int j = i - 1; j >= k; j--)
		{
			if (b[i] > b[j] && b[i] % 2 == 0)
				swap(b[i], b[j]);
		}
	}

}

void sort_Matrix(int matrix[][50], int dong, int cot)
{
	int arr[50], k = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			arr[k] = matrix[i][j];
			k++;
		}
	}

	sort_Arr(arr, k);
	k = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			matrix[i][j] = arr[k];
			k++;
		}
	}

}