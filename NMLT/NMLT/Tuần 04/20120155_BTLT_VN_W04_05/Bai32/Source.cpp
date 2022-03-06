#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	bool check = false;
	do {
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai la so nguyen duong" << endl;
		}
	} while (n <= 0);
	for (int i = 1; i < n; i++)
	{
		if (i*i== n)
		{	
			check = true;
			break;
		}
		
	}
	if (check == true)
	{
		cout << n << " la so chinh phuong";
	}
	else
	{
		cout << n << " khong la so chinh phuong";
	}
}
