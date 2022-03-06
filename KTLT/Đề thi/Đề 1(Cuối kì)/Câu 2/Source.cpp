#include<iostream>
using namespace std;

int GiaiThua(int n) {
	int GT = 1;
	for (int i = 1; i <= n; i++) {
		GT *= i;
	}
	return GT;
}
double LuyThua(double a, int b) {
	double LT = 1;
	while (b > 0) {
		LT *= a;
		b--;
	}
	return LT;
}
double Tinh_ham_F1(double x, int n) {
	if (n == 0) {
		return 0 ;
	}
	else if (n == 1) {
		return x;
	}
	else {
		int res = 1;
		for (int i = 1; i <= n; i++) {
			res *= i;
		}
		return (pow(x, n) / res) + Tinh_ham_F1(x, n - 1);
	}
}
double Tinh_ham_F2(double x, int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return x;
	}
	else {
		
		return (pow(x, n) / GiaiThua(n))+ (pow(x,n-1)/GiaiThua(n-1)) + Tinh_ham_F2(x, n - 2);
	}
}
double Tinh_ham_F_KoDeQuy(double x, int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (LuyThua(x, i) / GiaiThua(i));
	}
	return sum;
}

int main()
{
	int  n = 0;
	double x=0, ans = 0;
	cout << "Nhap x:"; cin >> x;
	cout << "Nhap n:"; cin >> n;
	ans=Tinh_ham_F_KoDeQuy(x, n);
	cout << ans;
	
	system("pause");
}