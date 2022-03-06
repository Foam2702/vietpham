#include<iostream>
#include<vector>
using namespace std;

vector<int> ShellSort(vector<int>arr)
{
	int n = arr.size();
	int interval = 0;
	for (interval = n / 2; interval >= 1; interval /= 2)
	{
		for (int j = interval; j < n; j++)
		{
			for (int i = j - interval; i >= 0; i -= interval)
			{
				if (arr[i] > arr[i + interval])
				{
					swap(arr[i], arr[i + interval]);
				}
				else break;
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
	newarr = ShellSort(arr);
	ExportArr(newarr);
}