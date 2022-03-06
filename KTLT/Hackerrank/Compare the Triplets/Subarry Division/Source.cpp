#include<iostream>
#include<vector>
using namespace std;

int birthday(vector<int> s, int d, int m) {
	
	int count=0;
	for (int i = 0; i < s.size(); i++)
	{	
		int sum = 0;
		int k = i;
		
		for (int j = 0; j < m; j++)
		{
			sum += s[k];
			k++;
			if (k > s.size())
				break;
		}
		if (sum == d)
		{
			count++;
		}
		
		
	}
	return count;
}
int main()
{	
	vector<int>s;
	int n; cin >> n;
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		s.push_back(data);
	}
	int d, m;
	cin >> d >> m;
	int value = birthday(s, d, m);
	cout << value;
	return 0;
}