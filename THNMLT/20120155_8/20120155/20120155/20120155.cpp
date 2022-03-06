#include"Header.h"

int main()
{
	Xe list[50];
	int n = 0, luachon = 0;
	while (true)
	{	
		cout << "----------------MENU-----------------"<<endl;
		cout << "1:Nhap va in thong tin danh sach xe" << endl;
		cout << "2:Dem va xuat Toyota diem >=8" << endl;
		cout << "3:Sap xep tang dan" << endl;
		cout << "0:Thoat"<<endl;
		cout << "Nhap lua chon:"; cin >> luachon;
		switch (luachon)
		{
		case 1:
			do
			{
				cout << "Nhap so luong xe:"; cin >> n;
				if (n < 2 || n>20)
				{
					cout << "So luong xe phai thuoc doan [2;20]";
				}
			} while (n < 2 || n>20);
			Input_DsXe(list, n);
			Output_DsXe(list, n);
			break;
		case 2:
			Dem_Xuat_Toyota_8(list, n);
			break;
		case 3:
			cout << "Sau khi sap xep" << endl;
			Sapxep_Alphabet(list, n);
			break;
		case 0:
			exit(0);
			break;
			
		}
	}
	system("pause");
}