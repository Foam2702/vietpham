#include"Header.h"


void ReadFile(ifstream& in, TamGiac& TG)
{
	in >> TG.A.x >> TG.A.y;
	in >> TG.B.x >> TG.B.y;
	in >> TG.C.x >> TG.C.y;
}
double KhoangCach2ToaDo(ToaDo a, ToaDo b)
{
	double KC = sqrt(pow(abs((b.x - a.x)), 2) + pow(abs((b.y - a.y)), 2));
	return KC;
}
bool KiemTraTamGiac(TamGiac TG)
{
	double AB, AC, BC;
	AB = KhoangCach2ToaDo(TG.A, TG.B);
	BC = KhoangCach2ToaDo(TG.B, TG.C);
	AC = KhoangCach2ToaDo(TG.A, TG.C);

	if ((AB + BC > AC) && (AB + AC > BC) && (AC + BC > AB))
	{
		return true;
	}
	return false;
}
double ChuViTamGiac(TamGiac TG)
{
	double AB, BC, AC, Chuvi;
	AB = KhoangCach2ToaDo(TG.A, TG.B);
	BC = KhoangCach2ToaDo(TG.B, TG.C);
	AC = KhoangCach2ToaDo(TG.A, TG.C);

	Chuvi = AB + BC + AC;
	return Chuvi;
}
void WriteFile(ofstream& out, TamGiac TG)
{
	if (KiemTraTamGiac(TG))
	{
		out << "La tam giac" << endl;
		out << "((" << TG.A.x << "," << TG.A.y << ");(" << TG.B.x << "," << TG.B.y << ");(" << TG.C.x << "," << TG.C.y << "))" << endl;
		out << "Chu vi tam giac :" << ChuViTamGiac(TG);
	}
	else
	{
		out << "Khong phai la tam giac";
	}
}







