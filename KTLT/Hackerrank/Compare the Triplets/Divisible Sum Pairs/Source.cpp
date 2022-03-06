#include<iostream>
#include<vector>
using namespace std;

int divisibleSumPairs(int n, int k, vector<int> ar) {
	int count = 0;
	for (int i = 0; i < ar.size()-1; i++)
	{
		for (int j = i + 1 ; j <ar.size(); j++)
		{
			if ((ar[i] + ar[j]) % k==0)
			{
				count++;
			}
		}
	}
	return count;
}

int main()
{
	int n; cin >> n;
	int k; cin >> k;
	int value;
	vector<int>arr;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		arr.push_back(value);
	}
	int count=divisibleSumPairs(n, k, arr);
	cout << count;
}