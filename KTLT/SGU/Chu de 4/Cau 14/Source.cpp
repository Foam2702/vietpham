#include<iostream>
#include<fstream>
using namespace std;


void InputArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{	
		cout << "[" << i << "]:";
		cin >> arr[i];
	}
}
void OutputArr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
double Average(int *arr, int n)// tinh trung binh cong(bài 14)
{	
	int count = 0, sum = 0;
	double average=0;
	
	for (int i = 0; i < n; i++)
	{
		count++;
		sum += arr[i];
	}
	average = (double)sum / count;
	return average;

}
bool checkPrime(int x)//kiem tra so nguyen to(bài 15)
{
	if (x < 2) return false;
	else
	{
		for (int i = 2; i <= x / 2; i++)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
	}
	
	return true;
}
int countPrime(int *a, int n)//dem so nguyen to (bài 15)
{	
	int prime = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkPrime(a[i]) == true)
		{
			prime++;
			
		}
	}
	return prime;
}
bool checkSquare(int x)//kiểm tra số chính phương
{
	if (sqrt(x) * sqrt(x) == x) return true;
	return false;
}
int countSquare(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkSquare(a[i]) == true)
			count++;
	}
	return count;
}
bool checkPerfect(int x)//kiem tra so hoan chinh(bài 15)
{	
	int sum = 0;
	for (int i = 1; i <= x / 2; i++)
	{
		if (x % i == 0) sum += i;
	}
	if (sum == x) return true;
	return false;
}
int countPerfectNum(int* a, int n)//dem so luong so hoan chinh(bài 15)
{	
	int count=0;
	for (int i = 0; i < n; i++)
	{
		if (checkPerfect(a[i]) == true)
			count++;
	}
	return count;
}

int countSumEqualto_m(int* a, int n,int m)//đếm có bao nhiêu cặp bằng m (bài 16)
{
	
	
	int count = 0;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == m)
			{
				count++;
			}
		}
	}
	return count;
}

int FindSubArr_MaxEle(int* a, int n)//bài 17
{
	int length = 1,max=0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1])
		{
			length++;
			if(length>max)
				max = length;
		}
		else 
		{
			length = 1;
		}
	}
	return max;
}
void Sort_Increasing(int* a, int n)//bai 18
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	
}


int main()
{
	
	ifstream in;
	in.open("NUM.INP.txt", ios_base::in);
	if (!in.is_open()) {
		cout << "ERROR";
	}
	int n, m;
	in >> n >> m;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		in >> a[i];
	}
	
	in.close();

	ofstream out;
	out.open("NUM.OUT.txt", ios_base::out);

	double average = Average(a, n);
	out << "Bai 14:" << average << endl;

	int prime = countPrime(a, n);
	int square = countSquare(a, n);
	int perfect = countPerfectNum(a, n);
	out << "Bai 15:" << prime << " " << square << " " << perfect << endl;

	int countsum = countSumEqualto_m(a, n,m);
	out << "Bai 16:" << countsum << endl;

	int countsubarrmax = FindSubArr_MaxEle(a, n);
	out << "Bai 17:" << countsubarrmax << endl;

	Sort_Increasing(a, n);
	out << "Bai 18:";
	for (int i = 0; i < n; i++)
	{
		out << a[i] << " ";
	}
	delete[]a;
	
	out.close();
	
}