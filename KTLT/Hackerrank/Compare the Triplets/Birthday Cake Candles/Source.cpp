#include<iostream>
#include<vector>
using namespace std;

int birthdayCakeCandles(vector<int> candles) {
	int n; cin >> n;
	int ele;
	int count;
	for (int i = 0; i < n; i++)
	{
		cin >> ele;
		candles.push_back(ele);
	}
	int max = candles[0];
	for (int i = 0; i < candles.size(); i++)
	{
		if (candles[i] > max) max = candles[i];
	}
	for (int i = 0; i < candles.size(); i++)
	{
		if (max == candles[i]) count++;
	}
	return count;
	
}
int main()
{	
	vector<int>candles;
	int count = birthdayCakeCandles(candles);
	cout << count;
}