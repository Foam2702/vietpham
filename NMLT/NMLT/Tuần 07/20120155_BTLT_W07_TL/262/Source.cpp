#include"Header.h"

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void chantang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{	
			if (a[i] > a[j] && (a[i] % 2 == 0 && a[j] % 2 == 0))
			{
				swap(a[i],a[j]);
			}
			else if (a[i] > a[j] && (a[i] % 2 != 0 && a[j] % 2 != 0))
			{
				swap(a[i],a[j]);
			}
		}
	}
}

