#include"Header.h"



void Insert(double a[],int &n)
{	
	do
	{
		cout << "Nhap so luong phan tu:"; cin >> n;
		if (n <= 0)
		{
			cout << "So luong phan tu phai lon hon 0" << endl;
		}
	} while (n <= 0);

	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu: ";
		cin >> a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				double temp = a[i];
				for (int k = i; k > j; k--)
				{
					a[k] = a[k - 1];

				}
				a[j] = temp;
				break;
			}	
		}		
	}
}

void Output(double a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	}
	cout << endl;
}