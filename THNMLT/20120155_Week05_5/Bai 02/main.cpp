#include"Header.h"

int main()
{
	int a, b, c, d;
	int choose, x=0;
	while(true)
	{
		cout << "////////////////MENU////////////////" << endl;
		cout << "1:Toi gian phan so" << endl;
		cout << "2:Tinh tong 2 phan so" << endl;
		cout << "3:Tinh tich 2 phan so" << endl;
		cout << "0:Ket thuc chuong trinh" << endl;
		cout << "/////////////////////////////////////" << endl;
	
			cout << "Nhap bai muon chon: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
			{	
				do
				{
					cout << "Nhap tu:";
					cin >> a;
					cout << "Nhap b: ";
					cin >> b;
					if (b == 0)
					{
						cout << "Mau phai khac 0" << endl;
					}
				} while (b == 0);
				ToiGianPhanSo(a, b);
				break;
			}
			case 2:
			{	Input(a, b, c, d);
				TongHaiPhanSo(a, b, c, d);
				break;
			}
			case 3:
			{	Input(a, b, c, d);
				TichHaiPhanSo(a, b, c, d);
				break;
			}
			case 0:
				exit(0);
		}

	} 
	system("pause");
}