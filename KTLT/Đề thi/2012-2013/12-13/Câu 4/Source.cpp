#include<iostream>
using namespace std;

void Sort(float a[], int n)
{
	if (n ==0||n==1)
	{
		return;
	}
	else
	{
		Sort(a, n - 1);
		if (a[n-1] < a[ n - 2 ])
			swap(a[ n - 1 ], a[n - 2]);
		return Sort(a, n - 1);
	}
	
}

int main()
{
	float a[] = { 5,4,3,2 };
	int n = sizeof(a) / sizeof(a[0]);
	Sort(a, n);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}