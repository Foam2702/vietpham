#include"Header.h"

void Input(int a[], int& n)
{
	do
	{
		cout << "Nhap n:"; cin >> n;
		if (n <= 0)
		{
			cout << "n phai lon hon 0" << endl;
		}

	} while (n <= 0);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}
void sapxepgiam(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				swap(a[i], a[j]);
}
void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";

	}
	cout << endl;
}