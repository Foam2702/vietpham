#include"Header.h"


void ReadFile(ifstream& in, ToaDo& a,ToaDo &b)
{
	
	in >> a.x >> a.y;
	in >> b.x >> b.y;
	
	
}
double KhoangCach2ToaDo(ToaDo a, ToaDo b)
{
	double KC = sqrt(pow(abs((b.x - a.x)), 2) + pow(abs((b.y - a.y)), 2));
	return KC;
}
void WriteFile(ofstream& out, ToaDo a,ToaDo b)
{	
	double KC;
	KC = KhoangCach2ToaDo(a,b);
	out << "a(" << a.x << "," << a.y << ")" << endl;
	out << "b(" << b.x << "," << b.y << ")" << endl;
	out << "Khoang cach 2 diem:" << KC;

}


