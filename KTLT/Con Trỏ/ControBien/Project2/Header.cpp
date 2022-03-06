#include"Header.h"

void Nhap(int*& a)
{

	cout << "Nhap 3 so a,b,c:" << endl;
	a = new int[4];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
}

void Xuat(int* a)
{
	int max = INT_MIN;
	for (int i = 0; i < 3; i++)
		if (a[i] > max)
			swap(max, a[i]);
	cout << "Dia chi gia tri lon nhat: " << &max << endl;
	cout << "gia tri lon nhat: " << max << endl;
}