#include"Header.h"

void Input(double a[], int& n)
{
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai lon hon 0" << endl;
		}

	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

void xoavitribatky(double a[], int &n, int k)
{
	for (int i = k; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

double Max(double a[], int n)
{
	double max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	return max;
}
void xoalonnhat(double a[], int &n)
{
	double max = Max(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
		{
			xoavitribatky(a, n, i);
			i--;
		}
	}
}

void Output(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}