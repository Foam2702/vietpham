#include "CRand.h"

CRand::CRand() {
	srand((unsigned)time(0));
}
int CRand::next() {
	int result = rand();
	return result;
}
int CRand::next(int n) {
	int a = 0;
	cout << "Nhap n (0->n):"; cin >> n;
	int result = rand() % (a - n + 1) + a;
	return result;
}
int CRand::next(int left, int right) {
	int result = rand() % (left - right + 1) + left;
	return result;
}