#include<iostream>
using namespace std;

int main()
{
	int n,temp;
	bool check;
	do {
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai la so nguyen duong" << endl;
		}
	} while (n <= 0);
	temp = n;
	while (temp != 0)
	{	
		int value = temp % 10;
		if (value % 2 == 0)
		{
			check = true;
		}
		else 
		{
			check = false;
			break;
		}
		temp /= 10;
	}
	if (check == true)
	{
		cout << n << " toan bo la chu so chan";
	}
	else
	{
		cout << n << " khong phai toan bo la so chan";
	}
}