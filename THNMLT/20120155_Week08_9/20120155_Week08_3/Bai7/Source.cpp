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

void swapDong(int matrix[][50], int dong, int cot, int m, int n)
{
	for (int i = 0; i < cot; i++)
	{
		swap(matrix[m][i], matrix[n][i]);
	}
}

int Tongdong(int matrix[][50], int dong, int cot, int k)
{
	int sum = 0;
	for (int i = 0; i < cot; i++)
	{
		sum += matrix[k][i];
	}
	return sum;
}

void SapXepDongMaTran(int matrix[][50], int dong, int cot)
{
	for (int i = 0; i < dong - 1; i++)
	{
		for (int j = i + 1; j < dong; j++)
		{
			if (Tongdong(matrix, dong, cot, i) > Tongdong(matrix, dong, cot, j))
				swapDong(matrix, dong, cot, i, j);
		}
	}
}