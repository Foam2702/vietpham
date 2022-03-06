#include"Header.h"

void Input(hs a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten hoc sinh " << i + 1 << " :";
		cin.ignore();
		cin.getline(a[i].hoten, 1000);
		cin.clear();
		cout << "Diem: ";
		cin >> a[i].diem;
	}
}

void Output(hs a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].hoten << endl;
		cout << a[i].diem << endl;
	}
}

void Output1(hs a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i].hoten << endl;
	}
}

void strcpy(char A[], char B[])
{
	int n = 0;
	do
	{
		A[n] = B[n];
		n++;
	} while (B[n] != '\0');
}

void Tach(char hoten[], char ten[])
{
	for (int i = strlen(hoten) - 1; i >= 0; i--) {
		if (hoten[i] == ' ') {
			strcpy(ten, hoten + 1 + i);
			break;
		}
	}
}

int strcmp(char a[], char b[])
{
	int n = 0;
	do
	{
		if (a[n] > b[n])
			return 1;
		else if (a[n] < b[n])
			return -1;
		n++;
	} while (a[n] != '\0' || b[n] != '\0');

	return 0;
}

void Sapxep(hs a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			char ten1[255] = "", ten2[255] = "";
			Tach(a[i].hoten, ten1);
			Tach(a[j].hoten, ten2);
			int check1 = strcmp(ten1, ten2);
			if (check1 > 0)
				swap(a[i], a[j]);

			else if (check1 == 0) {
				int check2 = strcmp(a[i].hoten, a[j].hoten);
				if (check2 > 0)
					swap(a[i], a[j]);

			}
		}
	}
}

void locTen(hs a[], int n)
{
	int count = 0;
	Ten b[50];
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			char ten1[255] = "", ten2[255] = "";
			Tach(a[i].hoten, ten1);
			Tach(a[j].hoten, ten2);
			int check1 = strcmp(ten1, ten2);
			if (check1 != 0)		
				count++;		
		}
	}
	cout << "Co " << count << "ten khac nhau" << endl;
}

void FindMax(hs a[], int n)
{
	float max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
	for (int i = 0; i < n; i++)
		if (max1 < a[i].diem)
			max1 = a[i].diem;
	for (int i = 0; i < n; i++)
		if (max2 < a[i].diem && a[i].diem < max1)
			max2 = a[i].diem;
	for(int i = 0; i < n; i++)
		if (max3 < a[i].diem && a[i].diem < max2)
			max3 = a[i].diem;
	for (int i = 0; i < n; i++)
		if (a[i].diem == max1)
			cout << a[i].hoten << endl;
	for (int i = 0; i < n; i++)
		if (a[i].diem == max2)
			cout << a[i].hoten << endl;
	for (int i = 0; i < n; i++)
		if (a[i].diem == max3)
			cout << a[i].hoten << endl;
	
}