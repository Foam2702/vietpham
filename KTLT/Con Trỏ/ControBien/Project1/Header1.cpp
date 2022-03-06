#include"Header1.h"



void Nhap(SinhVien *SV)
{
	cout << "Nhap ngay thang nam sinh : ";
	cin >> SV->NgaySinh;
	cout << "Nhap ho va ten: ";
	cin.ignore();
	getline(cin, SV->HoTen);
	cout << "Nhap gioi tinh :";
	cin >> SV->GioiTinh;
}

void Xuat(SinhVien* SV)
{
	cout << "Ho va ten: " << SV->HoTen << endl;
	cout << "Ngay sinh: " << SV->NgaySinh << endl;
	cout << "Gioi tinh :" << SV->GioiTinh << endl;

}

SinhVien*TaoSV()
{
	SinhVien* sv = new SinhVien;
	Nhap(sv);
	return sv;
}