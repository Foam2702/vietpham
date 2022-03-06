#include"Header.h"

int main()
{
	int a[100];
	int n;
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai lon hon 0" << endl;
		}
	} while (n <= 0);
	Input(a,n);
	chantang(a, n);
	Output(a, n);
}