#include<iostream>
using namespace std;

int main()
{
	int n, m, q,p,which,index;
	cin >> n >> q;
	int** arr = new int*[n];
	for (int i = 0; i < n; i++) {
		cin >> m;
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int p = 0; p < q; p++) {
		cin >> which>>index;
		cout << arr[which][index] <<endl;
	}
	for (int i = 0; i < n; i++) 
		delete[]arr[i];
	delete[]arr;

	
}