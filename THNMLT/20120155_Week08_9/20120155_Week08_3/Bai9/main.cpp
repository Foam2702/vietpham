#include"Header.h"

int main()
{
	int matrix[50][50], dong, cot;
	nhapMatran(matrix, dong, cot);
	cout << "Ma tran truoc khi sap xep: " << endl;
	xuatMatran(matrix, dong, cot);
	cout << "Ma Tran sau khi sap xep: " << endl;
	sapXep_maTran(matrix, dong, cot);
	xuatMatran(matrix, dong, cot);
	system("pause");
}