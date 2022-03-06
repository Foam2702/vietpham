#include"Header.h"

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

void lietKe_Abs_soDungtruoc(int a[], int n)
{
	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > abs(a[i + 1]))
		{
			check = true;
			cout << a[i] << "(" << a[i] << ">" << a[i + 1] << ")" << endl;
		}

	}
	cout << endl;
	if (check == false)
	{
		cout << "Khong co gia tri thoa yeu cau bai toan" << endl;
	}
}

