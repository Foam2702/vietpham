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
void phanTu_Trungnhau(int matrix1[][50], int matrix2[][50], int dong, int cot)
{
	int submatrix[50], temp = 0;
	bool check = false;
	for (int i = 0; i < dong; i++)
		for (int j = 0; j < cot; j++)
			if (matrix1[i][j] == matrix2[i][j])
			{
				submatrix[temp] = matrix1[i][j];
				matrix1[i][j] = matrix2[i][j] = 0;
				temp++;
				check = true;
				
			}
	if (check == false)
		cout << "Khong co phan tu trung nhau " << endl;
	else
	{
		cout << "Cac phan tu bang nhau : "<<endl;
		cout << "So luong " << temp << endl;
		for (int i = 0; i < temp; i++)
		{
			cout << submatrix[i] << " ";
		}
	}
}