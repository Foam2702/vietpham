#include<iostream>
using namespace std;


bool checkPrime(int x)
{
	if (x < 2)
		return false;
	else
	{	
		int i = 2;
		while (i <= sqrt(x))
		{
			if (x % i == 0)
			{
				return false;
				break;
			}
			i++;
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

	for (int i = 2; i < n; i++)
	{
		if (checkPrime(i))
			cout << i << " ";
	}

	system("pause");
}