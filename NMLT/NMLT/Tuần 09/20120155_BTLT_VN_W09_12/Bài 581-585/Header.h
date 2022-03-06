#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
#include<fstream>
using namespace std;

struct ToaDo {
	double x = 0;
	double y = 0;
};


struct TamGiac {
	ToaDo A;
	ToaDo B;
	ToaDo C;
};


double KhoangCach2ToaDo(ToaDo a, ToaDo b);
bool KiemTraTamGiac(TamGiac TG);
double ChuViTamGiac(TamGiac TG);
void ReadFile(ifstream& in, TamGiac& TG);
void WriteFile(ofstream& out, TamGiac TG);



#endif 
