#include"Header.h"

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
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

void lietKe_SNT(int a[], int n)
{
	bool check = false;
	cout << "Vi tri:";
	for (int i = 0; i < n; i++)
	{
		if (checkPrime(a[i]))
		{
			check = true;
			cout << i << " ";
		}

	}
	if (check == false)
		cout << "Khong co so nguyen to trong mang";
	cout << endl;
}