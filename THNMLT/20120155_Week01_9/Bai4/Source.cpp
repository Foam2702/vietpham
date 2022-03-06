#include<iostream>
using namespace std;

int main()
{
	double chieudai, chieurong, chuvi;
	do
	{
		cout << "Nhap chu vi:"; cin >> chuvi;
		if (chuvi <= 0)
		{
			cout << "Chu vi hinh chu nhat phai lon hon 0";
		}

	} while (chuvi <= 0);
	// chuvi= (dai+rong)*2=(1.5*rong+rong)*2=2.5*rong*2=5*rong
	chieurong = chuvi / 5;
	chieudai = 1.5 * chieurong;
	cout << "Dien tich HCN:" << chieudai * chieurong  ;

	
}