#include<iostream>
using namespace std;

int Xn( int n) {
	int ret = 0;
	if (n == 0) {
		return ret = 1;
	}
	else {
		ret = 0;
		for (int i = 0; i < n; i++) {
			ret += ((n - i) * (n - i) * Xn(i));
		}
	}
	return ret;
}
int main() {
	int n; cin >> n;
	int ans = 0;
	ans = Xn(n);
	cout << ans;
}