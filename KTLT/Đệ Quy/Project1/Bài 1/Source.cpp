#include"Header.h"

void InputArr(int a[], int& n,int i) {
	if (i == n) return;
	cout << "a[" << i << "]";
	cin >> a[i];
	InputArr(a, n, i + 1);

}
void OutputArr(int a[], int n, int i) {
	if (i == n) return;
	cout << a[i] << endl;
	OutputArr(a, n, i + 1);
}