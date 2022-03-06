#include<iostream>
#include<iomanip>
using namespace std;

int TinhTong(int n)
{
	static int sum = 0;
	static int i = 1;
	if (i <= n) {
		sum += i;
		i++;
		return TinhTong(n);
	}
	return sum;
}

int main()
{
	unsigned short a = 60234;
	unsigned char* p = (unsigned char*)& a;
	cout << p << endl;
	cout << (short)(*p) << endl;
	cout << short(*(p + 1)) << endl;
	cout<<setprecision
}