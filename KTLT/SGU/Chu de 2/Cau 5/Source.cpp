#include<iostream>
using namespace std;

void DeleteAtPos(int* arr, int& n)
{
	int pos;
	do {
		cout << "Nhap vi tri can xoa (0 -> " << n - 1 << "):";
		cin >> pos;
	} while (pos < 0 || pos >= n);


	for (int i = pos; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	n--;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	delete[]arr;
}
int main()
{
	int n;
	cout << "Nhap so luong phan tu:"; cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cout << "[" << i << "]:";
		cin >> arr[i];
	}
	DeleteAtPos(arr, n);



}