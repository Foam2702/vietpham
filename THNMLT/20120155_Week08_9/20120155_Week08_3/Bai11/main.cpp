#include"Header.h"

int main()
{
	int matrix1[50][50], matrix2[50][50], dong, cot;
	cout << "Nhap ma tran A" << endl;
	nhapMatran(matrix1, dong, cot);

	cout << "Nhap ma tran B" << endl;
	nhapMatran(matrix2, dong, cot);

	cout << "Ma tran A " << endl;
	xuatMatran(matrix1, dong, cot);

	cout << "Ma tran B " << endl;
	xuatMatran(matrix2, dong, cot);

	phanTu_Trungnhau(matrix1, matrix2, dong, cot);
	cout << "Sau khi doi phan tu  trung thanh so 0" << endl;

	cout << "Ma Tran A" << endl;
	xuatMatran(matrix1, dong, cot);

	cout << "Ma Tran B" << endl;
	xuatMatran(matrix2, dong, cot);

	system("pause");
}