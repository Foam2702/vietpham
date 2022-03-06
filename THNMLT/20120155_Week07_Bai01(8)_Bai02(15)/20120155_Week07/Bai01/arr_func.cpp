#include"array.h"

int FindMax(int arr[], int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
int Tong_soKhongam(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0)
		{
			sum += arr[i];
		}
	}
	return sum;
}
int Tong_viTrichan(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			sum += arr[i];
		}
	}
	return sum;
}
bool check_Prime(int x)
{
	if (x < 2)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
				return false;
		}
	}
	return true;
}
int Count_Prime(int arr[], int n)
{	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (check_Prime(arr[i]))
			count++;
	}
	return count;

}
int Tim_phantuAmLonNhat(int arr[], int n)
{	
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			max = arr[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			if (arr[i] > max)
				max = arr[i];
		}
	}
	return max;
}
int Tim_phantuKhongAmNhonhat(int arr[], int n)
{
	int min=-1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
			min = arr[i];
	}
	for(int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
	}
	return min;
}
bool Check_Increasing(int arr[], int n)
{
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[j] > arr[i] && arr[j + 1] > arr[j])
			
			{
				return true;
			}
			else
			{
				return false;
				break;
			}
		}
	}
	return true;
}
bool Check_soChinhphuong(int x)
{
	int sqr = sqrt(x);
	if (sqr* sqr == x)
		return true;
	return false;
}
int Tong_soChinhphuong(int arr[], int n)
{	
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (Check_soChinhphuong(arr[i]))
		{
			sum+=arr[i];
		}
	}
	return sum;
}