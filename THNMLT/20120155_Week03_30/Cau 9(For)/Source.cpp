#include<iostream>
using namespace std;

bool checkPrime(int n)
{
	if (n < 2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
				break;
			}
		}
	}
	return true;
}

int main()
{
	int n;
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n < 1)
		{
			cout << "Nhap lai(n>=1)" << endl;
		}
	} while (n < 1);

	if (checkPrime(n))
		cout << "La so nguyen to";
	else
		cout << "Khong la so nguyen to";

	system("pause");
}
