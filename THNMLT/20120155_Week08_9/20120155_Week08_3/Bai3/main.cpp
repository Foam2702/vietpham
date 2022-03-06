#include"Header.h"

int main()
{
	float matrix[50][50];
	int dong, cot, choose;
	while (true)
	{
		cout << "----------------MENU-----------------" << endl;
		cout << "1:Sap xep dung mang phu " << endl;
		cout << "2:Sap xep khong dung mang phu" << endl;
		cout << "0:Ket thuc chuong trinh" << endl;
		cout << "Nhap bai muon chon: ";
		cin >> choose;
		if (choose == 0)
		{
			system("pause");
			return 0;
		}
		switch (choose)
		{
			case 1:
				nhapMatran(matrix, dong, cot);
				cout << "Ma tran da nhap: " << endl;
				xuatMatran(matrix, dong, cot);
				cout << "Ma Tran sau khi sap xep: " << endl;
				sapXep_koMangphu(matrix, dong, cot);
				xuatMatran(matrix, dong, cot);
				break;
			case 2:
				nhapMatran(matrix, dong, cot);
				cout << "Ma tran da nhap: " << endl;
				xuatMatran(matrix, dong, cot);
				cout << "Ma Tran sau khi sap xep: " << endl;
				sapXep_Mangphu(matrix, dong, cot);
				xuatMatran(matrix, dong, cot);
				break;
		}
	}
	
	system("pause");
}