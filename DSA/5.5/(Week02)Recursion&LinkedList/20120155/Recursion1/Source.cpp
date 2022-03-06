#include<iostream>
using namespace std;

int Sum(int n)
{
	if (n == 1)
		return 1;
	else
		return n + Sum(n - 1);

}

int main()
{
	int n;
	do {
		cout << "Nhap n:";
		cin >> n;
		if (n <= 0)
			cout << "n phai la so nguyen duong"<<endl;
		else {
			int sum = Sum(n);
			cout << sum;
		}
		
	} while (n <= 0);

}