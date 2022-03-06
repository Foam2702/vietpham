#include<iostream>
using namespace std;

bool KiemtraToansochan(int n)
{	
	int temp;
	temp = n;
	while (temp != 0)
	{
		int value = temp % 10;
		if (value % 2 != 0)
		{
			return false;
			break;
		}
		temp /= 10;
	}
	return true;
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
	
	if (KiemtraToansochan(n))
	{
		cout << n << " toan bo la chu so chan";
	}
	else
	{
		cout << n << " khong phai toan bo la so chan";
	}
}