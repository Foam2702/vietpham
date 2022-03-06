#include"Header.h"

int main()
{
	int n;
	TamGiac TG;
	TamGiac mangTG[100];
	cout << "Nhap toa do tam giac ABC: " << endl;
	NhapTamGiac(TG);
	cout << "Tam giac da nhap: " << endl;
	XuatTamGiac(TG);
	cout << "Chu vi tam giac: " << ChuViTamGiac(TG) << endl;


	do
	{
		cout << "Nhap n tam giac :"; cin >> n;
		if (n <= 0)
		{
			cout << "So luong tam giac phai lon hon 0" << endl;
		}
	} while (n <= 0);
	Nhap_MangTamGiac(mangTG, n);
	Xuat_MangTamGiac(mangTG, n);
	tamgiac_Chuvi_Lonnhat(mangTG, n);
	system("pause");
}