#include<iostream>
using namespace std;

int main()
{
	int bienso = 0, div = 0, sum = 0, count = 0;
	cout << "Nhap bien so:";
	do {
		cin >> bienso;
		for (int j = bienso; j != 0; j /= 10)
		{
			j % 10;
			count++;

		}
		if (count < 5) {
			cout << "Nhap lai:";
			count = 0;
		}
	} while (count < 5);
	for (int i = bienso; i != 0; i /= 10)
	{
		sum += i % 10;
		
	}
	div = sum % 10;
	cout << "So nut:" << div;
	
}