#include"Header1.h"

void main()
{
	SinhVien *sv1 = TaoSV();
	Xuat(sv1);
	SinhVien sv;
	SinhVien* sv2;
	sv2 = &sv;
	Nhap(sv2);
	Xuat(sv2);
	system("pause");
}