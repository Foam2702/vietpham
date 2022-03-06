#include"Header.h"

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

void lietKe_soChan_lanCan_soChan(int a[], int n)
{
	bool check = false;
	if (a[0] % 2 == 0)
	{
		if (a[1] % 2 == 0)
		{
			check = true;
			cout << a[0] << "(" << a[0] << " " << a[1] << ")" << endl;
		}
	}
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i - 1] % 2 == 0 || a[i + 1] % 2 == 0)
			{
				check = true;
				cout << a[i] << "(" << a[i - 1] << " " << a[i] << " " << a[i + 1] << ")" << endl;

			}
		}
	}
	cout << endl;
	if (check == false)
	{
		cout << "Khong co gia tri thoa yeu cau bai toan" << endl;

	}
}