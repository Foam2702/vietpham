#include<iostream>
using namespace std;

int TinhY(int n);
int TinhX(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return TinhX(n - 1) + TinhY(n - 1);
	}
}
int TinhY(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * n * TinhX(n - 1) + TinhY(n - 1);
	}
}
int main() {
	int n = 0,ansX=0,ansY=0;
	cin >> n;
	ansX=TinhX(n);
	ansY = TinhY(n);
	cout << ansX << endl;
	cout << ansY;

}