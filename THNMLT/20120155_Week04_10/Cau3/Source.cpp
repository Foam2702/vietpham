#include<iostream>
using namespace std;

void nhapSoDuong(int& n)
{
	do
	{
		cout << "Nhap n :"; cin >> n;
		if (n <= 1 && n >= 10000000)
		{
			cout << "n phai la so nguyen duong";
		}
	} while (n <= 1 && n >= 100000000);
}
bool ktSoHoanHao(int n)
{	
	int S = 0, P = n * 2;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			S += i;
		}
	}
	if (S == P)
	{
		return true;
	}
	return false;
	
}

int main()
{
	int n = 0;
	nhapSoDuong(n);
	if (ktSoHoanHao(n))
	{
		cout << n << " la so hoan hao";
	}
	else
	{
		cout << n << " khong la so hoan hao";
	}

	system("pause");
}