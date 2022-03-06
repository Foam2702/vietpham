#include"Header.h"

int main()
{
	Tinh mang_tinh[100];
	int n;
	do
	{
		cout << "Nhap so Tinh: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "So luong tinh phai lon hon 0" << endl;
		}
	} while (n <= 0);
	Input_Tinh(mang_tinh, n);
	while (true)
	{
		cout << "--------------MENU-----------------" << endl;
		cout << "1:Xuat cac tinh co dan so lon hon 1.000.000" << endl;
		cout << "2:Tim mot tinh co dien tich lon nhat" << endl;
		cout << "3:Sap xep cac tinh giam dan theo dien tich" << endl;
		cout << "0:Thoat" << endl;
		cout << "--------------------------------------" << endl;
		int choose;
		cout << "Nhap so bai: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{

			Output_Tinhdanso(mang_tinh, n);
			system("pause");
			break;
		}
		case 2:
		{
			cout << "Tinh co dien tich lon nhat" << endl;
			Dientich_Lonnhat(mang_tinh, n);
			break;
		}
		case 3:
		{	cout << "Danh Sach cac Tinh sau khi sap xep:" << endl;
		Sapxep_Dientich_Giamdan(mang_tinh, n);
		system("pause");
		break;
		}
		case 0:
			exit(0);
		}
	}
	system("pause");
}