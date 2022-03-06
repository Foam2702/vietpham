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

int Min(int matrix[][50], int dong, int cot)
{
	int min = matrix[0][0];
	for (int i = 0; i < cot; i++)
	{
		if (matrix[dong][i] < min)
			min = matrix[dong][i];
	}
	return min;
}

int Max(int matrix[][50], int dong, int cot)
{
	int max = matrix[0][0];
	for (int i = 0; i < dong; i++)
	{
		if (matrix[i][cot] > max)
			max = matrix[i][cot];
	}
	return max;
}

void diem_Yenngua(int matrix[][50], int dong, int cot)
{
	bool check = false;
	int submatrix[50], temp = 0;
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if (matrix[i][j] == Min(matrix, i, cot) && matrix[i][j] == Max(matrix, dong, j))
			{
				submatrix[temp] = matrix[i][j];
				temp++;
				check = true;
			}
		}
	}

	if (check == true)
	{
		cout << "Diem yen ngua co the co: " << endl;
		for (int i = 0; i < temp; i++)
		{
			cout << submatrix[i] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Khong co diem yen ngua" << endl;
	}
}