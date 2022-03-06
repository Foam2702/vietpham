#include<iostream>
#include<vector>
using namespace std;

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) 
{
	int  m, n,data ;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{	
		cin >> data;
		apples.push_back(data);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		oranges.push_back(data);
	}
	int countapple = 0, countorange = 0;
	for (int i = 0; i < apples.size(); i++)
	{	
		int compareapple = a + apples[i];
		if (compareapple >= s && compareapple <= t)
		{
			countapple++;
		}
	}
	for (int i = 0; i < oranges.size(); i++)
	{
		int compareorange = b + oranges[i];
		if (compareorange >= s && compareorange <= t)
		{
			countorange++;
		}
	}
	cout << countapple << endl << countorange;
}

int main()
{
	int s, t, a, b;
	cin >> s >> t >> a >> b;
	vector<int>apples;
	vector<int>oranges;
	countApplesAndOranges(s, t, a, b, apples, oranges);
	return 0;
}