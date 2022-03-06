#include"Header.h"

void Input(double a[], int& n)
{	
	do
	{
		cout << "Nhap so luong phan tu:"; cin >> n;
		if (n <= 0)
		{
			cout << "So luong phan tu phai lon hon 0" << endl;
		}
	} while (n <= 0);

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu cua mang: ";
		cin >> a[i];
	}
}
double TongMang(double a[], int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return sum;
}