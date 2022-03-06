#include"Header.h"
using namespace std;



void InputFraction(PS& ps)
{
	cout << "Nhap tu so :"; cin >> ps.tu;
	do
	{
		cout << "Nhap mau so:"; cin >> ps.mau;
		if (ps.mau == 0)
		{
			cout << "Mau so phai khac 0";
		}
	} while (ps.mau == 0);
}
void OutputFraction(PS ps)
{
	cout << ps.tu << "/" << ps.mau<<endl;
}
PS SumFraction(PS ps1, PS ps2) {
	PS iX;
	iX.tu = (ps1.tu * ps2.mau) + (ps2.tu * ps1.mau);
	iX.mau = ps1.mau * ps2.mau;
	return iX;

}
PS MinusFraction(PS ps1, PS ps2)
{
	PS iX;
	iX.tu = (ps1.tu * ps2.mau) - (ps2.tu * ps1.mau);
	iX.mau = ps1.mau * ps2.mau;
	return iX;
}
PS MutipliYFraction(PS ps1, PS ps2)
{
	PS iX;
	iX.tu = ps1.tu * ps2.tu;
	iX.mau = ps2.mau * ps2.mau;
	return iX;
}

PS DivideFraction(PS ps1, PS ps2)
{
	PS iX;
	iX.tu = ps1.tu * ps2.mau;
	iX.mau = ps1.mau * ps2.tu;
	return iX;
}

int UCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
PS rutgon(PS ps)
{	
	PS newps;
	int c = UCLN(ps.tu, ps.mau);
	ps.tu = ps.tu / c;
	ps.mau = ps.mau / c;
	newps = ps;
	return newps;
}
int Sosanh_PS(PS PS1,PS PS2)
{
	rutgon(PS1);
	rutgon(PS2);
	double c = PS1.tu / PS1.mau;
	double d = PS2.tu / PS2.mau;
	if (c > d)
		return 1;
	else if (c == d)
		return 0;
	else
		return -1;
}

void Sort_Increasing(PS arr[],int n) {

	for (int i = 0; i < n- 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (((double)(arr[i].tu) / (double)(arr[i].mau)) > (((double)arr[j].tu) / ((double)arr[j].mau))) {
				swap(arr[i], arr[j]);

			}
		}
	}
}
void InputFraction_Arr(PS arr[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		InputFraction(arr[i]);
	}
}
void OutputFraction_Arr(PS arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		OutputFraction(arr[i]);
		
	}
	cout << endl;
}
PS ArrSum_Fraction(PS arr[], int n)
{
	PS sum;
	sum = arr[0];
	for (int i = 1; i < n; i++)
	{
		sum=SumFraction(sum, arr[i]);
	}
	rutgon(sum);
	return sum;
}
void thaiYThe_mangToigian(PS arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rutgon(arr[i]);
	}
	OutputFraction_Arr(arr, n);
}
int Tim_phanSo(PS arr[], int n, PS k)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (k.tu == arr[i].tu && k.mau == arr[i].mau)
			return 1;
	}
	return 0;
}
