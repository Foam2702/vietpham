#include"Header.h"

void nhapMatran(int matrix[][50], int& dong,int& cot)
{
	do
	{
		cout << "Nhap so dong: ";
		cin >> dong;
		if (dong < 1 || dong > 50)
			cout << "So phan tu phai <=50 ";
	} while (dong < 1 || dong>100);
	do
	{
		cout << "Nhap so cot: ";
		cin >> cot;
		if (cot < 1 || cot > 50)
			cout << "So phan tu phai <=50 ";
	} while (cot < 1 || cot>50);
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{	
			cout << "[" << i << "][" << j << "]:" ;
			cin >> matrix[i][j];
		}
	}
}
void xuatMatran(int matrix[][50], int dong,int cot)
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

void CongMaTran(int matrix1[][50], int matrix2[][50], int dong1, int cot1, int dong2, int cot2)
{
	int sum[50][50];
	for (int i = 0; i < dong1; i++)
	{
		for (int j = 0; j < cot1; j++)
		{
			sum[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	xuatMatran(sum, dong1, cot1);
}

void TichMaTran(int matrix1[][50], int matrix2[][50], int dong1, int cot1, int dong2, int cot2)
{
	int mutiply[50][50];
	for (int i = 0; i < dong1; i++)
	{
		for (int j = 0; j < cot2; j++)
		{
			mutiply[i][j] = 0;
			for (int k = 0; k < cot1; k++)
			{
				mutiply[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	xuatMatran(mutiply, dong1, cot1);
}