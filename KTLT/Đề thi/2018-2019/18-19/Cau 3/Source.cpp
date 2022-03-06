#include<iostream>
using namespace std;

void InNhiPhan(int n)
{
	if (n != 0)
	{
		InNhiPhan(n / 2);
		cout << n % 2;
	}
	
}

long NhiPhan(int a)
{
	long b;
	if (a == 0)
		return 0;
	else
		b = a % 2;
	return NhiPhan(a / 2) * 10 + b;
}



int main()
{
	int n; cin >> n;
	InNhiPhan(n);
	cout << endl;
	int value = NhiPhan(n);
	cout << value;
	return 0;
}