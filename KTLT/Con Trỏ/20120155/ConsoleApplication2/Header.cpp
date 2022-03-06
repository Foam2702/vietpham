#include"Header.h"

int** CreateArr(int& n, int& m) {
	cout << "Nhap so dong :"; cin >> n;
	cout << "Nhap so cot :"; cin >> m;
	int** a = new int* [n];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	}
	return a;
}
void InputArr(int** a, int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
}
void OutputArr(int** a, int n,int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void FreeArr(int** a, int n) {
	for (int i = 0; i < n; i++)
		delete[] a[i];
	delete[]a;
}

