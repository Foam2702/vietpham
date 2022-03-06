#include<iostream>
using namespace std;

double TinhTong(int N)
{
	double sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += (1 / (double)i);
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
		if (n < 1)
		{
			cout << "Nhap lai(n>=1)" << endl;
		}
	} while (n < 1);
	sum = TinhTong(n);
	cout << sum;
	system("pause");
}