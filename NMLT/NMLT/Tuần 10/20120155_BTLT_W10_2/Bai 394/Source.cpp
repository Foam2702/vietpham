#include<iostream>
using namespace std;

void nhapMatran(int matrix[][50], int& n, int& m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> matrix[i][j];
		}
	}
}
void xuatMatran(int matrix[][50], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void dichXuong_xoayVong_CachangtrongMatran(int a[][50], int n, int m) 
{ 
	for (int i = m - 1; i >= 1; i--)
	{
		for (int j = 0; j < n; j++)
		{
			swap(a[i][j], a[i - 1][j]);
		}
	}
}
int main()
{
	int matrix[50][50];
	int n, m;
	do
	{
		cout << "Nhap so dong: "; cin >> n;
		cout << "Nhap so cot: "; cin >> m;
		if (n <= 0 || m <= 0)
		{
			cout << "dong va cot phai lon hon hoac bang 0" << endl;
		}
	} while (n <= 0 || m <= 0);
	nhapMatran(matrix, n, m);
	xuatMatran(matrix, n, m);
	dichXuong_xoayVong_CachangtrongMatran(matrix, n, m);
	xuatMatran(matrix, n, m);
}

