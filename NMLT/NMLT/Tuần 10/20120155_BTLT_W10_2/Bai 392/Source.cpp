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
void Hoanvi_haiDongmaTran(int matrix[][50], int n, int m,int dong1,int dong2)
{
	
	for (int j = 0; j < m; j++)
	{
		swap(matrix[dong1][j], matrix[dong2][j]);
	}
		
	
	
}
int main()
{
	int matrix[50][50];
	int n, m,dong1,dong2;
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
	do
	{	
		cout << "Nhap dong thu 1 muon hoa vi:";
		cin >> dong1;
		cout << "Nhap dong thu 2 muon hoa vi:";
		cin >> dong2;
		if ((dong1 >= n) || (dong1 < 0) || (dong2 >= m) || (dong2 < 0))
		{
			cout << "2 dong muon hoan vi khong hop le" << endl;
		}
	} while ((dong1 >= n)||(dong1<0) || (dong2 >= m)||(dong2<0));
	Hoanvi_haiDongmaTran(matrix, n, m, dong1, dong2);
	xuatMatran(matrix, n, m);

}