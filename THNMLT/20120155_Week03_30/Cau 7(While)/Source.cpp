#include<iostream>
using namespace std;

int TinhTongcacChuso(int n)
{
	int sum = 0, temp = 0,i = n;
	if (i < 0)
		i = -i;
	while (i != 0)
	{
		temp = i % 10;
		sum += temp;
		i /= 10;
	}
	
	return sum;
}
int main()
{
	int n, sum = 0;

	cout << "Nhap n:"; cin >> n;

	sum = TinhTongcacChuso(n);
	cout << sum;
	system("pause");
}
