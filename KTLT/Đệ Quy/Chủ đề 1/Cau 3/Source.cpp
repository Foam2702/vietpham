#include<iostream>
using namespace std;

int FindMax(int* a,int n)
{
	if (n == 0)
		return a[0];
	else
	{
		if (a[n] > FindMax(a, n - 1))
		{
			return a[n];
		}
		return FindMax(a, n - 1);
	}
	
}

int main()
{
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << FindMax(arr, n);
}