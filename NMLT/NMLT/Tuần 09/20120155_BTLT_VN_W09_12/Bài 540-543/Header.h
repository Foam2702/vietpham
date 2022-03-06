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



void ReadFile(ifstream& in, ToaDo& a, ToaDo& b);
void WriteFile(ofstream& out, ToaDo a, ToaDo b);
double KhoangCach2ToaDo(ToaDo a, ToaDo b);

#endif 
