#include<iostream>
using namespace std;

float findMax(float a[], int n)
{	
	if (n == 0)
	{
		return -1;
	}
	if (n == 1)
	{
		return a[0];
	}
	else 
	{
		if (a[n - 1] > findMax(a, n - 1))
		return a[n - 1];

		else
		return findMax(a, n - 1);
		
	}
	
}

int main()
{
	float a[] = { 5,6,3,7,32,5 };
	int n = sizeof(a) / sizeof(a[0]);
	float value = findMax(a,n);
	cout << value;
	return 0;
}