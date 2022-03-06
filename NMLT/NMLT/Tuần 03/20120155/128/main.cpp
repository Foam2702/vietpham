#include "doubleArry.h"

int main()
{
	int n;
	double a[MAX];
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "So phan tu phai lon hon 0"<<endl;
		}
	} while (n <= 0);
	nhapMang(a, n);
	xuatMang(a, n);
	system("pause");
}