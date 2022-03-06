#include"Header.h"

void NhapToado(ToaDo& toado)
{

	cout << "Nhap toa do x: ";
	cin >> toado.x;
	cout << "Nhap toa do y: ";
	cin >> toado.y;


}

void XuatToaDo(ToaDo toado)
{
	cout << "(" << toado.x << "," << toado.y << ")" << endl;
}

double KhoangCach2ToaDo(ToaDo a, ToaDo b)
{
	double KC = sqrt(pow(abs((b.x - a.x)), 2) + pow(abs((b.y - a.y)), 2));
	return KC;
}

//cau 584
bool KiemTraTamGiac(TamGiac TG)
{
	double AB, AC, BC;
	AB = KhoangCach2ToaDo(TG.A, TG.B);
	BC = KhoangCach2ToaDo(TG.B, TG.C);
	AC = KhoangCach2ToaDo(TG.A, TG.C);

	if (AB + BC <= AC || AB + AC <= BC || AC + BC <= AB)
	{
		return false;
	}
	return true;
}

//cau 582
void NhapTamGiac(TamGiac& TG)
{
	do
	{
		cout << "Nhap toa do A(x,y): " << endl;
		NhapToado(TG.A);
		cout << "Nhap toa do B(x,y): " << endl;
		NhapToado(TG.B);
		cout << "Nhap toa do C(x,y): " << endl;
		NhapToado(TG.C);
		if (KiemTraTamGiac(TG) == false)
			cout << "Khong tao thanh  tam giac, nhap lai" << endl;
	} while (KiemTraTamGiac(TG) == false);
}

//cau 583
void XuatTamGiac(TamGiac TG)
{
	cout << "((" << TG.A.x << "," << TG.A.y << ");(" << TG.B.x << "," << TG.B.y << ");(" << TG.C.x << "," << TG.C.y << "))" << endl;
}

//cau 585
double ChuViTamGiac(TamGiac TG)
{
	double AB, BC, AC, Chuvi;
	AB = KhoangCach2ToaDo(TG.A, TG.B);
	BC = KhoangCach2ToaDo(TG.B, TG.C);
	AC = KhoangCach2ToaDo(TG.A, TG.C);

	Chuvi = AB + BC + AC;
	return Chuvi;
}

//bai 1001
void Nhap_MangTamGiac(TamGiac TG[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap toa do tam giac " << i + 1 << ":" << endl;
		NhapTamGiac(TG[i]);
	}
}

void Xuat_MangTamGiac(TamGiac TG[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Toa do tam giac " << i + 1 << ":" << endl;
		XuatTamGiac(TG[i]);
	}
}
//cau 1002
void tamgiac_Chuvi_Lonnhat(TamGiac TG[], int n)
{
	TamGiac tamgiacmax;
	double max = ChuViTamGiac(TG[0]);

	for (int i = 1; i < n; i++)
	{
		if (max < ChuViTamGiac(TG[i]))
		{
			max = ChuViTamGiac(TG[i]);
			tamgiacmax = TG[i];
		}
	}
	cout << "Tam giac co chu vi lon nhat : " << endl;
	XuatTamGiac(tamgiacmax);
	cout << "chu vi la: " << max << endl;;
}



