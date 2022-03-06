#include<iostream>
using namespace std;

double TinhTong(int N)
{
	double sum = 1;
	for (int i = 2; i <= N; i++)
	{
		sum += 1 / (((double)i - 1) * (double)i);

	}
	return sum;
}
int main()
{
	int n;
	double sum = 0;
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n < 2)
		{
			cout << "Nhap lai(n>=2)" << endl;
		}
	} while (n < 2);
	sum = TinhTong(n);
	cout << sum;
	system("pause");
}