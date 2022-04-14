#include<iostream>
#include<time.h>
using namespace std;

int Tinh_F(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	else if (n == 2)
		return 5;
	else
		return Tinh_F(n - 2) + Tinh_F(n - 3) * Tinh_F(n - 1);
}

int Tinh_F_KodeQuy(int n) {
	int F0 = 1, F1 = 2, F2 = 5, Fn = 0;
	for (int i = 3; i <= n; i++) {
		Fn = F1 + F0 * F2;
		F0 = F1;
		F1 = F2;
		F2 = Fn;

	}
	return Fn;
}


int main() {
	cout << Tinh_F(6) << endl;
	cout << Tinh_F_KodeQuy(6)<<endl;

	clock_t start, end;
	double time_use;

	start = clock();
	Tinh_F(30);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian chay F(n): " << time_use<<endl;
	

	start = clock();
	Tinh_F_KodeQuy(30);
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian chay F_KodeQuy(n): " << time_use<<endl;
}
