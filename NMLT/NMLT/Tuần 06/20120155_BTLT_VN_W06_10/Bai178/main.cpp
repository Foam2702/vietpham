#include"Header.h"

int main()
{
	int n, x, y;
	int a[100];
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	cout << "Nhap x:"; cin >> x;
	cout << "Nhap y:"; cin >> y;
	Input(a, n);
	cout << "Cac gia tri chan thuoc doan [" << x << "," << y << "]: ";
	lietKe_soChan_trongDoan(a, n, x, y);
	system("pause");

}