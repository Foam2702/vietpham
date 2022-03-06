#include<iostream>
using namespace std;


void Khoihop()
{	
	double chieucao,chieusau,chieurong;
	do
	{
		cout << "Nhap chieu cao:"; cin >> chieucao;
		cout << "Nhap chieu sau:"; cin >> chieusau;
		cout << "Nhap chieu rong:"; cin >> chieurong;
		if (chieucao <= 0 || chieusau <= 0 || chieurong <= 0)
		{
			cout << "chieu cao,chieu sau,chieu rong phai lon hon 0" << endl;
		}
	} while (chieucao <= 0 || chieusau <= 0 || chieurong <= 0);

	cout << "The tich khoi hop :" << chieucao * chieusau * chieurong << endl;
	cout << "Dien tich xung quanh khoi hop :" << 2 * chieucao * (chieurong + chieusau)<<endl;
}
void Khoilapphuong()
{
	double canh;
	do
	{
		cout << "Nhap canh:"; cin >> canh;
		if (canh <= 0)
		{
			cout << "Canh phai lon hon 0"<<endl;
		}

	} while (canh <= 0);
	cout << "The tich khoi lap phuong :" << canh * canh * canh << endl;
	cout << "Dien tich khoi lap phuong:" << 6 * canh * canh << endl;
}
void Khoitrutron()
{
	double R, chieucao;
	const double pi = 3.14;
	do
	{
		cout << "Nhap R:"; cin >> R;
		cout << "Nhap chieu cao:"; cin >> chieucao;
		if (R <= 0 || chieucao <= 0)
		{
			cout << "R va chieu cao phai lon hon 0" << endl;
		}
	} while (R <= 0 || chieucao <= 0);
	cout << "The tich khoi tru tron:" << pi * R * R * chieucao << endl;
	cout << "Dien tich khoi tru tron:" << 2 * pi * R * (R + chieucao)<<endl;

}
int main()
{
	int choose = 0;
	
	while (true)
	{
		cout << "Nhap 1 : Dien tich va The tich khoi hop" << endl;
		cout << "Nhap 2 : Dien tich va The tich khoi lap phuong" << endl;
		cout << "Nhap 3 : Dien tich va The tich khoi tru tron " << endl;
		cout << "Nhap 0 :Thoat"<<endl;
		cout << "Nhap lua chon:";
		cin >> choose;
		if (choose == 1)
		{
			Khoihop();
		}
		else if (choose == 2)
		{
			Khoilapphuong();
		}
		else if (choose == 3)
		{
			Khoitrutron();
		}
		else if (choose == 0)
		{
			break;
		}
	}
	
}