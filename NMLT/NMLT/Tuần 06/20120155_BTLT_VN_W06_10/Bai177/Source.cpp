#include"Header.h"

void Input(double a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

void lietKe_giaTri_trongDoan(double a[], int n, int x, int y)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x && a[i] <= y)
		{
			cout << a[i] << " ";
		}

	}
	cout << endl;
}