#include<iostream>
using namespace std;

int TinhTong(int N)
{	
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += pow(i, 3);
	}
	return sum;
}
int main()
{
	int n, sum = 0 ; 
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n < 1)
		{
			cout << "Nhap lai(n>=1)" <<endl;
		}
	} while (n < 1);
	sum = TinhTong(n);
	cout << sum;
	system("pause");
}

