#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(int arr[],int n) {
	int min = 0;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
			
		}
		swap(arr[min], arr[i]);
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
	SelectionSort(arr, n);
	ExportArr(arr, n);
}