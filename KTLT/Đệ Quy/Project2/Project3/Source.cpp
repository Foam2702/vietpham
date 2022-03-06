#include<iostream>
using namespace std;
//giai thừa
unsigned long long GiaiThua(int n) {
	if (n == 0 || n == 1) return 1;
	else {
		return n * GiaiThua(n - 1);
	}
}
int main()
{
	int n;
	cin >>n;
	cout<<GiaiThua(n);
}