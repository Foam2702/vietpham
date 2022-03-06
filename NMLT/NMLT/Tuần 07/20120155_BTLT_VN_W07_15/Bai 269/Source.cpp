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
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void thembaotoan(int a[], int &n, int x)
{	
	int temp = 0;
	if (x > a[n - 1])
	{
		a[n] = x;
	}
	for (int i = 0; i < n; i++)
	{
		if (x < a[i])
		{
			temp = x;
			for (int j = n; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = temp;
			break;
		}
		
	}
	n++;
}
