#include"doubleArry.h"

void nhapMang(double a[], int& n)
{
	for (int i = 0; i < n; i++)
	{	
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}
void xuatMang(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}