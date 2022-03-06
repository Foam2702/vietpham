#include<iostream>
using namespace std;


int Giaithua(int x)
{	
	if (x == 0)
		return 1;
	
	int giaithua = 1;
	for (int i = 1; i <= x; i++)
	{
		giaithua *= i;
	}
	return giaithua;
}
int TinhTong(int n)
{
	
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += Giaithua(i);
	}
	return sum;
}
int main()
{
	int n, sum = 0;
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n < 1)
		{
			cout << "Nhap lai(n>=1)" << endl;
		}
	} while (n < 1);
	sum = TinhTong(n);
	cout << sum;
	system("pause");
}