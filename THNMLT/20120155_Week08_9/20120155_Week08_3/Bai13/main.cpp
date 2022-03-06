#include"Header.h"

int main()
{
	int matrix[50][50], dong, cot;
	nhapMatran(matrix, dong, cot);
	cout << "Ma tran da nhap: " << endl;
	xuatMatran(matrix, dong, cot);
	cout << "Ma Tran sau khi sap xep: " << endl;
	sort_Matrix(matrix, dong, cot);
	xuatMatran(matrix, dong, cot);
	system("pause");
}