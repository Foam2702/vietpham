#include<iostream>
using namespace std;

int main()
{
	int n;
	double x;
	do
	{
		cout << "Nhap n:"; cin >> n;
		cout << "Nhap x:"; cin >> x;
		if (n <= 0)
		{
			cout << "n phai lon hon 0"<<endl;
		}
	} while (n <= 0);
	cout << pow(x * x + 1, n);
}