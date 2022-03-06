#include"Header.h"

int* CreateArr(int& n) {
	cout << "Nhap so phan tu cua mang :";
	cin >> n;
	int* a = new int[n];
	return a;
}
void InputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void OutputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]:" << a[i]<<endl;
	}
}
bool SNT(int x) {
		if (x < 2) return false;
		int j = 2;
		for (; j <= sqrt(x); j++) {
			if (x % j == 0) {
				return false;
			}
		}
	return true;
}
void CountSNT(int* a, int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (SNT(a[i]))  count++;
	}
	cout <<"Mang co so luong SNT :"<< count<<endl;
	for (int i = 0; i < n; i++) {
		if (SNT(a[i])) {
			cout << a[i] << " ";
		}
	}
}
