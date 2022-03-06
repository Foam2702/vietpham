#include"Header.h"

int main()
{
	double a[100];
	int n, k;
	Input(a, n);
	do
	{
		cout << "Vi tri muon xoa (0 -> " << n - 1 << "):";
		cin >> k;
		if (k < 0 || k >= n)
		{
			cout << "Nhap lai "<<endl;
		}
	} while (k < 0 || k >= n);
	xoavitri(a, n, k);
	cout << "Mang sau khi xoa: " << endl;
	Output(a, n);
	system("pause");
}