#include<iostream>
using namespace std;

int TinhTongcacChuso(int n)
{
	int sum = 0,temp = 0;
	for (int i = n; i != 0; i /= 10)
	{	
		if (i < 0)
			i = -i;
		temp = i % 10;
		sum += temp;
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
