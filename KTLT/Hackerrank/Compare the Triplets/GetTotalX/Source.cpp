#include<iostream>
#include<vector>
using namespace std;

int getTotalX(vector<int> &a, vector<int> &b) 
{
	int n, m,data;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		a.push_back(data);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> data;
		b.push_back(data);
	}	
	int countn = 0, countm = 0,total=0;
	for (int i = a[0]; i <= b[m-1]; i++)
	{	
		for (int j = 0; j < a.size(); j++)
		{
			if (i % a[j] == 0)
			{
				countn++;
			}
			
		}
		for (int k = 0; k < b.size(); k++)
		{
			if (b[k] % i == 0)
			{
				countm++;
			}
		}
		if (countn == n && countm == m)
		{
			total++;
		}
		countn = 0, countm = 0;
		
	}
	return total;
}
int main()
{
	vector<int>a;
	vector<int>b;
	int value=getTotalX(a, b);
	cout << value;
	return 0;
}