#include<iostream>
using namespace std;

double TinhTong(int N)
{
	double sum = 0;
	int i = 1;
	while (i <= N)
	{
		sum += (1 / (double)i);
		i++;
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