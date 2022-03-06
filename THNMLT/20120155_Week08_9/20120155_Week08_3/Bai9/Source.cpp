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

void sapXep_cotTang(int matrix[][50], int dong, int cot, int k)
{
	for (int i = 0; i < dong - 1; i++)
	{
		for (int j = i + 1; j < dong; j++)
		{
			if (matrix[i][k] > matrix[j][k])
				swap(matrix[i][k], matrix[j][k]);
		}
	}
}

void sapXep_dongGiam(int matrix[][50], int dong, int cot, int k)
{
	for (int i = 0; i < cot - 1; i++)
	{
		for (int j = i + 1; j < cot; j++)
		{
			if (matrix[k][i] < matrix[k][j])
				swap(matrix[k][i], matrix[k][j]);
		}
	}
}

void sapXep_maTran(int matrix[][50], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		sapXep_dongGiam(matrix, dong, cot, i);
	}
	for (int j = 0; j < cot; j++)
	{
		sapXep_cotTang(matrix, dong, cot, j);
	}
}