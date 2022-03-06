#include<iostream>
#include<vector>
using namespace std;

bool Kiemtra_Sohoanchinh(int n)
{	
	vector<int> arr;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			arr.push_back(i);
		}
	}
	int size = arr.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	if (sum == n) return true;
	return false;
}

int main()
{
	int n; cin >> n;
	Kiemtra_Sohoanchinh(n);
	if (Kiemtra_Sohoanchinh(n) == true)
	
		cout << n << " la so hoan chinh";
	
	else
		cout << n << " khong la so hoan chinh";
}