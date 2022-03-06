//#include<iostream>
//#include<vector>
//using namespace std;
//
//int migratoryBirds(vector<int> arr) {
//	int n;
//	cin >> n;
//	int value;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> value;
//		arr.push_back(value);
//	}
//	int count = 0;
//	vector<int>arrcount;
//	vector<int>arrbird;
//	for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = 0; j < arr.size(); j++)
//		{
//			if (arr[j] == arr[i])
//				count++;
//		}
//		arrcount.push_back(count);
//		count = 0;
//		
//	}
//	int countmax = arrcount[0];
//	for (int i = 0; i < arrcount.size(); i++)
//	{
//		if (arrcount[i] > countmax)
//		{
//			countmax = arrcount[i];
//
//		}
//	}
//	
//	for (int i = 0; i < arr.size(); i++)
//	{
//		for (int j = 0; j < arr.size(); j++)
//		{
//			if (arr[j] == arr[i])
//				count++;
//		}
//		if (count == countmax)
//		{
//			arrbird.push_back(arr[i]);
//		}
//		count = 0;
//	}
//	int min = arrbird[0];
//	for (int i = 0; i < arrbird.size(); i++)
//	{
//		if (arrbird[i] < min)
//		{
//			min = arrbird[i];
//		}
//		
//	}
//	return min;
//
//}
//int main()
//{
//	vector<int> arr;
//	int count = migratoryBirds(arr);
//	cout << count;
//}

#include<iostream>
using namespace std;

int migratoryBirds(int arr_count, int* arr) {
    int one = 0, two = 0, three = 0, four = 0, five = 0;
    for (int i = 0; i < arr_count; i++)
    {
        switch (arr[i])
        {
        case 1:one++;
            break;
        case 2:two++;
            break;
        case 3:three++;
            break;
        case 4:four++;
            break;
        case 5:five++;
            break;
        default:five++;
        }
    }
    int bird[5] = { one,two,three,four,five };
    int max = 0, ans = 0;
    for (int i = 0; i < 5; i++) {
        if (bird[i] > max) {
            max = bird[i];
            ans = i + 1;
        }
    }
    return ans;
}

int main()
{
    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
	int count = migratoryBirds(n,arr);
	cout << count;
}