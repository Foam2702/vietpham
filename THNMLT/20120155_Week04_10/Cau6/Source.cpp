#include<iostream>
using namespace std;

void nhapSoDuong(int& a,int& b)
{
	do
	{
		cout << "Nhap a :"; cin >> a;
		cout << "Nhap b :"; cin >> b;
		if (a <= 1 && a >= 10000000||b <= 1 && b >= 10000000)
		{
			cout << "n phai la so nguyen duong";
		}
	} while (a <= 1 && a >= 10000000 || b <= 1 && b >= 10000000);
}

int timUCLN(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else if (a < b)
			b -= a;
	}
	return a;
}

int main()
{
	int a, b;
	nhapSoDuong(a, b);
	cout << "UCLN(" << a << "," << b << "):" << timUCLN(a, b);
	system("pause");
}