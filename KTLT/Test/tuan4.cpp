#include <iostream>;
#include<iomanip>
using namespace std;

struct FRACTION {
	int tu, mau;
	bool operator<(FRACTION A)
	{
		if (this->tu * A.mau < A.tu * this->mau)
			return true;
		return false;
	};
	bool operator>(FRACTION A)
	{
		if (this->tu * A.mau > A.tu * this->mau)
			return true;
		return false;
	};
};

ostream& operator<<(ostream& os, const FRACTION& out)
{
	os << out.tu << "/" << out.mau;
	return os;
}
template<class T> void sortIncreasing(T* a, int n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j]) {
				T t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

template<class T> void sortDecreasing(T* a, int n) {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j]) {
				T t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}


template<class T> void showinfo(T* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void main() {
	int a[] = { 4,3,6,8 };
	float b[] = { 1.6F,8.6F,9.9F,2.3F };
	FRACTION c[] = { {1,2},{2,3},{3,7} };
	string s[] = { "hello","chao","bonjour" };
	cout << "Mang a: ";
	showinfo<int>(a, sizeof(a) / sizeof(int));
	cout << "Mang tang: ";
	sortIncreasing<int>(a, sizeof(a) / sizeof(int));
	showinfo<int>(a, sizeof(a) / sizeof(int));
	cout << "Mang giam: ";
	sortDecreasing<int>(a, sizeof(a) / sizeof(int));
	showinfo<int>(a, sizeof(a) / sizeof(int));
	cout << "================================" << endl;
	cout << "Mang b: ";
	showinfo<float>(b, sizeof(b) / sizeof(float));
	cout << "Mang tang: ";
	sortIncreasing<float>(b, sizeof(b) / sizeof(float));
	showinfo<float>(b, sizeof(b) / sizeof(float));
	cout << "Mang giam: ";
	sortDecreasing<float>(b, sizeof(b) / sizeof(float));
	showinfo<float>(b, sizeof(b) / sizeof(float));
	cout << "================================" << endl;
	cout << "Mang c: ";
	showinfo<FRACTION>(c, sizeof(c) / sizeof(FRACTION));
	cout << "Mang tang: ";
	sortIncreasing<FRACTION>(c, sizeof(c) / sizeof(FRACTION));
	showinfo<FRACTION>(c, sizeof(c) / sizeof(FRACTION));
	cout << "Mang giam: ";
	sortDecreasing<FRACTION>(c, sizeof(c) / sizeof(FRACTION));
	showinfo<FRACTION>(c, sizeof(c) / sizeof(FRACTION));
	cout << "================================" << endl;
	cout << "Mang d: ";
	showinfo<string>(s, sizeof(s) / sizeof(string));
	cout << "Mang tang: ";
	sortIncreasing<string>(s, sizeof(s) / sizeof(string));
	showinfo<string>(s, sizeof(s) / sizeof(string));
	cout << "Mang giam: ";
	sortDecreasing<string>(s, sizeof(s) / sizeof(string));
	showinfo<string>(s, sizeof(s) / sizeof(string));
}