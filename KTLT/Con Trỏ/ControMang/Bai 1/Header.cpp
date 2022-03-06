#include"Header.h"

int*CreateArr(int &n){
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
		cout << "a[" << i << "]:" << a[i]<<endl;
	}
	for (int i = 0; i < n; i++) {
		cout << "Dia chi a[" << i << "]:" << &a[i] << endl;
	}
}