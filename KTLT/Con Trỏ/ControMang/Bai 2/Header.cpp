#include"Header.h"


int* CreateArr(int& n) {
	cout << "Khoi tao mang voi so phan tu :";
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
		cout << "a[" << i << "]:" << a[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << "Dia chi a[" << i << "]:" << &a[i] << endl;
	}
}
void FindMinMax(int* a, int n) {
	int luachon;
	cout << "Nhap 1 :tim Max     Nhap 2:tim Min"<<endl;
	cout << "Nhap lua chon : ";
	cin >> luachon;
	if (luachon == 1) {
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (max < a[i]) max = a[i];
		}
		cout << max;
	}
	else if (luachon == 2) {
		int min = 0;
		for (int i = 0; i < n; i++) {
			if (min > a[i]) min = a[i];
		}
		cout << min;
	}
}