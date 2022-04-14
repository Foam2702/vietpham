#include<iostream>
using namespace std;

#define MAX_SIZE 1000
#define STOP -1
int* initialize(int maxSize)
{
	int* arr = new int[maxSize];
	return arr;
}

int* growSize(int* arr, int size, int& maxSize)
{
	int newsize = maxSize * 2;
	int* newarr = new int[newsize];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	if (arr != nullptr)
		delete arr;
	return newarr;
}
void addElement(int*& arr, int data, int& size, int& maxSize)
{
	if (size + 1 > maxSize)
	{
		arr = growSize(arr, size, maxSize);
	}
	size = size + 1;
	arr[size - 1] = data;

}
void addElementAtIndex(int*& arr, int index,int data, int& size, int& maxSize)
{
	if (index > size)
		return;
	else
	{
		addElement(arr, data, size, maxSize);
		for (int i = size - 1; i > index; i--)
		{
			swap(arr[i], arr[i - 1]);
		}
	}
}
void removeElement(int* arr, int& size, int maxSize)
{
	arr[size - 1] = NULL;
	size = size - 1;
}
void removeElementatIndex(int* arr,int index, int& size, int maxSize)
{
	if (index > size)
		return;
	for (int i = index; i < size; i++)
	{
		arr[i] = arr[i + 1];
	}
	removeElement(arr, size, maxSize);
}
int* shrinkArr(int* arr, int size, int maxSize)
{
	int* newarr = new int[size];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	if (arr != nullptr)
		delete arr;
	return newarr;
}
int maxElement(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
int searchElement(int* arr, int key, int size)
{
	int value = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			value = arr[i];
			return i;
			break;
		}
	}
	return 0;

}
void Sort_Increasing(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}
int* merge2Arr(int* a, int* b, int na, int nb)
{
	int nc = na + nb;
	int count = na;
	int* c = initialize(nc);

	for (int i = 0; i < na; i++)
	{
		c[i] = a[i];
	}
	for (int i = 0; i < nb; i++)
	{
		c[count] = b[i];
		count++;
	}

	return c;

}
void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i]<<" ";
	}
}
int main()
{
	int size = 0, maxSize = MAX_SIZE,data ,index;
	int* arr = initialize(maxSize);

	//cau a,b
	cout << "Nhan ctrl+W de thoat chuong trinh" << endl<<endl;
	cout << "Nhap element:";
	while (cin >> data)
	{

		cout << "Nhap element:";
		addElement(arr, data, size, maxSize);
	}
	PrintArr(arr, size); cout << endl;
	cin.clear();
	cin.ignore();

	//cau c
	cout << "Nhap vi tri muon them:";
	cin >> index;
	cout << "Nhap Element:";
	cin >> data;
	addElementAtIndex(arr, index, data, size, maxSize);
	PrintArr(arr, size); cout << endl;

	//cau d
	removeElement(arr, size, maxSize);
	PrintArr(arr, size); cout << endl;

	//cau e
	cout << "Nhap vi tri muon xoa:";
	cin >> index;
	removeElementatIndex(arr, index, size, maxSize);
	PrintArr(arr, size);cout<<endl;

	//cau f
	int* subarr = shrinkArr(arr, size, maxSize);
	PrintArr(subarr, size); cout << endl;

	//cau h
	int max = maxElement(subarr, size);
	cout << max<<endl;

	//cau k
	int k = 0;
	cout << "Nhap key:"; cin >> k;
	int local = searchElement(subarr,k, size);
	cout <<"Tai vi tri:"<< local << endl;

	//cau l
	int sizea = 0, sizeb = 0;
	int* a = initialize(sizea);
	int* b = initialize(sizeb);
	cout << "Nhap cho a:";
	while (cin >> data)
	{
		if (data == STOP) break;
		cout << "Nhap cho a:";
		addElement(a, data, sizea, maxSize);

	}
	PrintArr(a, sizea); cout << endl;
	cout << "Nhap cho b:";
	while (cin >> data)
	{
		if (data == STOP) break;
		cout << "Nhap cho b:";
		addElement(b, data, sizeb, maxSize);

	}
	PrintArr(b, sizeb); cout << endl;

	int* c = merge2Arr(a, b, sizea, sizeb);
	int sizec = sizea + sizeb;
	Sort_Increasing(c, sizec);
	PrintArr(c, sizec);

	return 0;
}

