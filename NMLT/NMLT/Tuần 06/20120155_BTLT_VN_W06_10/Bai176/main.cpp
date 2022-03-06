#include"Header.h"

int main()
{
	int n;
	double a[100];
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	Input(a, n);
	cout << "So am trong mang: ";
	LietkeSoAm( a, n);
	system("pause");
}