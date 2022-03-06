#include<iostream>
#include<vector>
using namespace std;

vector<int> interchangesort(vector<int>&arr)
{	
	int size = arr.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
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
	vector<int> arr ,newarr;
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
	newarr = interchangesort(arr);
	ExportArr(newarr);
}
