#include"Header.h"

void Input(double a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

void LietkeSoAm(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			cout << a[i] << " ";
	}
	cout << endl;
}