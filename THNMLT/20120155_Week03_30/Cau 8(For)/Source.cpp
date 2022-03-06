#include<iostream>
using namespace std;

int UCLN(int a, int b)
{
	for (; a != b ;)
	{
		if (a > b)
			a -= b;
		else if (a < b)
			b -= a;
	}
	return a;
}
int BCNN(int a, int b)
{
	int max = 0,i = 0;
	if (a > b)
		max = a;
	else
		max = b;
	i = max;
	for (;i % a != 0 || i % b != 0;)
	{
		i += max;
		
	}
	return i;
}

int main()
{
	int a,b, ucln = 0,bcnn = 0;
	do
	{
		cout << "Nhap a:"; cin >> a;
		cout << "Nhap b:"; cin >> b;
		if (a < 1 || b < 1)
		{
			cout << "Nhap lai(a >= 1 && b>= 1)" << endl;
		}
	} while (a < 1||b < 1);
	ucln = UCLN(a , b);
	cout << "UCLN(a,b)= "<< ucln << endl;
	bcnn = BCNN(a, b);
	cout << "BCNN(a,b)= "<< bcnn;
	system("pause");
}

