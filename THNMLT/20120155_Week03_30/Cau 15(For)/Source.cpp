#include<iostream>
using namespace std;

int fibonacci(int n)
{
	int f0 = 0, f1 = 1, fn = 1;
	if (n == 0 || n == 1)
		return n;
	else
	{
		for (int i = 2; i < n; i++)
		{
			f0 = f1;
			f1 = fn;
			fn = f0 + f1;
		}
	}
	return fn;

}
int main()
{
	int n;
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n < 0)
		{
			cout << "Nhap lai(n >= 0)" << endl;
		}
	} while (n < 0);
	
	cout << fibonacci(n-1) ;
	

	system("pause");
}