#include"Header.h"

int main()
{
	hs a[100];
	int n;
	int choose;
	cout << "----------------MENU-----------------" << endl;
	cout << "0:Ket thuc chuong trinh" << endl;
	cout << "1:Sanh sach sap xep theo thu tu alphabet " << endl;
	cout << "2:Ten khac nhau trong danh sach" << endl;
	cout << "3:Hoc sinh co diem cao nhat" << endl;
	cout << "-------------------------------------" << endl;
	do
	{
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
			cout << "Nhap so hoc sinh: ";
			cin >> n;
			Input(a, n);
			Output(a, n);
			Sapxep(a, n);
			cout << "Danh sach sau khi sap xep: " << endl;
			Output1(a, n);
			break;
		case 2:
			cout << "Nhap so hoc sinh: ";
			cin >> n;
			Input(a, n);
			Output(a, n);
			locTen(a, n);
			break;
		case 3:
			cout << "Nhap so hoc sinh: ";
			cin >> n;
			Input(a, n);
			Output(a, n);
			cout << "Nhung hoc sinh diem cao nhat: " << endl;
			FindMax(a, n);
			break;

		}
	} while (choose != 0);
	system("pause");

}