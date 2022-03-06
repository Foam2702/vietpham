#include<iostream>
using namespace std;
//tổng các số lẻ
int Sum(int n) {
	if (n == 1)
		return 1;
	if (n % 2 == 0) {
		return Sum(n - 1);
	}
	else return n + Sum(n - 2);
	
}

int main()
{
	int n;
	cin >> n;
	cout << Sum(n);
	
}
