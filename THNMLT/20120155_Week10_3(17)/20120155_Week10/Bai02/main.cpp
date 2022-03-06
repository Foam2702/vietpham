#include"Header.h"

int main()
{
	Diem2D a, b, c, d;
	TamGiac m;
	int choose;
	cout << "----------------MENU-----------------" << endl;
	cout << "0:Ket thuc chuong trinh" << endl;
	cout << "1:Nhap Xuat diem " << endl;
	cout << "2:Tinh khoang cach giua 2 diem" << endl;
	cout << "3:Kiem tra diem nam trong goc phan tu nao cua mat phang" << endl;
	cout << "4:Tinh chu vi, dien tich cua tam giac" << endl;
	cout << "5:Kiem tra diem thu 4 co nam trong tam giac " << endl;
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
			Input(a);
			Output(a);
			break;
		case 2:
			cout << "Nhap diem A: " << endl;
			Input(a);
			cout << "A=";
			Output(a);
			cout << "Nhap diem B: " << endl;
			Input(b);
			cout << "B=";
			Output(b);
			cout << "Khoang cach 2 diem: " << Khoangcach_haidiem(a, b) << endl;
			break;
		case 3:
			Input(a);
			Output(a);
			GocPhanTuTrongMatPhang(a);
			break;
		case 4:
			InputTamGiac(m);
			OutputTamGiac(m);
			cout << "Chu vi tam giac: " << ChuViTamGiac(m) << endl;
			cout << "Dien tich tam giac: " << DientichTamGiac(m) << endl;
			break;
		case 5:
			InputTamGiac(m);
			OutputTamGiac(m);
			cout << "Nhap diem D: " << endl;
			Input(d);
			int k = DiemTrongTamGiac(d, m.A, m.B, m.C);
			if (k == 1)
				cout << "Diem d co nam trong tam giac" << endl;
			else
				cout << "Diem d khong nam trong tam giac" << endl;
			break;
		}
	} while (choose != 0);
	system("pause");

}