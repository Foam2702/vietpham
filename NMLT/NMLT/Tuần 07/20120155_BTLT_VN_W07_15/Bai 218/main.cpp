#include"Header.h"

int main()
{
	int a[100], n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	Input(a, n);
	cout << "So phan tu doi duong la: " << demdoixung(a, n) << endl;
	system("pause");
}