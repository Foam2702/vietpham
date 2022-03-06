#include<iostream>
using namespace std;

bool SNT(int n)
{
	if (n < 2)
		return false;
	else if (n >= 2)
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0) {
				return false;
				break;
			}

		}
	}
	return true;

}

int CountPrime(int* a, int n)
{
	if (n < 1)
		return 0;
	if (SNT(a[n-1]) == true)
	{	
		return 1+ CountPrime(a, n - 1);
	}
	else
	{
		return CountPrime(a, n - 1);
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
	cout << CountPrime(arr, n);
}

