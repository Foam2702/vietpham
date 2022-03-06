#include"Header.h"

void Input(Diem2D diem)
{
	cout << "Nhap iX:"; cin >> diem.iX;
	cout << "Nhap iY:"; cin >> diem.iY;
}
void Output(Diem2D diem)
{
	cout << "(" << diem.iX << "," << diem.iY << ")";
}
double Khoangcach_haidiem(Diem2D diem1, Diem2D diem2)
{
	return sqrt(pow((diem2.iX - diem1.iX), 2)) + pow((diem2.iY - diem1.iY), 2);
}
void GocPhanTuTrongMatPhang(Diem2D a)
{
	if (a.iX == 0 && a.iY == 0)
		cout << "Trung diem goc (0,0) " << endl;
	else if (a.iX > 0 && a.iY > 0)
		cout << "Diem nam o goc phan tu thu nhat " << endl;
	else if (a.iX < 0 && a.iY>0)
		cout << "Diem nam o goc phan tu thu hai " << endl;
	else if (a.iX < 0 && a.iY < 0)
		cout << "Diem nam o goc phan tu thu ba " << endl;
	else if (a.iX > 0 && a.iY < 0)
		cout << "Diem nam o goc phan tu thu tu " << endl;
}

bool KiemTraTamGiac(TamGiac a)
{
	double AB = Khoangcach_haidiem(a.A, a.B);
	double BC = Khoangcach_haidiem(a.B, a.C);
	double AC = Khoangcach_haidiem(a.A, a.C);

	if (AB + BC <= AC || AB + AC <= BC || AC + BC <= AB)
		return false;
	return true;
}

void InputTamGiac(TamGiac& a)
{
	bool check = true;
	do
	{
		cout << "Nhap toa do A: " << endl;
		Input(a.A);
		cout << "Nhap toa do B: " << endl;
		Input(a.B);
		cout << "Nhap toa do C: " << endl;
		Input(a.C);
		check = KiemTraTamGiac(a);
		if (check == false)
			cout << "Khong tao tam giac, nhap lai" << endl;
	} while (check == false);
}

void OutputTamGiac(TamGiac a)
{
	cout << "((" << a.A.iX << "," << a.A.iY << ");(" << a.B.iX << "," << a.B.iY << ");(" << a.C.iX << "," << a.C.iY << "))" << endl;
}

float ChuViTamGiac(TamGiac a)
{
	float AB = Khoangcach_haidiem(a.A, a.B);
	float BC = Khoangcach_haidiem(a.B, a.C);
	float AC = Khoangcach_haidiem(a.A, a.C);

	float CV = AB + BC + AC;
	return CV;
}

float DientichTamGiac(TamGiac a)
{
	float AB = Khoangcach_haidiem(a.A, a.B);
	float BC = Khoangcach_haidiem(a.B, a.C);
	float AC = Khoangcach_haidiem(a.A, a.C);
	float CV = ChuViTamGiac(a);
	float p = CV / 2;
	float DT = sqrt(p * (p - AB) * (p - BC) * (p - AC));
	return DT;
}

int DiemTrongTamGiac(Diem2D d, Diem2D a, Diem2D b, Diem2D c)
{
	int as_iX = d.iX - a.iX;
	int as_iY = d.iY - a.iY;
	bool d_ab = (b.iX - a.iX) * as_iY - (b.iY - a.iY) * as_iX > 0;

	if ((c.iX - a.iX) * as_iY - (c.iY - a.iY) * as_iX > 0 == d_ab)
		return 0;

	if ((c.iX - b.iX) * (d.iY - b.iY) - (c.iY - b.iY) * (d.iX - b.iX) > 0 != d_ab)
		return 0;

	return 1;
}