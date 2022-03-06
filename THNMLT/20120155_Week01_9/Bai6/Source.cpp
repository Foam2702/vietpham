#include<iostream>
using namespace std;

int main()
{
	double chieudai, R,tamgiac,hinhtron;
	const double pi = 3.14;
	do
	{
		cout << "Nhap chieu dai tam giac deu:"; cin >> chieudai;
		cout << "Nhap ban kinh hinh tron:"; cin >> R;
		if (chieudai <= 0 || R <= 0)
		{
			cout << "Chieu dai tam giac deu va ban kinh hinh tron phai lon hon 0" << endl;
		}
	} while (chieudai <= 0 || R <= 0);
	tamgiac = chieudai * chieudai * (sqrt(3) / 4);
	hinhtron = pi * R * R;
	cout << "Dien tich cua phan duoc to xam:" << (double)3 * tamgiac + hinhtron / 2;

}