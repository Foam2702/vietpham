#include<iostream>
#include<vector>
using namespace std;

vector<int> BubbleSort(vector<int> arr)
{
	size_t size = arr.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (size_t j = size - 1; j > i; j--)
		{
			if (arr[j] < arr[static_cast<__int64>(j) - 1])
				swap(arr[j], arr[static_cast<__int64>(j) - 1]);
		}
	}
	return arr;
}
void ExportArr(vector<int> arr)
{
	size_t size = arr.size();
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
	newarr = BubbleSort(arr);
	ExportArr(newarr);
}

