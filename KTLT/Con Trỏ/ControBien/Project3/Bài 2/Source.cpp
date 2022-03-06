#include<iostream>
using namespace std;

int* CreateArr(int& n) {
	cout << "Nhap so luong phan tu :"; cin >> n;
	int* a = new int[n];
	return a;
}
void InputArr(int* a, int &n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void FindSolution(int* a, int n,int value) {
	cout << "Nhap phan tu muon tim :"; cin >>value;
	for (int i = 0; i < n; i++) {
		if (a[i] == value) {
			cout << i<<" ";
		}
	}
}

int main()
{
	int n = 0;
	int value = 0;
	int* a=CreateArr(n);
	InputArr(a, n);
	FindSolution(a, n, value);
	delete[]a;
	return 0;
}