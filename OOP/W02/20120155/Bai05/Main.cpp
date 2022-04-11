#include"CRand.h"

int main() {
	CRand random;
	int number, n, a, b;
	
	cout << "Phat sinh so nguyen tu 0 -> n .Nhap n:"; cin >> n;
	cout << "Nhap so luong so nguyen can phat sinh:"; cin >> number; 
	for (int i = 0; i < number; i++) {
		cout << random.next(n);
	}
	cout << "Phat sinh so nguyen tu a->b." << endl;
	cout << "Nhap a:"; cin >> a;
	cout << "Nhap b:"; cin >> b;
	cout << "Nhap so luong so nguyen can phat sinh:"; cin >> number;
	for (int i = 0; i < number; i++) {
		cout << random.next(a, b);
	}
	cout << "Phat sinh so nguyen tu 0->1." << endl;
	cout << "Nhap so luong so nguyen can phat sinh:"; cin >> number;
	for (int i = 0; i < number; i++) {
		cout<<static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}

}