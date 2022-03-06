#include<iostream>
using namespace std;

void nhapSoDuong(int& n)
{
	do
	{
		cout << "Nhap n : "; cin >> n;
		if (n < 0)
		{
			cout << "n phai la so nguyen duong";
		}
	} while (n < 0);
}

int tinhF(int n)
{
	int F0 = 1, F1 = 2,Fn=0;
	for (int i = 2; i <= n; i++)
	{	

		Fn = 3 * F1 - 2 * F0;
		F0 = F1;
		F1 = Fn;
	}
	return Fn;
}
int main()
{
	int n;
	nhapSoDuong(n);
	cout << "F" << n <<" = "<< tinhF(n);
	system("pause");
}