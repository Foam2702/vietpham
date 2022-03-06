#include"Header.h"

double KhoangCach2ToaDo(ToaDo a, ToaDo b)
{
	double KC = sqrt(pow(abs((b.x - a.x)), 2) + pow(abs((b.y - a.y)), 2));
	return KC;
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
void ReadFile(ifstream &in,TamGiac TG[],int n)
{	
	
	for (int i = 0; i < n; i++)
	{

		in >> TG[i].A.x >> TG[i].A.y;
		in >> TG[i].B.x >> TG[i].B.y;
		in >> TG[i].C.x >> TG[i].C.y;
	}
}

void WriteFile(ofstream &out,TamGiac TG[],int n)
{
	for (int i = 0; i < n; i++)
	{
		out << "Toa do tam giac " << i + 1 << ":" << endl;
		out << "((" << TG[i].A.x << "," << TG[i].A.y << ");(" << TG[i].B.x << "," << TG[i].B.y << ");(" << TG[i].C.x << "," << TG[i].C.y << "))" << endl;
		out << "Chu vi tam giac " << i + 1 << ChuViTamGiac(TG[i]) << endl;
	}
	out << "Tam giac co chu vi lon nhat la tam giac thu : " << tamgiac_Chuvi_Lonnhat(TG, n);
}


int tamgiac_Chuvi_Lonnhat(TamGiac TG[], int n)
{
	
	double max = ChuViTamGiac(TG[0]);
	int k = 0;

	for (int i = 1; i < n; i++)
	{
		if (max < ChuViTamGiac(TG[i]))
		{
			max = ChuViTamGiac(TG[i]);
			
			k = i;
		}
	}
	return k + 1;
	

}