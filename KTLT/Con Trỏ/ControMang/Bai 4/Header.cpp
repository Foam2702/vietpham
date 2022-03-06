#include"Header.h"

int* CreateArr(int& n){
	cout << "Nhap so luong phan tu :";
	cin >> n;
	int* a = new int[n];
	return a;
}
void InputArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void Increasing(int *a,int n){
	for (int i = 0; i < n - 1;i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i]>a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	cout << "Mang tang dan" << endl;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]:" << a[i] << " ";
	}
	cout << endl;
}

void Decreasing(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j< n; j++) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	cout << "Mang giam dan" << endl;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]:" << a[i] << " ";
	}
}