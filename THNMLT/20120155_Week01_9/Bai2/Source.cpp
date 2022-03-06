#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	do {
		cout << "Nhap a:"; cin >> a;
		cout << "Nhap b:"; cin >> b;
		cout << "Nhap c:"; cin >> c;
		if (a <= 0 || b <= 0||c <= 0)
		{
			cout << "a b c phai la 2 so nguyen duong" << endl;
		}
	} while (a <= 0 || b <= 0||c <= 0 );
	a = c - a;
	c = c - a;
	b = a + c;
	
	cout << "a:" << a<<endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
}