#include<iostream>
using namespace std;
#pragma GCC diagnostic ignored"_Wpedantic"
typedef union {
	double Value; unsigned long dWord[2]; unsigned short Words[4]; unsigned char Bytes[8];
	struct {
		unsigned long long Mantissa : 52; unsigned int Expo : 11; unsigned int Sign : 1;
	};
}
doubleStruct;

void doubleDump(doubleStruct* fs) {
	if (fs == NULL) return;
	cout << "--------------------" << endl;
	cout << "+value: " <<hex<< fs->Value << endl;
	cout << "+stored dword: " <<hex<< fs->dWord[0]<< " " << fs->dWord[1] << endl;
	cout << "+stored words: " <<hex<< fs->Words[0] << " " << fs->Words[1] << " " << fs->Words[2] << " " << fs->Words[3] << endl;
	cout << "stored bytes: ";
	for (int i = 0; i < sizeof(double); i++)
		cout << hex <<(int)fs->Bytes[i] << " ";
	cout << endl;
	cout << " +IEEE stored parts:" << endl;
	cout << " Sign: " <<hex<< fs->Sign << endl;
	int i = 9;
	printf("asd %x %d", i,i);
	cout << " Expo: " <<hex<< fs->Expo << endl;;
	cout << " Mantissa:" <<hex<< fs->Mantissa << endl;
	cout << sizeof(unsigned long);
	
}
void main() {
	double x = 1/(double)3;
	//unsigned char bytes[] = { 0x89,0x01,0x46,0xC1 };
	doubleStruct* p = (doubleStruct*)&x;
	//doubleDump(p); p = (doubleStruct*)bytes;
	doubleDump(p);
}