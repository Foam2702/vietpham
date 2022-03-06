#include<iostream>
using namespace std;

void nhapSoDuong(int& n)
{
	do
	{
		cout << "Nhap n :"; cin >> n;
		if (n <= 1 && n >= 10000000)
		{
			cout << "n phai la so nguyen duong";
		}
	} while (n <= 1 && n >= 10000000);
}

int timChuSoLonNhat(int n)
{	
	int temp = n, max = 0, r;
	
	while (temp > 0)
	{	
		r = temp % 10;
		if (r >= max)
			max = r;
		temp /= 10;
	}
	return max;
}
int main()
{
	int n;
	nhapSoDuong(n);
	cout << "Chu so lon nhat :" << timChuSoLonNhat(n);
	system("pause");
}