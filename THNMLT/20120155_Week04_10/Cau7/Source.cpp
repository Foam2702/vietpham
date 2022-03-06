#include<iostream>
using namespace std;


void nhapSoDuong(int& a, int& b)
{
	do
	{
		cout << "Nhap a :"; cin >> a;
		cout << "Nhap b :"; cin >> b;
		if (a <= 1 && a >= 10000000 || b <= 1 && b >= 10000000)
		{
			cout << "n phai la so nguyen duong";
		}
	} while (a <= 1 && a >= 10000000 || b <= 1 && b >= 10000000);
}
int timBCNN(int a, int b)
{	
	int tich = a * b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else if (a < b)
			b -= a;
	}
	return tich / a;
}

int main()
{
	int a, b;
	nhapSoDuong(a, b);
	cout << "BCNN(" << a << "," << b << "):" << timBCNN(a, b);
	system("pause");
}