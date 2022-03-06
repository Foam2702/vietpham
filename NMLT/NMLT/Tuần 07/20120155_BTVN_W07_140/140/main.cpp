#include"Header.h"

int main()
{
	double a[100];
	int n;
	do
	{
		cout << "Nhap n :"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai lon hon 0";
		}
	} while (n <= 0);
	Input(a, n);
	if (FindMin(a, n) == -1)
	{
		cout << "Khong co gia tri nao";
	}
	else
		cout << "Gia tri duong nho nhat :" << FindMin(a, n);
}