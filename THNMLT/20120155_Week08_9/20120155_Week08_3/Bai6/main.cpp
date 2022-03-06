#include"Header.h"

int main()
{
	float matrix[50][50];
	int dong, cot;
	nhapMatran(matrix, dong, cot);
	cout << "Ma tran da nhap: " << endl;
	xuatMatran(matrix, dong, cot);
	tim_Cucdai(matrix, dong, cot);
	system("pause");
}