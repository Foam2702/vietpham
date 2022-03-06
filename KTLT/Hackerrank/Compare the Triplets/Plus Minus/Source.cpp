#include<iostream>
#include<vector>
using namespace std;

void plusMinus(vector<int> arr) {
	int n; cin >> n;
	int value, temp1 = 0,temp2=0,temp3=0;
	double sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		arr.push_back(value);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0) temp1++;
		else if (arr[i] > 0) temp2++;
		else {
			temp3++;
		}
	}
	sum1 = (double)temp1 / n;
	sum2 = (double)temp2 / n;
	sum3 = (double)temp3 / n;
	cout << sum2 << endl << sum1 << endl << sum3;
}
int main()
{
	vector<int> arr;
	plusMinus(arr);
}

