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

bool check_SoDoiXung(int n)
{
	int sum = 0, temp = n, r;
	while (temp != 0)
	{
		r = temp % 10;
		sum = sum * 10 + r;
		temp /= 10;

	}
	if (sum == n)
	{
		return true;
	}
	return false;
}

int demdoixung(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (check_SoDoiXung(a[i]))
			count++;
	}
	return count;
}