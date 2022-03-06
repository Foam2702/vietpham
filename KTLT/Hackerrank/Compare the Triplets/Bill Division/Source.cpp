#include<iostream>
#include<vector>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b) 
{	
	int sum = 0;
	for (int i = 0; i < bill.size(); i++)
	{
		if (i != k)
		{
			sum += bill[i];
		}
	}
	sum = sum / 2;
	if (sum == b)
	{
		cout << "bon Appetit";
	}
	else if (sum < b)
	{
		cout << b - sum;
	}

}


int main()
{
	int n; cin >> n;
	int k; cin >> k;
	int value;
	vector<int>bill;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		bill.push_back(value);

	}
	int b; cin >> b;
	bonAppetit(bill, k, b);
}