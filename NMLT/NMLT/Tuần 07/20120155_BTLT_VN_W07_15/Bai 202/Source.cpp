#include"Header.h"

void Input(int a[], int& n)
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

bool check_ChuSoDauLe(int x)
{
	if (x < 0)
		x = -x;
	while (x >= 10 )
		x /= 10;
	if (x % 2 == 0)
		return false;
	return true;
}

int TongChuSoLe(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (check_ChuSoDauLe(a[i]))
			sum += a[i];
	}
	return sum;
}