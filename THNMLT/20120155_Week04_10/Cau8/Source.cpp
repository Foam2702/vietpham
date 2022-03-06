#include<iostream>
using namespace std;

void HoanviSoNguyenCach1(int &a, int &b)
{
	int tempt = a;
	a = b;
	b = tempt;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}
void HoanviSoNguyenCach2(int &a, int &b)
{
	a = a - b;
	b = a + b;
	a = b - a;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}
int main()
{
	int a, b,a1,b1;
	
	cout << "Nhap a:"; cin >> a;
	a1 = a;
	cout << "Nhap b:"; cin >> b;
	b1 = b;
		
	cout << "Hoan vi cach 1:"<<endl;
	HoanviSoNguyenCach1(a, b);
	cout << "Hoan vi cach 2:"<<endl;
	HoanviSoNguyenCach2(a1, b1);
	system("pause");
}