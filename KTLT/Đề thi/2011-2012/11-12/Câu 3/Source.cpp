#include<iostream>
#include<vector>
using namespace std;

void Input(vector<int>&arr,int x)
{	

	while (cin >> x)
	{
		if (x == '.') break;
		else
			arr.push_back(x);
	}
}

int KhoangcachMax_Traidau(vector<int>&arr)
{
	vector<int> soduong;
	vector<int> soam;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] < 0)
			soam.push_back(arr[i]);
		else if (arr[i] > 0)
			soduong.push_back(arr[i]);
	}
	int max = abs(soduong[0] - soam[0]);
	int sizesoam = soam.size();
	int sizesoduong = soduong.size();
	for (int i = 0; i < sizesoduong; i++)
	{
		for (int j = 0; j < sizesoam; j++)
		{
			if (abs(soduong[i] - soam[j]) > max)
				max = abs(soduong[i] - soam[j]);
		}
	}

	return max;

}

int main()
{
	vector<int>arr;
	int x=0;
	Input(arr, x);
	
	int max = KhoangcachMax_Traidau(arr);
	cout << max;
}