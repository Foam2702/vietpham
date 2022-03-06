#include"Header.h"

int main()
{
	int n;
	double a[100];
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	Input(a, n);
	cout << "Cac vi tri co gia tri lon nhat trong mang la:";
	lietKe_Max(a, n);
	system("pause");
}