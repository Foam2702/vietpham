#include<iostream>
#include<vector>
using namespace std;

void miniMaxSum(vector<long long> arr)
{
	int n = 5;
	long long ele;
	
	vector<long long>arrofsum;
	for (int i = 0; i < n; i++)
	{
		cin >> ele;
		arr.push_back(ele);
	}
	
	for (int i = 0; i < arr.size(); i++)
	{	
		long long value = 0;
		for (int j = 0; j < arr.size(); j++)
		{
			if (j != i)
			{
				value += arr[j];
			}
			
		}
		arrofsum.push_back(value);
	}
	
	
	for (int i = 0; i < arrofsum.size() - 1; i++)
	{
		for (int j = i + 1; j < arrofsum.size(); j++)
		{
			if (arrofsum[i] > arrofsum[j])
				swap(arrofsum[i], arrofsum[j]);
		}

	}
	long long min = arrofsum[arrofsum.size() - 1];
	long long max = arrofsum[0];
	

	cout << max << " " << min;
}
int main()
{	
	vector<long long>arr;
	miniMaxSum(arr);
	return 0;
}