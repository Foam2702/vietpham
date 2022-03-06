#include<iostream>
#include<vector>
using namespace std;

vector<int> breakingRecords(vector<int> scores) {
	int n; cin >> n;
	int data;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		scores.push_back(data);
	}
	int max = scores[0],min = scores[0];
	int countmax = 0, countmin = 0;
	for (int i = 0; i < scores.size(); i++)
	{
		if (scores[i] > max)
		{
			max = scores[i];
			countmax++;
		}
		if (scores[i] < min)
		{
			min = scores[i];
			countmin++;
		}
	}
	vector<int>breaking;
	breaking.push_back(countmax);
	breaking.push_back(countmin);
	return breaking;
}

int main()
{
	vector<int>scores;
	vector<int>breaking = breakingRecords(scores);
	for (int i = 0; i < breaking.size(); i++)
	{
		cout << breaking[i] << " ";
	}
	return 0;
}