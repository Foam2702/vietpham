#include"Header.h"

int main()
{
	float a, b;
	int choose, x;
	while(true)
	{
		cout << "////////////////MENU////////////////" << endl;
		cout << "1:Cong 2 so thuc" << endl;
		cout << "2:Tru 2 so thuc" << endl;
		cout << "3.Nhan 2 so thuc" << endl;
		cout << "4:Chia 2 so thuc" << endl;
		cout << "5:Tinh a^x" << endl;
		cout << "6:Tinh can bac x cua a" << endl;
		cout << "0:Ket thuc chuong trinh" << endl;
		cout << "/////////////////////////////////////" << endl;
			cout << "Nhap bai muon chon: ";
			cin >> choose;
			switch (choose)
			{
				case 1:
				{	Input(a, b);
					Output(Tong(a, b)); 
					break;
				}
				case 2:
				{	Input(a, b);
					Output(Hieu(a, b)); 
					break;
				}
				case 3:
				{	Input(a, b);
					Output(Tich(a, b));
					break;
				}
				case 4:
				{	Input(a, b);
					Output(Thuong(a, b)); 
					break;
				}
				case 5:
				{	Input1(a, x);
					Output(LuyThua(a, x)); 
					break;
				}
				case 6:
				{	Input1(a, x);
					Output(CanBac(a, x)); 
					break;
				}
				case 0:
					exit(0);
			}
	} 
	system("pause");
}