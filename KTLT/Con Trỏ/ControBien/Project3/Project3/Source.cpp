#include<iostream>
using namespace std;
int main()
{
	int var = 10;
	int* ptr1 = &var;
	*ptr1 = 20;
	int** ptr2 = &ptr1;
	**ptr2 = 30;
	int*** ptr3 = &ptr2;
	***ptr3 = 40;
	cout << var;
}