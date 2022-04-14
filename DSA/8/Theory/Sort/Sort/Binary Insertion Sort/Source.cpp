#include<iostream>
using namespace std;

void BInserttionSort(int arr[], int n) {
	int right, left, mid, x;
	for (int i = 1; i < n; i++) {
		x = arr[i], left = 0, right = i - 1;
		while (left <= right) {
			mid = (right + left) / 2;
			if (x < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		for (int j = i - 1; j >= left; j--) {
			arr[j + 1] = arr[j];
		}
		arr[left] = x;
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
	BInserttionSort(arr, n);
	ExportArr(arr, n);
}