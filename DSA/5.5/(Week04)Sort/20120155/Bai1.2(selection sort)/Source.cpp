#include<iostream>
#include<vector>
using namespace std;

vector<int> SelectionSort(vector<int>arr)
{	
	int size = arr.size();
	int min;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				swap(arr[min], arr[j]);
				min = j;
			}
		}
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
	newarr = SelectionSort(arr);
	ExportArr(newarr);
}