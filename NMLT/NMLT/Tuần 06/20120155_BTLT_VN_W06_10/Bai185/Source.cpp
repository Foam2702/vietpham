#include"Header.h"

void Input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}

bool check_soChinhphuong(int x)
{
	double sqrtx = sqrt(x);
	if (sqrtx * sqrtx == x)
	{
		return true;
	}
	return false;
}

void lietKe_soChinhphuong(int a[], int n)
{
	bool check = false;
	cout << "Vi tri:";
	for (int i = 0; i < n; i++)
	{
		if (check_soChinhphuong(a[i]))
		{
			check = true;
			cout << i << " ";
		}

	}
	if (check == false)
		cout << "Khong co so chinh phuong trong mang";
	cout << endl;
}