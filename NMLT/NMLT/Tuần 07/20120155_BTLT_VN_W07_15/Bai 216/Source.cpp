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
int demchan(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			count++;
		}
	}
	return count;
}