#include<iostream>
using namespace std;

bool checkPrime(int n)
{
	if (n < 2)
		return false;
	int i = 2;
	while(i<=sqrt(n))
	{
			if (n % i == 0)
			{
				return false;
				break;
			}
			i++;
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
