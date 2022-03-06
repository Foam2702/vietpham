#include<iostream>
#include<vector>
using namespace std;


void Chen0truocSochan(int* &arr, int n)
{	
	int count = 0;
	vector<int> vitri;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			count++;
			vitri.push_back(i);
			
		}
	}
	int countnewarr = n + count;
	int* newarr = new int[countnewarr];
	int j = 0, i = 0;
	bool linhcanh = true;
	for (i = 0; i < n ; i++)
	{
		linhcanh = true;
		for (int k = 0; k < vitri.size(); k++)
		{	
			
			if (i == vitri[k])
			{
				newarr[j] = 0;
				newarr[j + 1] = arr[i];
				j += 2;
				linhcanh = false;

			}
			
		}
		if (linhcanh == true)
		{
			newarr[j] = arr[i];
			j++;
		}
		
		
	}
	for (int i = 0; i < countnewarr; i++)
	{
		cout << newarr[i] << " ";
	}
	

	delete[]newarr;
	delete[]arr;
	
}
int main()
{
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	Chen0truocSochan(arr, n);
	
	return 0;

}