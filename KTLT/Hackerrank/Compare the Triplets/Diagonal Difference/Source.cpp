#include<iostream>
using namespace std;

int main()
{
	int sum1 = 0, sum2 = 0;
	int n; cin >> n;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum1 += arr[i][i];
	}
	int i=0, j=n-1;
	while (i < n)
	{
		sum2 += arr[i][j];
		i++, j--;
	}
	int sum = abs(sum1 - sum2);
	cout << sum;
}