//tổng phần tử trong mảng
#include<iostream>
using namespace std;

int SumArr(int a[1000], int n) {
	if (n == 1) return a[0];
	return a[n - 1] + SumArr(a, n - 1);
}
int main()
{
	int a[1000];
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int Sum = SumArr(a, n);
	cout << Sum;
}
