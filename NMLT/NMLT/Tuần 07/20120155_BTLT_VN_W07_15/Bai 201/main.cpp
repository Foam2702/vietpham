#include"Header.h"

int main()
{
	double a[100];
	int n;
	Input(a,n);
	cout << "Tong cac phan tu duong trong mang : " << TongMangDuong(a,n) << endl;
	system("pause");
}