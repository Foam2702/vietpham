#include <iostream>
#include <memory.h>
#include<malloc.h>
#define headSize sizeof(int)
using namespace std;
struct SOPHUC
{
	float Re, Im;
};
ostream& operator<<(ostream& os, const SOPHUC& out);
istream& operator>>(istream& is, SOPHUC& in);
int memSize(int nItem);
void* origin_addr(void* aData);
SOPHUC* data_addr(void* origin);
void set_nItem(SOPHUC* aData, int nItem);
int get_nItem(SOPHUC* aData);
int floatArrSize(SOPHUC* aData);
void ArrFree(void* aData);
SOPHUC* floatArrResize(SOPHUC* aData, int nItem);
int floatArrPushback(SOPHUC** aData, SOPHUC x);
SOPHUC* ArrPopback(void** aData);
SOPHUC* soPhucArrIn();
void soPhucArrOut(SOPHUC* a);
void arrFree(SOPHUC* a);
void main()
{
	cout << "Nhap ...: " << endl;
	SOPHUC* B = soPhucArrIn();
	int a = floatArrSize(B);
	SOPHUC* x = (SOPHUC*)ArrPopback((void**)&B);
	cout << "After pop:" << endl;
	soPhucArrOut(B);
	cout << "\nPopped element: " << *x << endl;
	free(x);
	arrFree(B);
	system("pause");
}
ostream& operator<<(ostream& os, const SOPHUC& out)
{
	os << out.Re << " + " << out.Im << "i";
	return os;
}
istream& operator>>(istream& is, SOPHUC& in)
{

	cout << "Phan thuc: ";
	is >> in.Re;
	if (is.fail())
	{
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return is;
	}
	cout << "Phan ao: ";
	is >> in.Im;
	if (is.fail())
	{
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return is;
}
int memSize(int nItem) {
	return headSize + nItem * sizeof(SOPHUC);
}
void* origin_addr(void* aData) {
	return (char*)aData - headSize;
}
SOPHUC* data_addr(void* origin) {
	return (SOPHUC*)((char*)origin + headSize);
}
void set_nItem(SOPHUC* aData, int nItem) {
	*((int*)origin_addr(aData)) = nItem;
}
int get_nItem(SOPHUC* aData) {
	return *((int*)origin_addr(aData));
}
int floatArrSize(SOPHUC* aData) {
	if (aData != NULL) return get_nItem(aData);
	return 0;
}
void ArrFree(void* aData) {
	if (aData != NULL)
		free(origin_addr(aData));
}
SOPHUC* floatArrResize(SOPHUC* aData, int nItem) {
	int sz = memSize(nItem);
	SOPHUC* anew = NULL; void* originAddr = NULL;
	if (aData != NULL) originAddr = origin_addr(aData);
	int* temp = (int*)originAddr;
	anew = (SOPHUC*)realloc(originAddr, sz);
	if (anew != NULL) {
		if (aData == NULL) memset(anew, 0, sz);
		temp = (int*)anew;
		aData = data_addr(anew);
		set_nItem(aData, nItem);
	}
	return aData;
}
int floatArrPushback(SOPHUC** aData, SOPHUC x) {
	int n = floatArrSize(*aData);
	SOPHUC* anew = floatArrResize(*aData, n + 1);
	if (anew != NULL) {
		anew[n] = x;
		*aData = anew;
		return 1;
	}
	return 0;
}
SOPHUC* ArrPopback(void** aData) {
	SOPHUC** AData = (SOPHUC**)aData;
	int n = floatArrSize(*AData);
	SOPHUC x; x.Im = INT_MIN; x.Re = INT_MIN;
	if (*aData != NULL && n > 0) {
		n--; x = (*AData)[n];
		SOPHUC* anew = floatArrResize(*AData, n);
		if (anew != NULL) *AData = anew;
	}
	if (x.Im == INT_MIN && x.Re == INT_MIN)
		return NULL;
	SOPHUC* res = new SOPHUC;
	*res = x;
	return res;
}
SOPHUC* soPhucArrIn() {
	SOPHUC* a = NULL, x;
	while (true) {
		cin >> x;
		if (cin.fail() == true)
			break;
		floatArrPushback(&a, x);
	}
	cin.clear();
	return a;
}
void soPhucArrOut(SOPHUC* a)
{
	int n = *(int*)(origin_addr(a));
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "	" << endl;
	}
}
void arrFree(SOPHUC* a)
{
	delete[]a;
}






