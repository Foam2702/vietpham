#include<iostream>
#include<cmath>
using namespace std;

bool KtraSochinhphuong(int n)
{
	for (int i = 1; i < n; i++)
	{
		if (i * i == n)
		{
			return true;
			break;
		}

	}
	return false;
	
}

int main()
{
	int n;
	do {
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai la so nguyen duong" << endl;
		}
	} while (n <= 0);
	if (KtraSochinhphuong(n))
	{
		cout << n << " la so chinh phuong";
	}
	else
	{
		cout << n << " khong la so chinh phuong";
	}

	
}
