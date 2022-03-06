#include<iostream>
using namespace std;

void ComparetheTriplets()
{
	int n; cin >> n;
	int a[10]; int b[10];
	int score1 = 0, score2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > b[i]) score1++;
		else if (a[i] < b[i]) score2++;
		
		
	}
	cout << score1 << " " << score2;
}
int main()
{
	ComparetheTriplets();
}