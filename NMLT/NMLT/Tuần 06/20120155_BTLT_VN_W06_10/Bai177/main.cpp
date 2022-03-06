#include"Header.h"

int main()
{
	int n, x, y;
	double a[100];
	cout << "Nhap so phan tu cua mang: "; cin >> n;

	cout << "Nhap x:"; cin >> x;

	cout << "Nhap y:"; cin >> y;

	Input(a, n);
	cout << "Cac gia tri thuoc doan [" << x << "," << y << "]: ";
	lietKe_giaTri_trongDoan(a, n, x, y);
	system("pause");

}