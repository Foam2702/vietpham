#include"Header.h"

int main()
{
	int n;
	int a[100];
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	Input(a, n);
	lietKe_Abs_soDungtruoc_soDungsau(a, n);
	system("pause");
}