#include  <iostream>
using namespace std;


void allCombination(int* Array, int size)
{
	cout << "To hop cac phan tu trong mang" << endl;
	for (int i = 0; i < pow(2, size); i++) // số tổ hợp = 2^size
	{
		cout << i + 1 << "/ {";
		for (int j = 0; j < size; j++)
		{
			if (1 == ((i >> j) & 1)) // lấy bit thứ j trong i
				cout << Array[j];
			if (j != size - 1)
				cout << ",";
		}
		cout << "}" << endl;
	}
}





int main()
{
	//int A[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	//allCombination(A, 12);
	int A[] = { 1,2,3 };
	allCombination(A, 3);


	system("pause");
	return 0;
}
