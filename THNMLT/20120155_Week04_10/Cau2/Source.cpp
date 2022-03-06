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
	} while (n <= 1 && n >= 10000000);
}

bool ktSoDoiXung(int n)
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

int main()
{
	int n;
	nhapSoDuong(n);
	if (ktSoDoiXung(n))
	{
		cout << n << " la so doi xung";
	}
	else
	{
		cout << n << " khong la so doi xung";
	}
	system("pause");
}