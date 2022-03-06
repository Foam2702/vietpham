#include"Header.h"

void Input(double a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}
double FindMax(double a[], int n)
{
	double max = a[0];

	for (int i = 0; i < n; i++)
	{
		if ((max < a[i]))
		{
			max = a[i];

		}

	}
	return max;

}

void lietKe_Max(double a[], int n)
{
	double max = FindMax(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max)
			cout << i << " ";
	}
	cout << endl;
}