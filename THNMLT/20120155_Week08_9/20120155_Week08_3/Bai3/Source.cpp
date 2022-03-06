#include"Header.h"

void nhapMatran(float a[][50], int& dong, int& cot)
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
			cin >> a[i][j];
		}
	}
}

void xuatMatran(float matrix[][50], int dong, int cot)
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

void sapXep(int arr[], int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[i] >arr[j])
				swap(arr[i], arr[j]);
		}
	}
}

void sapXep_Mangphu(float matrix[][50], int dong, int cot)
{
	int n = 0;
	int result[50];
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			result [n] = matrix[i][j];
			n++;
		}
	}
	sapXep(result, n);
	n = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			matrix[i][j] = result[n];
			n++;
		}
	}
}


void sapXep_koMangphu(float matrix[][50], int dong, int cot)
{
	int n = dong * cot;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (matrix[i / cot][i % cot] > matrix[j / cot][j % cot])
				swap(matrix[i / cot][i % cot], matrix[j / cot][j % cot]);
		}
	}
}

