#include<iostream>
#include<vector>
using namespace std;

long aVeryBigSum(vector<long> ar) {
	int n; cin >> n;
	int value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		ar.push_back(value);
	}

	long sum = 0;
	for (int i = 0; i < ar.size(); i++)
	{
		sum += ar[i];
	}
	return sum;
}

int main()
{
	vector<long>arr;
	long sum= aVeryBigSum(arr);
	cout << sum;
	
}