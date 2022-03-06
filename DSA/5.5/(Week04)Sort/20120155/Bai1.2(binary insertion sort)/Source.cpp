#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int>arr,int left,int right,int x)
{	
	
	if (right <= left)
		return(x > arr[left]) ? (left + 1) : left;

	int mid = (left + right) / 2;

	if (arr[mid] == x)
		return mid + 1 ;

	else if (arr[mid] > x)
	{
		return BinarySearch(arr, left, mid - 1, x);
	}
	else return BinarySearch(arr, mid + 1, right, x);
	
	
}

vector<int> BinaryInsertionSort(vector<int>arr)
{
	int key = 0, pos = 0, newpos = 0;
	int size = arr.size();
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		pos = i - 1;
		newpos = BinarySearch(arr, 0, pos, key);
		while (pos >= newpos)
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
	newarr = BinaryInsertionSort(arr);
	ExportArr(newarr);
}