#include<iostream>
#include<vector>
using namespace std;

int FindBestCouple_On2(vector<int> money, vector<int> bubble) {
	int count = 0;
	for (int i = 0; i < money.size() - 1; i++) {
		for (int j = i + 1; j < bubble.size(); j++) {
			if (money[i] + money[j] > bubble[i] + bubble[j]) {
				count++;
			}
		}
	}
	return count;
}
void sift(vector<int>& arr, int left, int right)// xây dựng heap
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

void Heapivfy(vector<int>& arr, int n)// đưa phần tử vào heap
{
	int left = (n / 2) - 2 ;
	while (left >= 0)
	{
		sift(arr, left, n);
		left--;
	}
}

vector<int> HeapSort(vector<int>& arr, int n)//sắp xếp tăng dần
{	
	vector<int> result;
	Heapivfy(arr, arr.size());

	for (int j = n - 1; j >= 0; j--)
	{	
		swap(arr[0], arr[j]);
		sift(arr, 0, j - 1);
	}
	return result;

}
int BinarySearch(vector<int>arr, int left, int right, int x)
{

	if (right < left)
		return -1;

	int mid = (left + right) / 2;

	if ((x + arr[mid]) > 0 && (x + arr[mid - 1] <= 0))
	{
		return mid;
	}

	else if (arr[mid] + x > 0)
	{
		return BinarySearch(arr, left, mid - 1, x);
	}
	else return BinarySearch(arr, mid + 1, right, x);


}

int FindBestCouple_Onlogn(vector<int>money, vector<int>bubble, int n)
{	
	int count = 0;
	vector<int> compare;
	for (int i = 0; i < n; i++)
	{
		compare.push_back(money[i] - bubble[i]);

	}
	HeapSort(compare,n);
	for (int i = 0; i < n; i++)
	{
		if (compare[i] > 0) {
			int m = n - 1 - i;
			count = count + (m * (m + 1)) / 2;
			break;
		}
		else {
			int location = BinarySearch(compare, i + 1, compare.size() - 1, compare[i] );
			if (location != -1) {
				count =count + n - location;
			}
		}
	}
	return count;
	
}

int main()
{	
	vector<int>money, bubble;
	int n,value;
	do
	{
		cin >> n;
		if (n < 2 || n > 2 * 100000)
		{
			cout << "n phai thuoc doan[2;2*100000]" << endl;
		}
	}while (n < 2 || n > 2 * 100000);


	for (int i = 0; i < n; i++)
	{	
		do
		{
			cin >> value;
			if (value < 1 || value>1000000)
			{
				cout << "n phai thuoc doan[1;1000000]" << endl;
			}
		} while (value < 1 || value>1000000);
		money.push_back(value);
	}
	for (int i = 0; i < n; i++)
	{
		do
		{
			cin >> value;
			if (value < 1 || value>1000000)
			{
				cout << "n phai thuoc doan[1;1000000]" << endl;
			}
		} while (value < 1 || value>1000000);
		bubble.push_back(value);
	}
	cout<<FindBestCouple_Onlogn(money, bubble, n);
}
