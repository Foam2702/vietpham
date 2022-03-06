#include<iostream>
using namespace std;

int** CreateMatrix(int& N)
{
	int**A = new int*[N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[N];
	}
	return A;
}
void InputMatrix(int** &A, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
}
void OutputMatrix(int** A, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << A[i][j]<<" ";
		}
		cout << endl;
	}
}
void DeleteMatrix(int** A, int N)
{
	for (int i = 0; i < N; i++)
	{
		delete[]A[i];
	}
	delete[]A;
}
int** tichmaTran(int** A, int** B, int N)
{	
	int** C = CreateMatrix(N);
	for (int i = 0; i < N; i++)
	{	
		for (int j = 0; j < N; j++)
		{
			int temp = 0;
			for (int l = 0; l < N; l++)
			{	
				
				temp+= A[i][l] * B[l][j];
				C[i][j] = temp;
				
			}
			
		}
		
	}
	return C;
}

int main()
{	
	int N;
	cin >> N;
	int** A = CreateMatrix(N);
	
	int** B = CreateMatrix(N);
	

	InputMatrix(A, N);
	InputMatrix(B, N);

	
	int** C = tichmaTran(A, B, N);

	
	OutputMatrix(A, N);
	cout << endl;
	OutputMatrix(B, N);
	cout << endl;
	OutputMatrix(C, N);
	

	DeleteMatrix(A, N);
	DeleteMatrix(B, N);
	DeleteMatrix(C, N);


}