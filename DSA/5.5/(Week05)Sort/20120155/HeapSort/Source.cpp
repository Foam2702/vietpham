#include<iostream>
#include<vector>
using namespace std;

void sift(vector<int>&arr, int left, int right)// xây dựng heap
{	
	int i = left;
	int j = i * 2 + 1;
	int x = arr[i];
	while (j <= right)
	{
		if (j < right)
		{
			if (arr[j] <= arr[j + 1])
				j++;
		}
		if (x >= arr[j]) break;
		else
		{
			arr[i] = arr[j];
		}
		i = j;
		j = i * 2 + 1;
	}
	arr[i] = x;
	
}

void Heapivfy(vector<int>&arr,int n)// đưa phần tử vào heap
{
	int left = (n / 2) - 2;
	while (left >= 0)
	{
		sift(arr, left, n);
		left--;
	}
}

vector<int> HeapSort(vector<int>& arr, int n)//sắp xếp tăng dần
{	
	Heapivfy(arr, arr.size());
	for (int j = n - 1; j >= 0; j--)
	{
		swap(arr[0], arr[j]);
		
		sift(arr, 0, j - 1);
	}
	return arr;

}

int main()
{	
	
	vector<int>arr,newarr;
	int value;
	cout << "Nhap gia tri (Ctrl+W de dung nhap):";
	while (cin >> value)
	{	
		
		if (value == NULL)
		{
			break;
		}
		arr.push_back(value);
		cout << "Nhap gia tri (Ctrl+W de dung nhap):";
		
	}
	
	newarr=HeapSort(arr,arr.size());
	for (int i = 0; i < newarr.size(); i++)
	{
		cout << newarr[i] << " ";
	}
}