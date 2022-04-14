#include<iostream>
#include<time.h>
using namespace std;

int Fibo(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

long long Fibo_KodeQuy(int n) {
	long long F0 = 0, F1 = 1, Fn = 0;
	for (int i = 2; i <= n; i++) {
		Fn = F0 + F1;
		F0 = F1;
		F1 = Fn;
	}
	return Fn;
}

int main() {
	clock_t start, end;   
	double time_use;

	start = clock();
	cout<<Fibo(50)<<endl;
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC; 
	cout << "Thoi gian chay fibo(n): " << time_use;
	

	start = clock();
	cout << Fibo_KodeQuy(50)<<endl;
	end = clock();
	time_use = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Thoi gian chay Fibo_KodeQuy(n): " << time_use;
	
}