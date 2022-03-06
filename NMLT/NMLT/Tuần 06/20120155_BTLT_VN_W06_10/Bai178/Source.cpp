#include"Header.h"

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

void lietKe_soChan_trongDoan(int a[], int n, int x, int y)
{
	for (int i = 0; i < n; i++)
	{

		if (a[i] >= x && a[i] <= y)
		{
			if (a[i] % 2 == 0)
			{
				cout << a[i] << " ";
			}
		}

	}
	cout << endl;
}