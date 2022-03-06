#include<iostream>
using namespace std;


//bai 1
void InputArray_1D(int*& a, int& n)
{
	cout << "Hay nhap phan tu cua mang mot chieu: ";
	cin >> n;
	a = new int[n];
	cout << "Hay nhap gia tri phan tu trong mang mot chieu: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void FreeArray_1D(int* a)
{
	delete[]a;
}

void OutputArray_1D(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << "a[" << i << "]= " << a[i] << endl;
}

//bai2 
void InputMatrix(int**& a, int& n)
{
	cout << "Hay nhap kich thuoc cua ma tran vuong:  ";
	cin >> n;
	a = new int* [n];
	cout << "Nhap gia tri ma tran tai vi tri: " << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << " a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}

void OutputMatrix(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void FreeMatrix(int**& a, int n)
{
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
}

void main()
{
	int n,m;
	cout << "1:bai 1" << endl;
	cout << "2:bai 2" << endl;
	cout << "0:de dung chuong trinh" << endl;
	while (true)
	{
		cout << "Nhap bai thay muon thuc hien: ";
		cin >> m;
		if (m == 1)
		{
			int* a = NULL;
			InputArray_1D(a, n);
			OutputArray_1D(a, n);
			FreeArray_1D(a);
		}
		else if (m == 2)
		{
			int** a = NULL;
			InputMatrix(a, n);
			cout << endl;
			OutputMatrix(a, n);
			FreeMatrix(a, n);
		}
		else if (m == 0) break;
	}	
}