#include"Header.h"

//cau 541
void Input_Tinh(ToaDo& toado)
{

	cout << "Nhap toa do x: ";
	cin >> toado.x;
	cout << "Nhap toa do y: ";
	cin >> toado.y;


}

//cau 542
void Output_Tinh(ToaDo toado)
{
	cout << "(" << toado.x << "," << toado.y << ")" << endl;
}

//cau 543
double KhoangCach2ToaDo(ToaDo a, ToaDo b)
{
	double KC = sqrt(pow(abs((b.x - a.x)), 2) + pow(abs((b.y - a.y)), 2));
	return KC;
}