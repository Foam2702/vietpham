#include<iostream>
#include<fstream>
using namespace std;

//23a
int Tongduongcheochinh(int** a, int n)
{	
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) sum += a[i][j];
		}
	}
	return sum;
}

int Tongduongcheophu(int** a, int n)
{
	int sum = 0;
	int i = 0, j = n-1;
	while (i<n)
	{
		sum += a[i][j];
		i++; j--;

	}
	return sum;
}
//cau b
int Tongphantuthuoctamgiactren(int** a, int n)
{	
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j) {
				sum += a[i][j];
			}
		}
	}
	return sum;
}
int Tongphantuthuoctamgiacduoi(int** a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i > j) {
				sum += a[i][j];
			}
		}
	}
	return sum;
}
int main()
{
	ifstream in;
	in.open("SQUARE.INP.txt", ios_base::in);
	if (!in.is_open())
	{
		cout << "ERROR";
	}
	int n;
	in >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> a[i][j];
		}
	}
	in.close();

	ofstream out;
	out.open("SQUARE.OUT.txt", ios_base::out);
	//cau a
	int sum1 = 0, sum2 = 0;
	sum1 = Tongduongcheochinh(a, n);
	sum2 = Tongduongcheophu(a, n);
	out << "Cau a:" << sum1 << " " << sum2<<endl;
	//cau b
	int value1 = 0, value2 = 0;
	value1 = Tongphantuthuoctamgiactren(a, n);
	value2 = Tongphantuthuoctamgiacduoi(a, n);
	out << "Cau b:" << value1 << " " << value2;
	out.close();


	for (int i = 0; i < n; i++)
	{
		delete[]a[i];
	}
	delete[]a;

}