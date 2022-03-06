#include<iostream>
#include<algorithm>
using namespace std;

int recursiveBinarySearch(int* a, int left, int right, int key)
{
	if (left == right)
	{
		if (a[left] == key)
			return left;
		else
			return 0;
	}
	else {
		int mid = (right + left) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
			return recursiveBinarySearch(a, left, mid - 1, key);
		else
			return recursiveBinarySearch(a, mid + 1, right, key);
	}
}
int main()
{
	int n, key, index;
	int* a;
	cout << "Nhap so phan tu mang:"; cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	cout << "Mang sau khi sap xep:";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Nhap phan tu can tim kiem:"; cin >> key;
	index = recursiveBinarySearch(a, 0, n - 1, key);
	cout << "Tai vi tri:"<<index;
	delete[]a;

}