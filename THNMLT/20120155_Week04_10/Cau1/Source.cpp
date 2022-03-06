#include<iostream>
using namespace std;

void nhapSoDuong(int &n)
{
	do
	{
		cout << "Nhap n :"; cin >> n;
		if (n <= 1 && n >= 10000000)
		{
			cout << "n phai la so nguyen duong";
		}
	} while (n <= 1 && n>=10000000);
}

bool ktSonguyenTo(int n)
{
	if (n < 2)
		return false;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool ktSoHoanChinh(int n)
{
	int S = 0, P = 1;
	
	if (ktSonguyenTo(n))
		return false;

	else
	{
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				S += i;
				P *= i;
			}
		}
		if (S == P)
		{
			return true;
		}
	}
	
	return false;
}

int main()
{
	int n = 0;
	nhapSoDuong(n);
	if (ktSoHoanChinh(n))
	{
		cout << n << " la so hoan chinh";
	}
	else
	{
		cout << n << " khong la so hoan chinh";
	}
		
	system("pause");
}