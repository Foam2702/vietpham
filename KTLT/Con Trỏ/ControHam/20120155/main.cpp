#include"Header.h"
int main()
{	
	PS PS1, PS2;
	cin >> PS1;
	cin >> PS2;
	int luachon;
	system("cls");
	while (true) {
		cout << "Phan so :"<<PS1 << endl;
		cout <<"Phan so:"<< PS2 << endl;
		cout << " MENU" << endl;
		cout << "1 => Cong 2 phan so" << endl;
		cout << "2 => Tru 2 pha so" << endl;
		cout << "3 => Nhan 2 phan so" << endl;
		cout << "4 => Chia 2 phan so" << endl;
		cout << "0 => Thoat"<<endl;
		cout << "Vui long nhap lua chon :";
		cin >> luachon;
		if (luachon == 1) {
			XuLyMenu(SumFraction, PS1, PS2);
			system("pause");
		}
		else if (luachon == 2) {
			XuLyMenu(MinusFraction, PS1, PS2);
			system("pause");
		}
		else if (luachon == 3) {
			XuLyMenu(MutiplyFraction, PS1, PS2);
			system("pause");
		}
		else if (luachon == 4) {
			XuLyMenu(DivideFraction, PS1, PS2);
			system("pause");
		}
		else break;
	}
	return 0;
}