#pragma once
#pragma once
#ifndef _HEADER_
#define _HEADER_

#include<iostream>
using namespace std;

struct Tinh {
	short matinh;
	char tentinh[30];
	int danso;
	double dientich;
};


void Input_Tinh(Tinh mang_tinh[], int& n);
void Output_Tinh(Tinh tinh);
void Output_Tinhdanso(Tinh mang_tinh[], int n);
void Dientich_Lonnhat(Tinh mang_tinh[], int n);
void Sapxep_Dientich_Giamdan(Tinh a[], int n);
#endif
