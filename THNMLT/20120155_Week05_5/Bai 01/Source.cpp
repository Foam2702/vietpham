#include"Header.h"

void Input(float& a, float& b)
{
	cout << "Nhap a: ";
	cin >> a;
	cout << "Nhap b: ";
	cin >> b;
}

void Input1(float& a, int& x)
{
	do
	{
		cout << "Nhap a: ";
		cin >> a;
		cout << "Nhap x: ";
		cin >> x;
		if (x < 0)
			cout << "Khong phu hop, xin nhap lai" << endl;
	} while (x < 0);
}


float Tong(float a, float b)
{
	return a + b;
}

float Hieu(float a, float b)
{
	return a - b;
}

float Tich(float a, float b)
{
	return a * b;
}

float Thuong(float a, float b)
{
	return a / b;
}

float LuyThua(float a, int x)
{
	float temp = 1;
	for (int i = 1; i <= x; i++)
	{
		temp *= a;
	}
	return temp;
}

float CanBac(float a, int x)
{
	float temp = pow(a, 1.0 / x);
	return temp;
}

void Output(float x)
{
	cout << "Ket qua: " << setprecision(2) << fixed << x << endl;
}