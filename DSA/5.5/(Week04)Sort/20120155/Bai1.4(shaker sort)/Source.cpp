#include<iostream>
#include<vector>
using namespace std;

vector<int> ShakerSort(vector<int>arr)
{
	int size = arr.size();
	int left = 0, right = size - 1;
	while (right > left)
	{
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
				swap(arr[i], arr[i + 1]);
		}
		right--;
		for (int j = right; j > left; j--)
		{
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
		left++;
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
	newarr = ShakerSort(arr);
	ExportArr(newarr);
}
