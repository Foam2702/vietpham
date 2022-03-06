#include"Header.h"

void Input(double a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]:";
		cin >> a[i];
	}
}

double FindMin(double a[], int n)
{	
	int check = 0;
	double min;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			min = a[i];
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			if (a[i] < min)
			{
				min = a[i];
			}
			check++;
		}
		
	}
	if (check != 0)
	{
		return min;
	}
	return -1;

}

