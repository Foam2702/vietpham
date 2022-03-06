#include"Header.h"

int main()
{
	int matrix[50][50], dong, cot, k;
	nhapMatran(matrix, dong, cot);
	cout << "Ma tran da nhap: " << endl;
	xuatMatran(matrix, dong, cot);
	do
	{
		cout << "Nhap k: ";
		cin >> k;
		if (k <= 0 || k >= min(dong, cot))
			cout << "Nhap lai:" << endl;
	} while (k <= 0 || k >= min(dong, cot));
	cout << "Tong cua so " << k << "x" << k << " lon nhat : " << tong(matrix, dong, cot, k) << endl;
	system("pause");
}