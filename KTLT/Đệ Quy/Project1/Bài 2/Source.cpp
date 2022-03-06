//lãi suất ngân hàng
#include<iostream>
using namespace std;

double LaiSuat(double value, int n) {
	double temp = 0;
	if (n == 0) return 0;
	else {
		temp = temp + (value * 0.001) + LaiSuat(value, n - 1);
	}
	return temp;
}
int main()
{
	double value;
	int n;
	cin >> value; cin >> n;
	cout << LaiSuat(value, n);
}
