#include"Header.h"

void nhapMatran(float matrix[][50], int& dong, int& cot)
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

bool check_Cucdai(float matrix[][50], int dong, int cot, int m, int n)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (m + i >= 0 && n + j >= 0 && m + i < dong && n + j < cot && !(i == 0 && j == 0))
			{
				if (matrix[m][n] <= matrix[m + i][n + j])
					return false;
			}
		}
	}

	return true;
}

void tim_Cucdai(float matrix[][50], int dong, int cot)

{
	int count = 0;
	cout << "Cac phan tu cuc dai: " << endl;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (check_Cucdai(matrix, dong, cot, i, j) == true)
			{	
				count++;
				cout << "Co " << count << " cuc dai" << endl;
				cout << matrix[i][j] << " ";
			}
		}
	}
	cout << endl;
}