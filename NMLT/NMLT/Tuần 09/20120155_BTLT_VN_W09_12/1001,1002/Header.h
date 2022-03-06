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
bool KiemTraTamGiac(TamGiac TG);
double ChuViTamGiac(TamGiac TG);
double KhoangCach2ToaDo(ToaDo a, ToaDo b);
void ReadFile(ifstream &in,TamGiac TG[],int n);
void WriteFile(ofstream &out,TamGiac TG[],int n);
int tamgiac_Chuvi_Lonnhat(TamGiac TG[],int n);

#endif