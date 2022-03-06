#include<iostream>
using namespace std;

void Tong(float& a, float& b)
{
	cout << a + b;

}
void Hieu(float& a, float& b)
{
	cout << a - b;
}

void Nhap(float& a, float& b)
{
	cout << "Nhap a:";
	cin >> a;
	cout << "Nhap b:";
	cin >> b;
}

void Lua_Chon(float& a, float& b)
{
	int t;
	char temp;
	system("cls");
	while (true)
	{
		cout << "MENU" << endl;
		cout << "Nhap 1=> Bai 1" << endl;
		cout << "Nhap 2=> Bai 2" << endl;
		cout << "Nhap 3=> Thoat" << endl;
		cout << "Nhap lua chon :";
		cin >> t;
		if (t == 1) {
			Nhap(a, b);
			Tong(a, b);
		}
		else if (t == 2) {
			Nhap(a, b);
			Hieu(a, b);
		}
		else if (t == 3) {

			cout << "Ban co thuc su muon thoat ";
			cout << "Co :Y   Khong: N or press any keys ";
			cin >> temp;
			if (temp =='Y') break;

		}
		else break;

	}
}



int main()
{

	float a, b;
	Lua_Chon(a, b);
	system("pause");
	return 0;
}


