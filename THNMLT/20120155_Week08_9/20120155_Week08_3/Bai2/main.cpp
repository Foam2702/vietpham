#include"Header.h"

int main()
{
	int matrix1[50][50], matrix2[50][50], dong1, cot1, dong2, cot2;
	do 
	{
		cout << "Nhap ma tran 1 " << endl;
		nhapMatran(matrix1, dong1, cot1);
		cout << "Nhap Ma Tran 2 " << endl;
		nhapMatran(matrix2, dong2, cot2);
		cout << "Ma Tran 1 da nhap " << endl;
		xuatMatran(matrix1, dong1, cot1);
		cout << "Ma Tran 2 da nhap " << endl;
		xuatMatran(matrix2, dong2, cot2);
		if (dong1 != dong2 || cot1 != cot2)
			cout << "Hai ma tran phai cung kich co" << endl;
	} while (dong1 != dong2 || cot1 != cot2);
	cout << "Tong 2 Ma Tran " << endl;
	CongMaTran(matrix1, matrix2, dong1, cot1, dong2, cot2);
	cout << "Tich 2 Ma Tran" << endl;
	TichMaTran(matrix1, matrix2, dong1, cot1, dong2, cot2);
	system("pause");
}