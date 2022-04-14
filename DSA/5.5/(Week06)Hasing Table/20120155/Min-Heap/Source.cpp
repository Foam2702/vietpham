#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void Heapify(vector<int>& arr, int left, int right) {
	int i = left;
	while (2 * i + 1 < right) 
	{
		if (arr[i] > arr[2 * i]) 
		{
			swap(arr[i], arr[2 * i]);
			i /= 2;
		}
		else if (arr[i] > arr[2 * i + 1]) 
		{
			swap(arr[i], arr[2 * i + 1]);
			i = (i - 1) / 2;
		}
		else 
		{
			++i;
		}
	}
	
}
int getMin(vector<int> heap) 
{
	return heap[0];
}
int extractMin(vector<int>& arr) 
{
	int min_arr = arr[0];
	swap(arr[0], arr[arr.size() - 1]);
	arr.pop_back();
	Heapify(arr, 0, arr.size());
	return min_arr;
}
void insert(vector<int>& arr, int x) 
{
	arr.push_back(x);
	Heapify(arr, 0, arr.size());
}
bool is_Heap(vector<int> arr) 
{
	int i = 0;
	while (2 * i + 1 < arr.size()) 
	{
		if (arr[i] > arr[2 * i] || arr[i] > arr[2 * i + 1]) 
		
		{
			return false;
		}
		else 
		{
			++i;
		}
	}
	return true;
}
int main() 
{
	vector<int> a;
	int value;
	cout << "Nhap gia tri :";
	while (cin >> value)
	{
		cout << "Nhap gia tri :";
		if (value == NULL)
		{
			break;
		}
		a.push_back(value);
	}
	Heapify(a, 0, a.size());
	cout << is_Heap(a) << endl;
	cout << getMin(a) << endl;
	cout << extractMin(a) << endl;
	cout << is_Heap(a) << endl;
	insert(a, 0);
	cout << is_Heap(a);
}