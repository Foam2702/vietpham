#include<iostream>
using namespace std;

int main()
{
	int a, b;
	do {
		cout << "Nhap a:"; cin >> a;
		cout << "Nhap b:"; cin >> b;
		if (a <= 0 || b <= 0)
		{
			cout << "a va b phai la 2 so nguyen duong"<<endl;
		}
	} while (a <= 0 || b <= 0);
	a = a - b;
	b = a + b;
	a = b - a;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}