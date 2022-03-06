#include<iostream>
#include<vector>
using namespace std;

vector<int> insertionSort(vector<int> arr)
{
	int key = 0,pos = 0;
	int size = arr.size();
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > key)
		{
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = key;
	}
	return arr;
}


void ExportArr(vector<int> arr)
{
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	vector<int> arr, newarr;
	int value;
	cout << "Nhap gia tri :";
	while (cin >> value)
	{
		cout << "Nhap gia tri :";
		if (value == NULL)
		{
			break;
		}
		arr.push_back(value);
	}
	newarr = insertionSort(arr);
	ExportArr(newarr);
}
