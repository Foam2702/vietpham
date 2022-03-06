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

int tong_kxk(int matrix[][50], int i1, int j1, int k)
{
	int sum = 0;
	for (int i = i1; i < i1 + k; i++)
	{
		for (int j = j1; j < j1 + k; j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}

int tong(int matrix[][50], int dong, int cot, int k)
{
	int maxsum = tong_kxk(matrix, 0, 0, k);
	for (int i = 0; i < dong - k; i++)
	{
		for (int j = 0; j < cot - k; j++)
		{
			maxsum = max(tong_kxk(matrix, i, j, k), maxsum);
		}
	}
	return maxsum;
}