#include<iostream>
using namespace std;


void InsertionSort(int arr[], int n) {
	int pos, x;
	for (int i = 1; i < n; i++) {
		x = arr[i], pos = i - 1;
		while (pos >= 0 && arr[pos] > x) {
			arr[pos + 1] = arr[pos]; 
			pos--;
		}
		arr[pos + 1] = x;
	}
}
void ExportArr(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main() {
	int arr[] = { 12,2,8,5,1,6,4,15 }, n;
	n = sizeof(arr) / sizeof(arr[0]);
	ExportArr(arr, n);
	InsertionSort(arr, n);
	ExportArr(arr, n);
}