#include<iostream>
using namespace std;

int main()
{
	const float pi = 3.14;
	int R = 0;
	float Chuvi = 0 , Dientich = 0;
	cout << "Nhap ban kinh R:";
	do {
		cin >> R;
		if (R <= 0)
		{
			cout << "Nhap lai (R > 0):";
		}
	} while (R <= 0);
	Chuvi = 2 * pi * R;
	Dientich = pi * R * R;
	cout << "Chu vi duong tron:" << Chuvi << endl;
	cout << "Dien tich duong tron:" << Dientich;
}