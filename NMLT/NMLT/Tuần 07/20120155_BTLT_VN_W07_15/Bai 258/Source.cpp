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

bool checkPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return false;
	}		
	return true;
}

void nguyentotang(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j] && checkPrime(a[i])&&checkPrime(a[j]))
				swap(a[i], a[j]);
		}
	}
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{

		cout << a[i] << " ";
	}
	cout << endl;
}