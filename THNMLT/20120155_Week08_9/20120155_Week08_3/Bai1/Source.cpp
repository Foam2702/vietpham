#include"Header.h"
using namespace std;

void nhapMatran(int matrix[][50], int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
void xuatMatran(int matrix[][50], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int tinhTong(int matrix[][50], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n;j++)
		{
			sum += matrix[i][j];
		}
	}
	return sum;
}
int dem_solanXuathien_x(int matrix[][50], int n,int x)
{
	int count = 0;
	for (int  i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == x)
			{
				count++;
			}
		}
	}
	return count++;
}
bool check_Prime(int x)
{
	if (x < 2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				return false;
				break;
			}
		}
	}
	return true;
}
int dem_solanXuathien_SNT(int matrix[][50], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check_Prime(matrix[i][j]))
			{
				count++;
			}
		}
	}
	return count;
}
int tinhTong_SokhongAm(int matrix[][50], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] >= 0)
				sum += matrix[i][j];
		}
	}
	return sum = 0;
}
int tinhTong_Phantu_duongCheochinh(int matrix[][50], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				sum += matrix[i][j];
		}
	}
	return sum;
}
bool kiemTra_duongCheochinh_Tangdan(int matrix[][50], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			if (i == j)
			{
				if (matrix[i][j] < matrix[i + 1][j + 1])
					return true;
				else
				{
					return false;
					break;
				}
					
			}
		}
	}
	return true;
}
int tinhTong_Phantu_duongCheophu(int matrix[][50], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += matrix[i][n - 1 - i];
	}
	return sum;
}
void sapXep_tangDan_Tungdong(int matrix[][50], int n)
{
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (matrix[i][j] > matrix[i][j + 1])
				swap(matrix[i][j], matrix[i][j + 1]);
		}
	}
}
void tim_Max_dong_cot_matran(int matrix[][50],int maxtungdong[],int maxtungcot[], int n)
{
	int maxdong = matrix[0][0],maxcot=matrix[0][0],maxtoanmatran=matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] > maxdong)
			{
				maxdong = matrix[i][j];
			}
		}
		maxtungdong[i] = maxdong;
		cout << "Dong " << i + 1 << " Max la: " << maxtungdong[i] << endl;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (matrix[i][j] > maxcot)
			{
				maxcot = matrix[i][j];
			}
		}
		maxtungcot[j] = maxcot;
		cout << "Cot" << j + 1 << "Max la:" << maxtungcot[j] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] > maxtoanmatran)
			{
				maxtoanmatran = matrix[i][j];
			}
		}
	}
	cout << "Toan ma tran" << "Max la:" << maxtoanmatran << endl;
}
void tim_Min_dong_cot_matran(int matrix[][50], int mintungdong[], int mintungcot[], int n)
{
	int mindong = matrix[0][0], mincot = matrix[0][0], mintoanmatran = matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] < mindong)
			{
				mindong = matrix[i][j];
			}
		}
		mintungdong[i] = mindong;
		cout << "Dong " << i + 1 << " Min la: " << mintungdong[i] << endl;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (matrix[i][j] < mincot)
			{
				mincot = matrix[i][j];
			}
		}
		mintungcot[j] = mincot;
		cout << "Cot" << j + 1 << "Min la:" << mintungcot[j] << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] < mintoanmatran)
			{
				mintoanmatran = matrix[i][j];
			}
		}
	}
	cout << "Toan ma tran" << "Min la:" << mintoanmatran << endl;
}
void tim_Max_duave_duongCheochinh(int matrix[][50], int n)
{
	int maxdong = matrix[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] > maxdong)
			{
				maxdong = matrix[i][j];
			}
		}
		for (int k = 0; k < n; k++)
		{
			for (int h = 0; h < n; h++)
			{
				if (maxdong == matrix[k][h])
				{
					swap(matrix[k][h], matrix[i][i]);
				}
			}
		}
		
	}
}