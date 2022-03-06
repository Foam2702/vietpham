#include<iostream>
using namespace std;

int demSoAm(double k)
{
	int dem = 0;
	do 
	{
		cout << "Nhap gia tri:";
		cin >> k;
		if (k == 0)
		{
			break;
		}
		if (k < 0)
		{
			dem++;
		}
	} while (k != 0);

	return dem;
}

int main()
{
	double k=0;
	cout << "So thuc am :" << demSoAm(k);
	system("pause");
}