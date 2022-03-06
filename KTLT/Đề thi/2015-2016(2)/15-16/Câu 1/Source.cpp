#include<iostream>
using namespace std;
int f[100];
int fibo(int n)
{
	if (f[n] != 0) return f[n];
	if (n == 1)
	{
		 f[n]=1;

	}
	else if (n == 2)
	{
		 f[n]=1;
	}
	else if (n == 3)
	{
		 f[n]=2;
	}
	else if (n % 2 == 0)
	{	
		int fk = fibo(n / 2);
		int fk1 = fibo(n / 2 + 1);
		f[n] = 2 * fk * fk1 - fk * fk;
	}
	else
	{
		int fk = fibo((n - 1) / 2);
		int fk1 = fibo((n - 1) / 2 + 1);
		f[n] = fk1 * fk1 + fk * fk;
	}
	return f[n];
}

int main()
{
	int n; cin >> n;
	int f = 0;
	f=fibo(n);
	cout << f;
}