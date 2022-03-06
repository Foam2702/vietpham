#include"Header.h"

int main()
{
	int matrix[50][50], dong, cot;
	nhapMatran(matrix, dong, cot);
	cout << "Ma tran da nhap: " << endl;
	xuatMatran(matrix, dong, cot);
	diem_Yenngua(matrix, dong, cot);
	system("pause");
}