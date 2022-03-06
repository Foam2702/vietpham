#include<iostream>
using namespace std;

bool KtrasoHoanthien(int n)
{	
	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
		}
	}
	if (sum == n)
	{
		return true;
	}
	else
	{
		return false;
	}
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
	if (KtrasoHoanthien(n))
	{
		cout << n << " la so hoan thien";
	}
	else
	{
		cout << n << " khong la so hoan thien";
	}
	
}