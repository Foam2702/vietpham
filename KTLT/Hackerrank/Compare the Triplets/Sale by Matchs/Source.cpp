#include<iostream>
#include<vector>
using namespace std;

int sockMerchant(int n, vector<int> &ar) {
	int value;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		ar.push_back(value);
	}
	int count = 1;
	int sum = 0;
	int loca = 0;
	vector<int> check;
	for (int i = 0; i < ar.size()-1; i++)
	{
		for (int j = i+1; j < ar.size(); j++)
		{
			if (ar[i] > ar[j])
				swap(ar[i], ar[j]);
		}
	}
	for (int i = 0; i < ar.size() - 1; i+=loca)
	{	
		for (int j = i + 1; j < ar.size(); j++)
		{
			if (ar[i] == ar[j])
			{
				count++;
				
			}
			
			
		}
		if (count > 2 && count % 2 != 0)
		{
			count = count - 1;
			sum += count / 2;
			loca = count;
			count = 1;
		}
		else if (count >= 2 && count % 2 == 0)
		{
			sum += count / 2;
			loca = count;
			count = 1;
		}
		else
		{	
			loca = count;
			count = 1;
		}
		
	}
	return sum;
}
int main()
{
	int n; cin >> n;
	vector<int>arr;
	int sum=sockMerchant(n, arr);
	cout << sum;
}
