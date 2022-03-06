#include<iostream>
using namespace std;

int main()
{
	double R;
	const double pi = 3.14;
	do 
	{
		cout << "Nhap R:"; cin >> R;
		if (R <= 0)
		{
			cout << "R phai lon hon 0"<<endl;
			
		}
	} while (R <= 0);
	cout <<"Chu vi hinh tron:"<< 2 * pi * R << endl;
	cout << "Dien tich hinh tron:" << pi * R * R << endl;
}