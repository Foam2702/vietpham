#include<iostream>
#include<cmath>
using namespace std;

int* CreateArr(int& n) {
	int* a = new int[n];
	return a;
}
void InputArr(int* a, int& n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void FindApproximately(int* a, int* b,int *c, int n, int value) {
	cout << "Nhap phan tu cang tim :"; cin >> value;
	int compare = value - a[0];
	int count = 0;
	int i = 1;
	int j = 0;
	do {
		int temp = abs(value - a[i]);
		if (temp <= compare) {
			compare = abs(value - a[i]);
			b[j] = a[i];
			count++;
			j++;
		}
		i++;
	} while (i <n);
	int k = 0,max=b[0],temp=0;
	for (int j = 0; j < count-1; j++) {
		for (int g = j + 1; g < count; g++) {
			if (b[g] > max) max = b[g];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			c[k] = i;
			k++;
			temp++;
		}
	}

	for (int k = 0; k < temp; k++) {
		cout << c[k] << " ";
	}
}

int main()
{	
	int n,value=0;
	cout << "Nhap so luong phan tu: "; cin >> n;
	int* a = CreateArr(n);
	int* b = CreateArr(n);
	int* c = CreateArr(n);
	InputArr(a, n);
	FindApproximately(a, b,c, n, value);
	delete[]a;
	delete[]b;
	delete[]c;
	system("pause");
	return 0;
}