#include"Header.h"

int main()
{
	ToaDo a, b;
	cout << "Toa do ToaDo A(x,y)" << endl; Input_Tinh(a);
	cout << "Toa do ToaDo B(x,y)" << endl; Input_Tinh(b);
	Output_Tinh(a);
	Output_Tinh(b);
	cout << "Khoang cach giua hai ToaDo : " << KhoangCach2ToaDo(a, b) << endl;
	system("pause");
}