#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


//bai 20
int findMin(int** a, int m, int n)
{	
	
	vector<int> arrofmin;
	for (int i = 0; i < m; i++)
	{
		int min = a[0][0];
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] < min) min = a[i][j];
		}
		arrofmin.push_back(min);

	}
	int max = arrofmin[0];;
	for (int i = 0; i < arrofmin.size(); i++)
	{
		if (arrofmin[i] > max) max = arrofmin[i];
	}
	return max;
}
//bai 21
void Sort_Increasing(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n-1; j++)
		{

			for (int k = j + 1; k < n; k++)
			{
				if (a[i][j] > a[i][k])
					swap(a[i][j], a[i][k]);
			}
		}
	}

	
}
//bai 22
int Replace(int value)
{	
	int sum = 0;
	for (int i = value; i != 0; i /= 10)
	{
		sum += i % 10;
	}
	return sum;
}
int Sum_Matrix(int** a, int m, int n)
{	
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum += Replace(a[i][j]);
		}
	}
	return sum;
}

int main()
{
	ifstream in;
	in.open("TABLE.INP.txt", ios_base::in);
	if (!in.is_open()) {
		cout << "ERROR";
	}
	int m, n;
	in >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> a[i][j];
		}

	}
	
	in.close();

	ofstream out;
	out.open("TABLE.OUT.txt", ios_base::out);
	//Bai 19
	int sumdong = 0, sumcot = 0;
	out << "Bai 19:";
	for (int i = 0; i < m; i++)
	{	
		sumdong = 0;
		for (int j = 0; j < n; j++)
		{
			sumdong += a[i][j];
		}
		out << sumdong << " "; 
	}
	out << endl;
		
	for (int i = 0; i < n; i++)
	{
		sumcot = 0;
		for (int j = 0; j < m; j++)
		{
			sumcot += a[j][i];
		}
		out << sumcot << " ";
	}
	out << endl;
	//bai 20
	int value = findMin(a, m, n);
	out <<"Bai 20:"<< value << endl;
	//bai 21
	Sort_Increasing(a, m, n);
	out << "Bai 21:"<<endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << a[i][j] << " ";
		}
		out << endl;
	}
	
	//bai 22
	int data = Sum_Matrix(a, m, n);
	out << "Bai 22:" << data;
	
	
	out.close();

	

	for (int i = 0; i < m; i++)
	{
		delete[]a[i];
	}
	delete[]a;
}
