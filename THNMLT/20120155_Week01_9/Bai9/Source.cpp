#include<iostream>
using namespace std;

int main()
{
	double M, q;
	int n;
	do
	{
		cout << "Nhap so tien gui :"; cin >> M;
		cout << "Nhap so thang gui :"; cin >> n;
		cout << "Nhap lai suat :"; cin >> q;
		if (M <= 0 || n <= 0 || q <= 0)
		{
			cout << "Cac gia tri phai lon hon 0"<<endl;
		}
	} while (M <= 0 || n <= 0 || q <= 0);
	cout << "So tien lai:" << (M * pow((1 + q/100), n))-M;
}