#include<iostream>
using namespace std;

double TinhTong(double x, int n)
{
	double sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += pow(x, i);
	}
	return sum;
}
int main()
{
	int n;
	double x, sum = 0;

	do
	{
		cout << "Nhap n:"; cin >> n;
		cout << "Nhap x:"; cin >> x;
		if (n < 1 || x == 0)
		{
			cout << "Nhap lai (n>=1 && x!=0)" << endl;
		}
	} while (n < 1 || x == 0);
	sum = TinhTong(x, n);
	cout << sum;
	system("pause");
}