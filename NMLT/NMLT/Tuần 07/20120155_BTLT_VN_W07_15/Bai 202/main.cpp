#include"Header.h"

int main()
{
	int a[100], n;
	
	Input(a, n);
	cout << "Tong cac phan tu co chu so dau le trong mang la: " << TongChuSoLe(a, n) << endl;
	system("pause");
}