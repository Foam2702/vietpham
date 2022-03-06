#include<iostream>
using namespace std;

int Giaithua(int n)
{	
	int giaithua = 1;
	for (int i = 1; i <= n; i++)
	{
		giaithua *= i;
	}
	return giaithua;
}
int main()
{
	int x = 0, n = 0;
	double tu = 0, mau = 0, sum = 1;

	cout << "Nhap x :"; cin >> x;
	cout << "Nhap n :"; cin >> n;
	
	for (int i = 0; i <= n; i++)
	{	
		tu = pow(x, (2 * i) + 1);
		mau = Giaithua((2 * i) + 1);
		sum += (tu/mau);
	}
	cout << "S(" << n << ")="<< sum;
}