#include<iostream>
using namespace std;

int main()
{
	double dientich;
	const double pi = 3.14;
	do
	{
		cout << "Nhap dien tich hinh tron:"; cin >> dientich;
		if (dientich <= 0)
		{
			cout << "Dien tich phai lon hon 0" << endl;
		}
	} while (dientich <= 0);
	cout << "Ban kinh hinh tron : " << sqrt(dientich/ pi);
}
